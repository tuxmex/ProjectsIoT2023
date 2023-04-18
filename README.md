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

## Tabla de Software utilizado
| Id | Software | Versión | Tipo |
|----|----------|---------|------|
| 01 |Visual Studio Code|1.74|Entorno de Desarrollo Integrado|
| 02 |Arduino IDE|2.0|Entorno de Desarrollo Integrado|
| 03 |ESP32|1.1.0|Librería|
| 04 |Phyton|3.10|Lenguaje de Programación|
| 05 |Node-Red|3.0.2|Herramienta de desarrollo basada en flujo|
| 06 |Mosquitto|2.0.15|Agente MQTT|

## Tabla con el hardware utilizado
| Id | Componente | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|  01  |ESP32|El módulo ESP32 es una solución de Wi-Fi/Bluetooth todo en uno, integrada y certificada que proporciona no solo la radio inalámbrica, sino también un procesador integrado con interfaces para conectarse con varios periféricos.|![Uploading image.png…](https://m.media-amazon.com/images/I/61eyPE6adjL._SL1500_.jpg)|1|$160|
|  02  |Raspberry PI 4|Raspberry Pi es una placa de microordenador, que como su propio nombre indica, es de pequeñas dimensiones a la cual se le pueden dar multitud de usos.|![Uploading image.png…](https://m.media-amazon.com/images/I/41cn6diLE0L._AC_.jpg)|1|$1991|
|  03  |LED|Un diodo LED es un dispositivo que permite el paso de corriente en un solo sentido y que al ser polarizado emite un haz de luz.|![Uploading image.png…](https://uelectronics.com/wp-content/uploads/2017/08/Leds-5-mm-difuso-V1.jpg)|4|$40|
|  04  |Push Button|Switch push miniatura momentáneo normalmente abierto. Un interruptor eléctrico es en su acepción más básica un dispositivo que permite desviar o interrumpir el curso de una corriente eléctrica.|![Uploading image.png…](https://aelectronics.com.mx/2363/push-button-4-pines.jpg)|1|$10|
|  05  |Módulo Mp3|El Módulo reproductor MP3 Arduino es un mini reproductor mp3 muy económico utilizado para reproducir estos formatos de audio en Arduino con una salida directa hacia un speaker.|![Uploading image.png…](https://www.luisllamas.es/wp-content/uploads/2017/01/arduino-mp3-DFPlayer-mini-componente.jpg)|1|$75|
|  06  |Buzzer|Es un pequeño transductor capaz de convertir la energía eléctrica en sonido. Para hacerlos funcionar solo basta conectar el positivo con el + y la tierra o negativo con el – de una batería o cualquier fuente de corriente directa.|![Uploading image.png…](https://uelectronics.com/wp-content/uploads/2018/02/AR0355-Buzzer_v3.jpg)|1|$50|
|  07  |Sensor Ultrasónico|Permite medir distancia mediante ultrasonido desde 2cm hasta 450cm, ideal para usar con Arduino o PIC, muy utilizado en Robots Exploradores.|![Uploading image.png…](https://electronicamade.com/wp-content/uploads/2020/03/sensor-distancia-ultrasonido-1.jpg)|1          |$50|
|  08  |Sensor Seguidor de Línea|El seguidor de línea es un dispositivo autónomo que rastrea las líneas en un circuito de carrera utilizando sensores infrarrojos después de que un corredor haya ingresado el tiempo y la distancia de la carrera en la que desea participar.|![Uploading image.png…](https://www.steren.com.mx/media/catalog/product/cache/b69086f136192bea7a4d681a8eaf533d/image/20292a55c/sensor-seguidor-de-linea.jpg)|1|$56|
|  09  |Jumpers|Un jumper o saltador es un elemento que permite cerrar el circuito eléctrico del que forma parte dos conexiones.|![Uploading image.png…](https://http2.mlstatic.com/D_NQ_NP_648190-MLM49852695986_052022-O.jpg)|40|$50|

## Epicas del proyecto
- En muchas ocasiones las personas tienden a ser solidarias con quienes no pueden ver, sin embargo, hay algunas excepciones tristemente, el bastón inteligente trata de ayudar de manera completa a la persona invidente, poniendo como prioridad su seguridad en todo momento, haciendo que el usuario se sienta más tranquilo al caminar.
- La mayoría de personas que no ven pueden presentar alguna dificultad incluso en lugares que no son muy concurridos, haciendo que no existan personas que puedan auxiliarlas en caso de necesitarlo, gracias al bastón pueden entender el entorno de mejor manera y pueden sentirse tranquilos al caminar.
- Hay ocasiones en que las personas invidentes pueden tener pensamientos donde se consideren una carga para los demás, claro, esto depende del entorno en el que se rodean, donde en ocasiones, tristemente los individuos son muy poco empaticos con las personas que padecen esta discapacidad, el bastón es una manera de decirle al usuario que puede ser tan capaz como el resto, que puede ser libre y no depender de nadie, haciéndole entender que todo está bien consigo mismo y que para nada es una carga, si no, una persona distinta simplemente.

## Tabla de historias de usuario
| Id | Historia de usuario | Prioridad | Estimación | Como probarlo | Responsable |
|----|---------------------|-----------|------------|---------------|-------------|
| 01 |Como usuario quiero detectar los posibles obstáculos en mi camino|Alta|4 semanas|Probando el bastón en la práctica|Erik Daniel Méndez Enríquez|
| 02 |Como usuario quiero ser avisado de los posibles riesgos cercanos.|Alta|3 semanas|Probando el bastón en la práctica|Oscar Adahir Rojas Sánchez|
| 03 |Como usuario quiero poder rastrear el bastón en caso de posible hurto|Alta|3 semanas|Captando la señal que otorgue el bastón|Miguel Ángel Hernández Solís|
| 04 |Como usuario quiero poder ver las rutas que he tomado con el bastón|Media|4 semanas|Revisando los valores mandados por los sensores a la aplicación web|Erik Daniel Méndez Enríquez|
| 05 |Como usuario quiero poder alertar que estoy en peligro|Alta|2 semanas|Probando el botón que activara el Buzzer|Miguel Ángel Hernández Solís|
| 06 |Como usuario quiero poder ser identificado del lugar donde estoy|Alta|4 semanas|Probando el bastón en la práctica|Oscar Adahir Rojas Sánchez|

## Prototipo en dibujo
![WhatsApp Image 2023-01-27 at 19 08 56](https://user-images.githubusercontent.com/70409607/215236093-be307bf0-cc9c-4ab4-abfb-0817b05bca54.jpeg)
