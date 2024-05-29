# Microcontrollers_TableroLavadora
El objetivo de este proyecto es crear un tablero de lavadora

##	:chart_with_upwards_trend: Prioridad de los botones

El siguiente apartado mostrará la prioridad de los botones dentro del proyecto de desarrollo de un tablero de lavadora.

| Botón | Funcionalidad | Prioridad |
|-------|---------------|-----------|
| Encendido/apagado |El botón permite que se encienda y se apague la lavadora | Alta: Sin este botón, la lavadora no puede ser utilizada en absoluto |
| Inicio/pausa | El botón inicia y pausa el ciclo de lavado | Alta: Es esencial el botón para el inicio de un ciclo de lavado |
| Ciclo de lavado | Permite seleccionar entre diferentes ciclos de lavado. | Media: Es importante para la personalización del ciclo de lavado |
| Tipo de lavado | Permite seleccionar el tipo de lavado | Alta: Es crucial para personalizar el proceso de lavado |
| Nivel del agua | Permite seleccionar el nivel del agua que usara el ciclo de lavado | Media: Es importante para la cantidad de agua que usara el ciclo de lavado | 
| Temporizador | Agrega tiempo al ciclo de lavado. | Medio: Determinara el tiempo que durara el ciclo de lavado | 

### Diagrama de actividades 
![D actividades](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/35c5502b-76ba-49dc-812e-3436a9fb1966)



### Pasos para el funcionamiento del tablero de lavadora

#### Actividad: Uso de la Lavadora 
1. Encender la lavadora
    - Presionar el botón de encendido/apagado
        - Si la lavadora está apagada:
            - Mostrar mensaje "Lavadora encendida"
        - Si la lavadora está encendida:
            - Mostrar mensaje "Lavadora apagada"
2. Escoger el tipo de lavado
    - Presionar el segundo botón para seleccionar el tipo de lavado:
        - Opción a: Lavar
            - Ir al paso 4 (Selección de nivel de agua)
        - Opción b: Enjuagar
            - Ir al paso 5 (Temporizador)
        - Opción c: Centrifugar
            - Ir al paso 5 (Temporizador)
        - Opción d: Completo
            - Ir al paso 3 (Selección de ciclo de lavado)
3. Escoger el ciclo de lavado (Solo si se selecciona "Completo" en el paso 2)
    - Presionar el tercer botón para seleccionar el ciclo de lavado:
        - Opción a: Delicado
        - Opción b: Normal
        - Opción c: Rápido
        - Mostrar mensaje con la opción seleccionada
4. Escoger nivel del agua
    - Presionar el cuarto botón para seleccionar el nivel de agua:
        - Opción a: Mínimo
        - Opción b: Medio
        - Opción c: Máximo
        - Mostrar mensaje con la opción seleccionada
5. Temporizar el tiempo del ciclo de lavado
    - Presionar el quinto botón para agregar tiempo al ciclo de lavado (opcional):
        - Añadir 30 segundos al tiempo del ciclo
        - Mostrar mensaje "Tiempo agregado al ciclo"
6. Iniciar ciclo
    - Presionar el sexto botón para iniciar el ciclo de lavado:
        - Mostrar mensaje "Ciclo de lavado iniciado"
7. Fin del ciclo
    - Cuando el ciclo de lavado ha terminado:
        - Mostrar mensaje "Ciclo de lavado completado"
8. Apagar la lavadora
    - Presionar el botón de encendido/apagado para apagar la lavadora
        - Mostrar mensaje "Lavadora apagada"
9. Fin

## :electric_plug: Prototipo de alambrado del circuito

![prototipo1 2](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/f0c731e2-5a11-4ade-a4c5-5adcd86035bf)

En esta imagen se presenta un prototiwpo de alambrado en su primera versión , esto significa que a lo largo de mas sprints o de mejora de funcionalidades, este prototipo evolucionara. 

## :round_pushpin: Uso de pines de la raspberry pi pico w 

Esta distribución de pines se planeo para que cada componente pudiera ser usado de una manera eficiente. Para una mayor referencia, mirar la imagen del apartado del prototipo de alambrado.  

1. **GP 0 - GP 10**

