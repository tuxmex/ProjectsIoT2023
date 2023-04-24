// Autores
// Oscar Adahir Rojas Sánchez
// Miguel Ángel Hernández Solís
// Erik Daniel Méndez Enríquez

// Bibliotecas utilizadas
#include <WiFi.h>
#include <PubSubClient.h>
#include <HTTPClient.h>
#include <UrlEncode.h>
#include "Adafruit_TCS34725.h"
#include "ColorConverterLib.h"
#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Pines
int pinBtn = 2;
int pinLedRojo = 4;
int pinLedVerde = 15;
int PinBuzzer = 5;
int pinMotor = 18;
int pinEco = 23;
int pinGatillo = 22;
int pinSonido = 35;
int pinColorSDA = 33;
int pinColorSCL = 32;
int pinRX = 21;
int pinTX = 19;

// Variables de ayuda
float sinVal;
int toneVal;
bool stateAlarm;
bool sonidoVal;
int distancia;
long tiempoEnvio, tiempoActual;

// Datos del Broker
const char* mqtt_server = "192.168.137.134";
IPAddress server(192,168,137,134);

// Objetos de comunicación para enviar al broker
WiFiClient espClient;
PubSubClient client(espClient);

// GPS
TinyGPS gps;
SoftwareSerial softSerial(pinTX, pinRX);

// Sensor de color
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

// Red
const char* ssid = "Conectate a Dios";
const char* password = "VergaDePuerco123";

// API de WhatsApp
String phoneNumber = "+5214181121719";
String apiKey = "8098112";

void setup(){
  //Iniciar comunicación serial
  Serial.begin(115200);
  softSerial.begin(9600);
  
  // Definiendo pines de entrada y salida
  pinMode(pinBtn, INPUT);
  pinMode(pinSonido, INPUT);
  pinMode(pinMotor, OUTPUT);
  pinMode(PinBuzzer, OUTPUT);
  pinMode(pinLedRojo, OUTPUT);  
  pinMode(pinLedVerde, OUTPUT);

  // Conexión a la red
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // Conección al broker
  client.setServer(server, 1883);
  client.setCallback(callback);
  delay(1500);

  // Buzzer
  ledcSetup(0, 8000, 8);
  ledcAttachPin(PinBuzzer, 0);

  // Sensor de color    
  Wire.begin(pinColorSDA, pinColorSCL);
  if(tcs.begin()){
    Serial.println("Inicializando");
    delay(2000);
  }
  else{
    Serial.println("Error");
    Serial.println("Debe de revisar las conexiones e iniciar nuevamente");
    while(1)delay(500);
  }
}

