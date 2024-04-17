# Control de Inicio/Pausa de Ciclo de Lavado

Este proyecto implementa un control de inicio/pausa de ciclo de lavado para una lavadora. Utiliza un botón conectado a un microcontrolador para controlar el inicio y la pausa del ciclo de lavado. Además, muestra en la consola el tiempo transcurrido desde que se inició el ciclo de lavado.

## Funcionalidades

- **Inicio del Ciclo de Lavado:** Al presionar el botón, se inicia el ciclo de lavado.
- **Pausa del Ciclo de Lavado:** Si el ciclo de lavado está en marcha, al presionar el botón se pausa el ciclo. Si se presiona nuevamente, se reanuda el ciclo desde el punto en que se detuvo.
- **Contador de Tiempo:** Muestra en la consola el tiempo transcurrido desde que se inició el ciclo de lavado.
- **Reinicio Automático:** Cuando el ciclo de lavado finaliza, el contador de tiempo se reinicia automáticamente.

## Implementación del Código

El código está escrito en lenguaje C y está diseñado para ser ejecutado en un microcontrolador como la Raspberry Pi Pico.

### Función `main()`

La función principal del programa inicializa los pines GPIO del botón, LED y display de 7 segmentos. Luego, entra en un bucle infinito donde verifica el estado del botón y actualiza el estado del LED. También actualiza el temporizador y muestra el tiempo transcurrido en la consola.

### Función `display_number(int number)`

Esta función se encarga de mostrar un número en un display de 7 segmentos. Recibe como argumento el número a mostrar y activa los segmentos correspondientes para representar ese número.

### Función `gpio_callback(uint gpio, uint32_t events)`

Esta función es un callback que se llama cuando se produce una interrupción en el pin GPIO del botón. Cambia el estado del LED y controla la pausa/inicio del ciclo de lavado según el estado del botón.

## Esquema de Conexión

A continuación se muestra el esquema de conexión del botón al microcontrolador:

![Esquema de Conexión](imagen_prototipo.png)

## Instalación y Uso

1. Clona este repositorio en tu dispositivo.
2. Conecta el botón al microcontrolador según el esquema de conexión proporcionado.
3. Compila y carga el código en el microcontrolador.
4. Inicia el ciclo de lavado presionando el botón.
5. Para pausar el ciclo, presiona nuevamente el botón. Para reanudar el ciclo, presiona el botón otra vez.

## Diagrama de Flujo

A continuación se muestra un diagrama de flujo que ilustra el funcionamiento del programa:



