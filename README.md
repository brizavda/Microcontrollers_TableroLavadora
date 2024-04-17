# Control de Inicio/Pausa de Ciclo de Lavado :play_or_pause_button:

En esta sección del proyecto se presenta la implementación de un control de inicio/pausa para el ciclo de lavado en una lavadora. Utiliza un botón conectado a un microcontrolador para activar el inicio y la pausa del ciclo, proporcionando además retroalimentación visual a través de un LED y mostrando mensajes en la consola.

## Funcionalidades :writing_hand:

- **Inicio del Ciclo de Lavado:** Al presionar el botón, se inicia el ciclo de lavado y su temporizador.
- **Pausa del Ciclo de Lavado:** Si el ciclo de lavado está en marcha, al presionar nuevamente el botón se pausa el temporizador del ciclo. Al volver a presionar el botón, se reanuda el temporizador desde el punto en que se detuvo.

## Implementación del Código :computer: :computer_mouse:

### Función `main()`

La función principal del programa comienza inicializando los pines GPIO del botón, el LED y el display de 7 segmentos. Luego, entra en un bucle infinito donde:
- Verifica el estado del botón y actualiza el estado del LED correspondiente.
- Actualiza el temporizador cada segundo y muestra el tiempo transcurrido en la consola.

### Función `display_number(int number)`

Esta función se encarga de mostrar un número en un display de 7 segmentos. Recibe como argumento el número a mostrar y activa los segmentos correspondientes para representar dicho número.

### Función `gpio_callback(uint gpio, uint32_t events)`

Este callback se activa cuando se produce una interrupción en el pin GPIO del botón. Cambia el estado del LED y controla la pausa/inicio del ciclo de lavado según el estado del botón.

### Funcionalidad de los Estados del Botón

- **Estado de Reposo:** Cuando el botón no está presionado, el sistema permanece en estado de reposo, sin realizar ninguna acción.
- **Estado de Inicio:** Al presionar el botón, el sistema pasa al estado de inicio, iniciando el ciclo de lavado si no estaba en marcha y encendiendo el LED indicador.
- **Estado de Pausa:** Si el ciclo de lavado está en marcha y se presiona nuevamente el botón, el sistema pasa al estado de pausa. En este estado, se detiene el temporizador del ciclo de lavado y se apaga el LED indicador. Si se vuelve a presionar el botón, se reanuda el ciclo de lavado desde el punto en que se detuvo y se enciende nuevamente el LED indicador.

## Esquema de Conexión :hammer_and_wrench:

El esquema de conexión muestra la disposición del botón respecto al microcontrolador:

![imagen_prototipo](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/e18cf001-2b7f-4989-8f93-b166e2a0afcd)

## Instalación y Uso :card_file_box:

1. Construye el prototipo siguiendo el esquema de conexión proporcionado.
2. Clona el repositorio en tu dispositivo.
3. Carga el archivo UF2 (incluido en este repositorio) en tu tarjeta Raspberry Pi Pico.
4. Inicia el ciclo de lavado y su temporizador presionando el botón.
5. Para pausar el ciclo y el temporizador, presiona nuevamente el botón.
6. Para reanudar el ciclo, presiona el botón otra vez.

## Diagramas de Flujo

### Diagrama de flujo de la Función `main()`

El diagrama de flujo principal representa el flujo de control del programa. Comienza inicializando los pines GPIO y luego entra en un bucle donde verifica el estado del botón, actualiza el LED y el temporizador, mostrando el tiempo transcurrido en la consola.

![diagrama_funcion_main](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/ded5f95f-3759-4d90-89cd-952841ec8193)

### Diagrama de flujo de la Función `display_number(int number)`

Este diagrama maneja la función `display_number`, que muestra un número en un display de 7 segmentos. Verifica si el número es válido y activa los segmentos correspondientes para mostrarlo.

![mermaid-diagram-2024-04-17-000635](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/15d51eff-1fcb-43ce-b0f4-3ccbfa28f6e5)

### Diagrama de Flujo para la Función `gpio_callback(uint gpio, uint32_t events)`

Este diagrama describe la función `gpio_callback`, que maneja las interrupciones del botón. Espera la interrupción del botón, verifica su estado, cambia el LED correspondiente y espera hasta que el botón se libere.

![mermaid-diagram-2024-04-17-000821](https://github.com/brizavda/Microcontrollers_TableroLavadora/assets/125591740/ecd52ccf-e6c4-4743-9b9b-de6adf68f485)

Creo que estos cambios hacen que el README sea más cohesivo y fácil de entender. ¿Hay algo más en lo que pueda ayudarte?