Estos 11 pines quedarón reservados para el componente "7 segmentos x 4"
el cual servira para poder mostrar mensajes ademas del temporizador principal de la lavadora.
Cada uno de los pines del display fueron escogidos con un color para uns mejor organización del prototipo. 

![7x4segmen](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/d088041f-9c67-4739-b01e-3fadf97841c4)


Como se puede observar en la imagen se tienen 7 pines para las letras de los 7 segmentos, a las cuales se les asignaron los siguientes GPIOS y los siguientes colores: 

|pin| color asignado | GPIO asignado |
|--- |---------------|---------------|
a| <font color='red'>rojo</font> | 0
b|<font color='orange'>naranja</font>| 1
c|<font color='yellow'>amarillo</font>| 2 
d|<font color='green '>verde</font>| 3 
e|<font color='blue'>azul</font>| 4 
f|<font color='purple'>morado</font>| 5
g|<font color='gray'>gris</font>| 6
D1| <font color='black'>negro</font>| 7
D2| <font color='black'>negro</font>| 8
D3| <font color='black'>negro</font>| 9
D4| <font color='black'>negro</font>| 10

2.  **GP 11 - GP 15 y GP 18-19**

Estos 7 pines seran ocupados por un display de 7 segmentos normal, el cual cumplira la función de mostrar las animaciones de los ciclos de lavado. 


![7segmentos](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/df780a6c-686a-444f-8f24-cb81d5b7c57d)

Al igual que el display de 7x4 segmentos, este display de animaciones tiene un color asignado por pin al igual que un GPIO. 

|pin| color asignado | GPIO asignado |
|--- |---------------|---------------|
a| <font color='red'>rojo</font> | 11
b|<font color='orange'>naranja</font>| 12
c|<font color='yellow'>amarillo</font>| 13
d|<font color='green '>verde</font>| 14
e|<font color='blue'>azul</font>| 15
f|<font color='purple'>morado</font>| 18
g|<font color='gray'>gris</font>| 19

3.  **GP 20**

Este pin quedo reservado para la funcionalidad de On/Off, esto debido a que se usara un botón y un led indicador. 

La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
BOTON| <font color='turquoise'>turquesa</font> | 20

4.  **GP 21**

Al igual que los pines anteriores, estos quedaron reservados para la funcionalidad de Star/Pause, igualmente hara usode un botón y un led indicador. 

La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 21

5.  **GP 22**
 Este pin se reservo para poder colocar el botón de selección de fases ciclos, solo hara uso de un solo botón. 

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 22

6. **GP 26**

Al igual que el pin anterior solo se hara uso de un botón el cual se usará para poder hacer la selección de ciclo de lavado.

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 26

7. **GP 27**

Este pin sera usado por un boton el cual servirá para poder seleccionar el nivel de aguaa de la lavadora.

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 27

8. **GP 28**

Este pin se reservo para ser ocupado por el botón del aumento de temporizador. 

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 28


9. **Pines reservados para Comunicación UART**
La comunicación UART (Transmisión Asíncrona Universal por Receptor) se utiliza para la transmisión de datos entre dos microcontroladores. En este proyecto, se establece una comunicación UART entre una Raspberry Pi Pico W y una Raspberry Pi Pico normal. La Pico W ejecuta código en C, mientras que la Pico normal utiliza MicroPython.

*Conexión de Pines*
- Raspberry Pi Pico W:
  
TX (Transmisión) en el pin 16

RX (Recepción) en el pin 17

- Raspberry Pi Pico Normal:
  
TX en el pin 16

RX en el pin 17

La configuración de la comunicación UART entre la Raspberry Pi Pico W y la Raspberry Pi Pico normal permite una transmisión de datos eficiente y fiable. Esta configuración es útil para aplicaciones donde se necesita intercambiar información entre dos microcontroladores.




# Componentes Conectados a la Raspberry Pi Pico Normal

![Imagen de WhatsApp 2024-05-29 a las 13 24 32_2f7cc810](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/141947806/80d4d898-bb67-48c2-b406-04c245fb5814)

- Pantalla OLED

Descripción: La pantalla OLED muestra un resumen de la configuración y el estado actual de la lavadora. La información presentada incluye el nivel de agua, la temperatura del agua y el estado del ciclo de lavado (en curso, terminado, etc.).

