# SmartCane

## Integrantes del equipo 
- Oscar Adahir Rojas Sánchez (1220100308)
- Erik Daniel Méndez Enríquez (1220100445)
- Miguel Ángel Hernández Solís (1220100587)

## Objetivo general
El objetivo general de este proyecto es construir un bastón inteligente el cual ayude tanto a personas ciegas como adultos mayores a la hora de transitar solos por las calles, dicho bastón ayudará a las personas a caminar por la banqueta de una manera más segura ya proporcionará ayuda, guiando a las personas que lo llevan, además, en caso de detectar un objeto enfrente o salga de la banqueta el bastón avisará a su usuario, también tendrá opciones de alerta para el momento en el que se sientan en peligro o necesiten ayuda con cualquier cosa, solo basta con activar un botón de este y se accionará una alarma para que los demás se percaten de la situación y se acerquen a ayudarlo.

### Objetivos específicos
- Lograr un sistema que detecte objetos a cierta distancia con precisión
- Lograr un sistema que informe en tiempo real las características del entorno en las que se encuentra el usuario
- Lograr un sistema que logre dar alertas en caso de peligro
- Lograr un sistema fácil de uso para el usuario
- Lograr un sistema capaz de registrar la información en un dashboard de manera eficaz


## Tabla de Software Utilizado
| Id | Software | Versión | Tipo |
|----|----------|---------|------|
| 01 |Arduino IDE|2.0|Entorno de Desarrollo Integrado|
| 02 |Phyton|3.10|Lenguaje de Programación|
| 03 |Node-Red|3.0.2|Herramienta de desarrollo basada en flujo|
| 04 |Mosquitto|2.0.15|Agente MQTT|