void loop(){
  // Encender el LED Verde
  digitalWrite(pinLedVerde,  HIGH);
  digitalWrite(pinLedRojo,  LOW);  
  
  // Obtención de datos GPS
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;  

  // Intentar recibir secuencia durante un segundo
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (softSerial.available())
    {
      char c = softSerial.read();
      if (gps.encode(c)) // Nueva secuencia recibida
        newData = true;
    }
  }

  // Botón
  int valBtn = digitalRead(pinBtn);
  if (valBtn == 0) {//Cambiar a 0    
    // Encender LED Rojo
    digitalWrite(pinLedRojo, HIGH);
    digitalWrite(pinLedVerde,  LOW); 
    delay(1500);
    // Hacer chillar el buzzer
    for (int i = 0; i < 5; i++) {
      digitalWrite(pinMotor, 255);
      for (int x = 0; x < 180; x++) {
        sinVal = (sin(x * (3.1412 / 180)));
        toneVal = 2000 + (int(sinVal * 1000));
        ledcWriteTone(0, toneVal);
        delay(10);
      }
      ledcWriteTone(0, 0);
    }
    // Guarda valores en base de datos
    publishData(client, 4, valBtn);
    
    // Apagar actuadores       
    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde,  HIGH);
    digitalWrite(pinMotor, 0);
    
    // Envíar ubicación por GPS  
    if (newData){
      float flat, flon;
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age);
      flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6;
      flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6;
            
      // Envía el mensaje de WhatsApp
      sendMessage("Ayuda!!!");
      sendMessage("Me encuentro en la siguiente ubicación: https://www.google.com.mx/maps/@"+ String(flat,6) + "," + String(flon,6) + ",12z");  
      delay(3000);
    }   
  }

  // Sensor de sonido;
  sonidoVal = digitalRead(pinSonido);  
  if (sonidoVal == false){
    digitalWrite(pinMotor, 255);
    ledcWriteTone(0, 255);
    digitalWrite(pinLedRojo, HIGH);
    digitalWrite(pinLedVerde,  LOW);
    delay(2000);
    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde,  HIGH);
    digitalWrite(pinMotor, 0);
    ledcWriteTone(0, 0);
    // Guarda valores en base de datos
    publishData(client, 3, sonidoVal);
  }   

  // Sensor ultrasónico
  distancia = 0.01723 * readUltrasonicDistance(pinGatillo, pinEco);
  if (distancia < 30) {
    digitalWrite(pinLedRojo, HIGH);
    digitalWrite(pinLedVerde,  LOW);  
    digitalWrite(pinMotor, 255);
    ledcWriteTone(0, 255);
    delay(1000);
    digitalWrite(pinMotor, 0);
    ledcWriteTone(0, 0);
    delay(500);
    digitalWrite(pinMotor, 255);
    ledcWriteTone(0, 255);
    delay(1000);
    digitalWrite(pinMotor, 0);
    ledcWriteTone(0, 0);
    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde,  HIGH);
    publishData(client, 2, distancia);    
  }

  //Sensor de color
  uint16_t clear, red, green, blue;
  tcs.setInterrupt(false);
  delay(60); // Cuesta 50ms capturar el color
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);

  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;

  r *= 256; g *= 256; b *= 256;
  
  double hue, saturation, value;
  ColorConverter::RgbToHsv(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), hue, saturation, value);

  hue *= 360;
  if (hue > 45 && hue < 90){
    digitalWrite(pinMotor, 255);
    ledcWriteTone(0, 255);
    digitalWrite(pinLedRojo, HIGH);
    digitalWrite(pinLedVerde,  LOW);
    delay(1000);
    digitalWrite(pinMotor, 0);
    ledcWriteTone(0, 0);
    delay(500);
    digitalWrite(pinMotor, 255);
    ledcWriteTone(0, 255);
    delay(1000);  
    digitalWrite(pinMotor, 0);
    ledcWriteTone(0, 0);
    delay(500);
    digitalWrite(pinMotor, 255);
    ledcWriteTone(0, 255);
    delay(1000);  
    digitalWrite(pinMotor, 0);
    ledcWriteTone(0, 0);
    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde,  HIGH); 
    publishData(client, 5, hue);
  }
  
  tiempoActual = millis();
  if(tiempoActual - tiempoEnvio > 10000){
    tiempoEnvio = tiempoActual;
    publishData(client, 2, distancia);
    publishData(client, 3, sonidoVal);
    publishData(client, 4, valBtn);
    publishData(client, 5, hue);
  }
}

// Lectura ultrasónica
long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

// Enviar mensajes por WhatsApp
void sendMessage(String message){
  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);    
  HTTPClient http;
  http.begin(url);
  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.println("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
}

// Publicación de valores para sensores
void publishData(PubSubClient& client, int sensorNumber, float sensorValue) {
  if(!client.connected()){
    reconnect();
  }
  client.loop();

  // Building JSON
  String json = "{\"id\":\"Tacho\", \"sensor\":\"" + String(sensorNumber) + "\", \"value\":\""+ String(sensorValue)+"\"}";

  // Printing JSON in Serial
  Serial.println(json); 

  // Converting JSON string to char array
  int str_len = json.length() + 1;
  char char_array[str_len];
  json.toCharArray(char_array, str_len);

  // Publishing data to MQTT
  client.publish("manganello", char_array);
}


void callback(char* topic, byte* message, unsigned int length){
  Serial.print("Recieved message in topic");
  Serial.print(topic);

  String messageTemp;
  for(int i = 0; i<length; i++){
    Serial.print((char)message[i]);
    messageTemp+= (char)message[i];
  }
  Serial.println(messageTemp);
 
}

// Reconecting mqtt
void reconnect() {
  // Connection loop
  while (!client.connected()) {
    Serial.print("Tying connect...");
    // Intentar reconexión
    if (client.connect("client")) { 
      Serial.println("Connected");
      client.subscribe("manganello"); 
    }else {
      Serial.print("Failed connect, Error rc=");
      Serial.print(client.state());
      Serial.println(" Trying in 5 seconds");
      delay(5000);
      Serial.println (client.connected()); 
    }
  }
}