Funcionalidad: Permite a los usuarios visualizar información importante sobre el funcionamiento de la lavadora de manera clara y en tiempo real.
- Sensor de Proximidad
  
Descripción: El sensor de proximidad se utiliza para medir el nivel de agua en el tambor de la lavadora. Este sensor proporciona datos que se pueden traducir en el nivel de agua presente.

Funcionalidad: Ayuda a asegurar que la lavadora tenga la cantidad adecuada de agua para los diferentes ciclos de lavado, y puede alertar si el nivel de agua está fuera del rango deseado.

- Sensor de Temperatura

Descripción: El sensor de temperatura mide la temperatura del agua en el tambor de la lavadora. Esta información es crucial para los ciclos de lavado que requieren temperaturas específicas.

Funcionalidad: Permite el control preciso de la temperatura del agua, asegurando que se cumplan los requisitos de temperatura para diferentes tipos de ropa y detergentes.

- Buzzer

Descripción: El buzzer emite una melodía cuando un ciclo de lavado ha terminado. Esto sirve como una notificación auditiva para los usuarios.

Funcionalidad: Proporciona una alerta sonora que informa a los usuarios cuando el ciclo de lavado ha concluido, mejorando la experiencia de usuario mediante una señal clara y reconocible.

**Integración y Operación**

La integración de estos componentes en la Raspberry Pi Pico normal permite una monitorización y control precisos de los distintos aspectos del ciclo de lavado. A continuación, se describe cómo se espera que funcionen estos componentes en conjunto:

Inicio del Ciclo: Al inicio del ciclo de lavado, la Raspberry Pi Pico normal recibe configuraciones y comandos a través de UART desde la Raspberry Pi Pico W.

Monitorización Continua:

- Pantalla OLED: Actualiza continuamente para mostrar el nivel de agua, la temperatura y el estado del ciclo.
- Sensor de Proximidad: Mide y envía datos del nivel de agua, que se muestran en la pantalla OLED y se utilizan para ajustar el llenado de agua si es necesario.
- Sensor de Temperatura: Mide y envía datos de la temperatura del agua, que también se muestran en la pantalla OLED. Esta información puede usarse para ajustar la temperatura del agua durante el ciclo de lavado.

Finalización del Ciclo:

- Buzzer: Reproduce una melodía predefinida para notificar a los usuarios que el ciclo de lavado ha terminado.

## Documentación Conexión WiFi

### Archivo blynk_connection.py
- 1 Importar librerias
  - 'network': Proporciona acceso a las capacidades de red de la Raspberry Pi Pico W.
- 2 Credenciales WiFi
  - 'SSID': Nombre de la red WiFi.
  - 'PASSWORD': Contraseña de la red WiFi.
- 3 Función 'connect_wifi':
  - Activa la interfaz de red WiFi.
  - intenta conectar la red WiFi especificada.    
  - Imprime mensajes en la consola indicando el estado de la conexión.
  - Devuelve la instancia de 'network.WLAN' configurada
 
### Protocolo de Comunicación de Blynk

Blynk es una plataforma de IoT que permite la comunicación entre dispositivos físicos y una aplicación móvil. Utiliza un protocolo basado en sockets para enviar y recibir datos entre el hardware (como la Raspberry Pi Pico W) y la aplicación Blynk en el móvil.

#### Componentes de Blyn utilizados

1. Auth Token: Un token único generado para cada proyecto en Blynk. Este token es necesario para autenticar el dispositivo en la plataforma Blynk.
2. Virtual Pins: Puntos de datos que se utilizan para intercambiar información entre el dispositivo y la aplicación Blynk. Estos pines virtuales no están vinculados a pines físicos del hardware, sino que actúan como puntos de referencia lógicos.
3. Blynk Library: Proporciona una API para interactuar con la plataforma Blynk. Permite manejar conexiones, enviar datos y recibir comandos.

### Pines Virtuales Usados en el proyecto

En este proyecto, se utilizan los siguientes pines virtuales para leer y enviar datos de los sensores:

- Virtual Pin 5: Utilizado para enviar la temperatura del agua.
- Virtual Pin 6: Utilizado para enviar el nivel del agua



