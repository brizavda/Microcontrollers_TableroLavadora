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

![Se presentaa el diagrama de actividades del tablero de lavadora ](/imagenes/D.actividades.jpg)

### Pasos para el funcionamiento del tablero de lavadora

#### Actividad: Uso de la Lavadora 
1. Encender la lavadora
    - Presionar el botón de encendido/apagado
        - Si la lavadora está apagada:
            - Encender el LED
            - Mostrar mensaje "Lavadora encendida"
        - Si la lavadora está encendida:
            - Apagar el LED
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
        - Apagar el LED
        - Mostrar mensaje "Lavadora apagada"
9. Fin

## :electric_plug: Prototipo de alambrado del circuito
![Se presentaa el diagrama de conexiones del prototipo provisional en su primera versión ](/imagenes/prototipo1.2.jpg)

En esta imagen se presenta un prototiwpo de alambrado en su primera versión , esto significa que a lo largo de mas sprints o de mejora de funcionalidades, este prototipo evolucionara. 

## :round_pushpin: Uso de pines de la raspberry pi pico w 

Esta distribución de pines se planeo para que cada componente pudiera ser usado de una manera eficiente. Para una mayor referencia, mirar la imagen del apartado del prototipo de alambrado.  

1. *GP 0 - GP 10* 

Estos 11 pines quedarón reservados para el componente "7 segmentos x 4"
el cual servira para poder mostrar mensajes ademas del temporizador principal de la lavadora.
Cada uno de los pines del display fueron escogidos con un color para uns mejor organización del prototipo. 

![Se presentaa el diagrama de pines del 7x4 segmentos ](/imagenes/74segmen.jpg) 

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

2.  *GP 11 - GP 17*

Estos 7 pines seran ocupados por un display de 7 segmentos normal, el cual cumplira la función de mostrar las animaciones de los ciclos de lavado. 

![Se presentaa el diagrama de pines del 7x4 segmentos ](/imagenes/7segmentos.png)  
Al igual que el display de 7x4 segmentos, este display de animaciones tiene un color asignado por pin al igual que un GPIO. 

|pin| color asignado | GPIO asignado |
|--- |---------------|---------------|
a| <font color='red'>rojo</font> | 11
b|<font color='orange'>naranja</font>| 12
c|<font color='yellow'>amarillo</font>| 13
d|<font color='green '>verde</font>| 14
e|<font color='blue'>azul</font>| 15
f|<font color='purple'>morado</font>| 16
g|<font color='gray'>gris</font>| 17

3.  *GP 18 - GP 19*

Estos 2 pines quedaron reservados para la funcionalidad de On/Off, esto debido a que se usara un botón y un led indicador. 

La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
LED| <font color='turquoise'>turquesa</font> | 18
Botón|<font color='orange'>naranja</font>| 19

4.  *GP 20 - GP 21*

Al igual que los pines anteriores, estos quedaron reservados para la funcionalidad de Star/Pause, igualmente hara usode un botón y un led indicador. 

La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
LED| <font color='turquoise'>turquesa</font> | 20
Botón|<font color='orange'>naranja</font>| 21
5.  *GP 22*
 Este pin se reservo para poder colocar el botón de selección de fases ciclos, solo hara uso de un solo botón. 

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 22
6. *GP 26*

Al igual que el pin anterior solo se hara uso de un botón el cual se usará para poder hacer la selección de ciclo de lavado.

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 26

7. *GP 27*

Este pin sera usado por un boton el cual servirá para poder seleccionar el nivel de aguaa de la lavadora.

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 27

8. *GP 28*

Este pin se reservo para ser ocupado por el botón del aumento de temporizador. 

 La aignacion de colores y de pines es la siguiente: 

|Componente| color asignado | GPIO asignado |
|--- |---------------|---------------|
Botón|<font color='orange'>naranja</font>| 28
