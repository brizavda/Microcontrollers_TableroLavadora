# :arrows_clockwise: Botón de Control de Ciclos de Lavado

En este apartado del proyecto se implementa un botón para la selección de ciclos de lavado para nuestra lavadora. Utiliza un botón conectado a un microcontrolador para alternar entre tres ciclos de lavado (Normal, Delicado, Rápido). Además, muestra en la consola mensajes dependiendo del ciclo que esté seleccionado.

## :writing_hand: Funcionalidad

- **Selección del Ciclo de Lavado:** Al presionar el botón, se alterna entre los tres ciclos disponibles en la lavadora (Normal, Delicado, Rápido).

## :computer: Implementación del Código

Este código es un programa escrito en lenguaje C para controlar los ciclos de una lavadora utilizando un microcontrolador compatible con el entorno de desarrollo Pico de Raspberry Pi.

- Se incluyen las bibliotecas necesarias para el manejo de entrada y salida, así como la inicialización de la comunicación estándar.
- Se define el pin utilizado para el botón de selección de ciclos de la lavadora como `BOTON_PRESS`, asignado al pin 4.
- En la función `main()`, se inicializa la comunicación estándar para permitir la salida de texto a través del puerto serie y se muestra un mensaje de bienvenida.
- Se inicializa el pin del botón de presión como entrada y se habilita la resistencia pull-up para evitar lecturas erróneas debido a fluctuaciones eléctricas.
- Se declara e inicializa la variable `ciclos` para llevar un seguimiento del ciclo actual seleccionado.
- Se establece la variable `button_pressed` como falsa para indicar que el botón no ha sido presionado.

En un bucle infinito `while(true)`:

- Se detecta si el botón ha sido presionado mediante un bucle while que espera hasta que se presione el botón y luego establece `button_pressed` como verdadero.
- Si `button_pressed` es verdadero, se incrementa el contador de ciclos (`ciclos`). Si ya está en el tercer ciclo, se reinicia a 1.
- Se restablece `button_pressed` a falso después de procesar la pulsación del botón y se espera un corto período de tiempo para evitar múltiples lecturas de un solo botón.
- Dependiendo del valor de `ciclos`, se imprime un mensaje correspondiente al ciclo seleccionado.
- Se espera un corto período de tiempo antes de repetir el bucle para evitar la sobrecarga del procesador.

En resumen, este código permite al usuario seleccionar entre tres ciclos de lavado (Normal, Delicado, Rápido) presionando un botón, y muestra el ciclo seleccionado en la salida estándar.

### Funcionalidad de los Estados del Botón

- **Estado de Reposo:** Cuando el botón no está presionado, el sistema muestra un mensaje en consola solicitando la selección de un ciclo de lavado.
- **Estado de Selección:** Al presionar el botón, se alternan entre los ciclos disponibles: Normal, Delicado, Rápido.

## :hammer_and_wrench: Esquema de Conexión

A continuación se muestra el esquema de conexión del botón al microcontrolador.

## :card_file_box: Instalación y Uso

1. Construye el prototipo de acuerdo con el esquema de conexión proporcionado.
2. Clona este repositorio en tu dispositivo.
3. Carga el archivo UF2 (incluido en este repositorio) en tu tarjeta Raspberry Pi Pico.
4. Selecciona el ciclo de lavado presionando el botón.

## Diagramas de Flujo