## Tabla de Hardware Utilizado (Controladores y Otros)
| Id | Controlador | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|  01  |ESP32|El módulo ESP32 es una solución de Wi-Fi/Bluetooth todo en uno, integrada y certificada que proporciona no solo la radio inalámbrica, sino también un procesador integrado con interfaces para conectarse con varios periféricos.|![Uploading image.png…](https://m.media-amazon.com/images/I/61eyPE6adjL._SL1500_.jpg)|1|$160|
|  02  |Raspberry PI 4|Raspberry Pi es una placa de microordenador, que como su propio nombre indica, es de pequeñas dimensiones a la cual se le pueden dar multitud de usos.|![Uploading image.png…](https://m.media-amazon.com/images/I/41cn6diLE0L._AC_.jpg)|1|$1991|
|  03  |Powerbank|Un powerbank es un dispositivo portátil de carga que se utiliza para cargar dispositivos electrónicos como smartphones, tabletas, reproductores de música, cámaras digitales, entre otros. También se le conoce como batería externa o cargador portátil.|![Uploading image.png…](https://m.media-amazon.com/images/I/61+ul9GMcOL._AC_SY355_.jpg)|1|$189|

## Tabla de Hardware Utilizado (Sensores)
| Id | Sensor | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|  01  |Push Button|Switch push miniatura momentáneo normalmente abierto. Un interruptor eléctrico es en su acepción más básica un dispositivo que permite desviar o interrumpir el curso de una corriente eléctrica.|![Uploading image.png…](https://aelectronics.com.mx/2363/push-button-4-pines.jpg)|1|$10|
|  02  |Ultrasónico|Permite medir distancia mediante ultrasonido desde 2cm hasta 450cm, ideal para usar con Arduino o PIC, muy utilizado en Robots Exploradores.|![Uploading image.png…](https://electronicamade.com/wp-content/uploads/2020/03/sensor-distancia-ultrasonido-1.jpg)|1          |$50|
|  03  |Sensor de color RGB TCS34725|es un sensor de color RGB que se utiliza para detectar y medir la luz de diferentes colores. Este sensor es capaz de medir la intensidad de luz roja, verde, azul y blanco en una amplia variedad de condiciones de iluminación.|![Uploading image.png…](https://electronicathido.com/assets/recursosImagenes/productos/2216/imagenes/TCS34725%20Modulo%20Sensor%20De%20Color%20RGB.jpg)|1|$130|
|  04  |GPS|Es un dispositivo que utiliza señales de satélites para determinar la ubicación precisa de un objeto en la Tierra en tiempo real. El sensor recopila datos de los satélites y los procesa para proporcionar información sobre la latitud, longitud, altitud y velocidad del objeto en movimiento.|<img width="464" alt="ALV" src="https://user-images.githubusercontent.com/123588416/232864448-c6eb3bc4-a92a-4231-9c6f-e11d2bff5728.png">|1|$199|
|  05  |Big Sound|Este dispositivo tiene la capacidad de detectar la amplitud del sonido. Con ayuda del preset que incluye en el misma PCB, podemos seleccionar el nivel de sonido que nos interesa detectar.|<img width="416" alt="bigsound" src="https://user-images.githubusercontent.com/123588416/232865713-eed79bee-11da-469a-9046-cebb473f0e41.png">|1|$39|
|  06  |Switch|Es un dispositivo mecánico o electrónico que se utiliza para controlar la corriente eléctrica mediante la apertura o el cierre de un circuito eléctrico. Cuando se activa el switch, se produce un cambio en el estado del circuito, lo que permite la activación o desactivación de otros componentes del sistema.|<img width="416" alt="bigsound" src="https://http2.mlstatic.com/D_NQ_NP_839711-MLM31220244656_062019-O.webp">|1|$35|

## Tabla de Hardware Utilizado (Actuadores)
| Id | Actuadores | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|  01  |LED|Un diodo LED es un dispositivo que permite el paso de corriente en un solo sentido y que al ser polarizado emite un haz de luz.|![Uploading image.png…](https://uelectronics.com/wp-content/uploads/2017/08/Leds-5-mm-difuso-V1.jpg)|2 - rojo y verde|$20|
|  02  |Buzzer|Es un pequeño transductor capaz de convertir la energía eléctrica en sonido. Para hacerlos funcionar solo basta conectar el positivo con el + y la tierra o negativo con el – de una batería o cualquier fuente de corriente directa.|![Uploading image.png…](https://uelectronics.com/wp-content/uploads/2018/02/AR0355-Buzzer_v3.jpg)|1|$50|
|  03  |Motor de vibración tipo moneda|Es un pequeño componente que al momento de ser conectado a un voltaje entre 2V y 5V, causara un efecto de vibratorio. Con rotación y posición en cualquier sentido y de corriente continua.|<img width="346" alt="Motor Vibración" src="https://user-images.githubusercontent.com/123588416/232861525-90978106-d4ee-4780-9790-a05f8cc4cee6.png">|1|$42|

## Tabla de Hardware Utilizado (Cables)
| Id | Cables | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|  01  |Jumpers|Un jumper o saltador es un elemento que permite cerrar el circuito eléctrico del que forma parte dos conexiones.|![Uploading image.png…](https://http2.mlstatic.com/D_NQ_NP_648190-MLM49852695986_052022-O.jpg)|120|$80|
|  02  |Micro USB|Es un cable de carga y transferencia de datos que tiene un conector pequeño y reversible en ambos extremos.|<img width="362" alt="usb " src="https://user-images.githubusercontent.com/123588416/232867677-7ffe46e8-a1fe-48a4-bfe2-76e51786cbc0.png">|2|$50|

## Epicas del proyecto
- En muchas ocasiones las personas tienden a ser solidarias con quienes no pueden ver, sin embargo, hay algunas excepciones tristemente, el bastón inteligente trata de ayudar de manera completa a la persona invidente, poniendo como prioridad su seguridad en todo momento, haciendo que el usuario se sienta más tranquilo al caminar.
- La mayoría de personas que no ven pueden presentar alguna dificultad incluso en lugares que no son muy concurridos, haciendo que no existan personas que puedan auxiliarlas en caso de necesitarlo, gracias al bastón pueden entender el entorno de mejor manera y pueden sentirse tranquilos al caminar.
- Hay ocasiones en que las personas invidentes pueden tener pensamientos donde se consideren una carga para los demás, claro, esto depende del entorno en el que se rodean, donde en ocasiones, tristemente los individuos son muy poco empaticos con las personas que padecen esta discapacidad, el bastón es una manera de decirle al usuario que puede ser tan capaz como el resto, que puede ser libre y no depender de nadie, haciéndole entender que todo está bien consigo mismo y que para nada es una carga, si no, una persona distinta simplemente.

## Tabla de historias de usuario
| Id | Como               | Quiero                                                                                | Para                                                                          | Condiciones                                                                                                                                                                                   |
|----|--------------------|---------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 01 | Usuario del bastón | Que el sistema me alerte en caso de peligro                                           | Evitar accidentes y lesiones                                                  | * Las alertas deben ser claras y sencillas de entender * Las alertas deben ser configurables para el usuario * El sistema debe dar retroalimentación inmediata al usuario                     |
| 02 | Usuario del bastón | Que el sistema sea capaz de detectar ciertos colores                                  | Poder circular de manera segura y eficiente en mi entorno                     | * El sistema debe de detectar distintos colores para poder diferenciar obstáculos y señalamientos * El sistema debe de proporcionar retroalimentación al usuario mediante vibración o sonido  |
| 03 | Usuario del bastón | Que el sistema informe en tiempo real las estadisticas del entorno donde me encuentro | Poder planificar mi ruta de manera más efectiva                               | * La información proporcionada por el sistema debe ser precisa y actualizada                                                                                                                  |
| 04 | Usuario del bastón | Que el sistema sea sencillo de usar, con una interfaz simple e intuitiva              | Poder acceder a todas las funciones y configuraciones sin dificultad          | * El sistema debe de ser intuitivo y sencillo para las personas que no están familiarizadas con la tecnología                                                                                 |
| 05 | Usuario del bastón | Que el sistema sea capaz de registrar y visualizar la información en un dashboard     | Poder analizar mis estadísticas y mejorar mi experiencia de uso a largo plazo | * El sistema debe de ser capaz de almacenar la información del usuario  * El dashboard debe de ser fácil de usar y entender                                                                   |

## Dashboard del proyecto
- Monitoreo del sensor ultrasónico

El sensor ultrasónico admite valores del 0 al 220, en donde cuando se tiene una distancia del 80% se muestra un color verde, haciendo saber que la distancia es buena en relación a un objeto cercano, el 40% de la distancia es representado con el color naranja, mostrando que la distancia es regular, finalmente, en el color rojo, se representa una distancia corta, que tiene valores del 39% hacía abajo. 

![Ultrasónico](https://user-images.githubusercontent.com/123588416/234077732-7cb55947-3a10-4795-a7cf-58e2f806d31e.jpeg)

- Monitoreo del sensor big sound

El sensor big sound admite valores del 0 al 1, en donde el 1 muestra que el sensor está activo, haciendo que la gráfica cambie a color verde, por otro lado, el 0 muestra que el sensor está inactivo, dejando el estado de la grafica en color blanco 

- Monitoreo del sensor de color

- Monitoreo del sensor de botón

## Visualizando proyecto final
![WhatsApp Image 2023-04-24 at 11 41 45 (1)](https://user-images.githubusercontent.com/70409607/234081042-f5cfbc26-e9f4-43b0-bfce-d0d9d09d08c1.jpeg)
![WhatsApp Image 2023-04-24 at 11 41 45](https://user-images.githubusercontent.com/70409607/234081045-d164d50f-fd6a-4b7a-a41d-1f4ec14252de.jpeg)
![WhatsApp Image 2023-04-24 at 11 41 44 (1)](https://user-images.githubusercontent.com/70409607/234081046-c4b0d3e7-13e4-4b38-995e-d2940b029d86.jpeg)
![WhatsApp Image 2023-04-24 at 11 41 47 (1)](https://user-images.githubusercontent.com/70409607/234081051-66a4d1c0-ecd3-43b1-b0af-5684e804d3e6.jpeg)
![WhatsApp Image 2023-04-24 at 11 41 47](https://user-images.githubusercontent.com/70409607/234081052-c5009c0a-fa59-4077-87b0-2cfd5439262c.jpeg)
![WhatsApp Image 2023-04-24 at 11 41 46](https://user-images.githubusercontent.com/70409607/234081056-b6ee0148-b46b-4d18-973f-363724b82a77.jpeg)

## Video explicativo del proyecto
