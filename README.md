# 	:play_or_pause_button: Control de Inicio/Pausa de Ciclo de Lavado

En este apartado del proyecto se  implementa un control de inicio/pausa de ciclo de lavado para nuestra lavadora. Utiliza un botón conectado a un microcontrolador para controlar el inicio y la pausa del ciclo de lavado. Además, muestra en la consola mensajes de "ciclo iniciado /pausado"

## :writing_hand: Funcionalidades

- **Inicio del Ciclo de Lavado:** Al presionar el botón, se inicia el ciclo de lavado y su temporizador.
- **Pausa del Ciclo de Lavado:** Si el ciclo de lavado está en marcha, al presionar el botón se pausa el temporizador del ciclo. Si se presiona nuevamente, se reanuda el temporizador desde el punto en que se detuvo.


## :computer: 	:computer_mouse: Implementación del Código

El código está escrito en lenguaje C y está diseñado para ser ejecutado en un microcontrolador como la Raspberry Pi Pico.

### Función `main()`

La función principal del programa inicializa los pines GPIO del botón, LED y display de 7 segmentos. Luego, entra en un bucle infinito donde verifica el estado del botón y actualiza el estado del LED. También actualiza el temporizador y muestra el tiempo transcurrido en la consola.

**Implementación:**
- La función `main()` comienza inicializando los pines GPIO del botón, LED y display de 7 segmentos.
- Luego, entra en un bucle infinito donde:
  - Verifica el estado del botón y actualiza el estado del LED según corresponda.
  - Actualiza el temporizador cada segundo y muestra el tiempo transcurrido en la consola.

### Función `display_number(int number)`

Esta función se encarga de mostrar un número en un display de 7 segmentos. Recibe como argumento el número a mostrar y activa los segmentos correspondientes para representar ese número.

**Propósito:** Mostrar números en un display de 7 segmentos.

**Funcionamiento:** La función recibe un número entero como parámetro y utiliza un array predefinido para determinar qué segmentos deben estar activados para representar ese número en el display.

**Implementación:**
- Utiliza un array de bits predefinido que representa la configuración de los segmentos para cada número del 0 al 9.
- Luego, activa los segmentos correspondientes según la configuración del número recibido como parámetro.

### Función `gpio_callback(uint gpio, uint32_t events)`

Esta función es un callback que se llama cuando se produce una interrupción en el pin GPIO del botón. Cambia el estado del LED y controla la pausa/inicio del ciclo de lavado según el estado del botón.

**Propósito:** Manejar eventos de interrupción del botón.

**Funcionamiento:** La función se llama cuando se produce una interrupción en el pin GPIO del botón. Verifica el estado del botón y cambia el estado del LED y el ciclo de lavado según corresponda.

**Implementación:**
- Utiliza operaciones de lectura y escritura en los pines GPIO para controlar el estado del botón y del LED.
- Se utiliza un bucle para esperar hasta que el botón se suelte antes de realizar cualquier acción, asegurando así que se detecte correctamente el cambio de estado del botón.


### Funcionalidad de los Estados del Botón

- **Estado de Reposo:** Cuando el botón no está presionado, el sistema se encuentra en estado de reposo. En este estado, no se realiza ninguna acción.
- **Estado de Inicio:** Cuando se presiona el botón, el sistema pasa al estado de inicio. En este estado, se inicia el ciclo de lavado si no estaba en marcha, y se enciende el LED indicador.
- **Estado de Pausa:** Si el ciclo de lavado está en marcha y se vuelve a presionar el botón, el sistema pasa al estado de pausa. En este estado, se pausa el ciclo de lavado y se apaga el LED indicador. Si se presiona nuevamente el botón, se reanuda el ciclo de lavado desde el punto en que se detuvo y se enciende el LED indicador nuevamente.
- 
## :hammer_and_wrench: Esquema de Conexión

A continuación se muestra el esquema de conexión del botón al microcontrolador:

![imagen_prototipo](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/e18cf001-2b7f-4989-8f93-b166e2a0afcd)


## :card_file_box: Instalación y Uso

1. Construye el prototipo de acuerdo con el esquema de conexión proporcionado.
2. Clona este repositorio en tu dispositivo.
3. Carga el archivo UF2 (cargado en este mismo repositorio )en tu tarjeta Raspberry Pi Pico.
4. Inicia el ciclo de lavado y su temporizador presionando el botón.
5. Para pausar el ciclo y el temporizador, presiona nuevamente el botón.
6. Para reanudar el ciclo , presiona el botón otra vez.


## Diagramas de Flujo

### Diagrama de flujo de la Función `main()`

El diagrama de flujo main() representa el flujo de control principal del programa. Comienza inicializando los pines GPIO y luego entra en un bucle donde verifica el estado del botón. Dependiendo de si el botón está presionado o no, cambia el estado del LED correspondiente. Además, actualiza el temporizador y muestra el tiempo transcurrido en la consola. Este proceso se repite continuamente hasta que se detiene el programa.

![diagrama_funcion_main](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/ded5f95f-3759-4d90-89cd-952841ec8193)




### Diagrama de flujo de la Función `display_number(int number)`

Este diagrama de flujo maneja la función display_number, que se encarga de mostrar un número en un display de 7 segmentos. Primero, verifica si el número proporcionado es válido. Si es válido, activa los segmentos correspondientes en el display para mostrar el número. Si el número no es válido, el proceso termina.
![mermaid-diagram-2024-04-17-000635](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/15d51eff-1fcb-43ce-b0f4-3ccbfa28f6e5)


 ### Diagrama de Flujo para la Función ` gpio_callback(uint gpio, uint32_t events)`
 Este diagrama de flujo describe la función gpio_callback, que maneja las interrupciones del botón. Espera la interrupción del botón y luego verifica su estado. Si el botón está presionado, cambia el estado del LED correspondiente y espera hasta que el botón se libere. Una vez que se libera el botón, el proceso termina.
 
 ![mermaid-diagram-2024-04-17-000821](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/ecd52ccf-e6c4-4743-9b9b-de6adf68f485)

