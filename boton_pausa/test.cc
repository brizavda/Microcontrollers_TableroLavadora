#include <iostream> // Incluye la biblioteca estándar de entrada y salida.
#include <vector> // Incluye la biblioteca para utilizar vectores.
#include <stdio.h> // Incluye la biblioteca estándar de entrada y salida en C.
#include "pico/stdlib.h" // Incluye la biblioteca de pico estándar.
#include "hardware/gpio.h" // Incluye la biblioteca de GPIO del hardware.
#include "boton_pausa.h" // Incluye el archivo de encabezado de la clase BotonPausaInicio.

using namespace std; // Utiliza el espacio de nombres estándar.

int main() {
    BotonPausaInicio boton = BotonPausaInicio(); // Crea una instancia de la clase BotonPausaInicio.
    boton.inicializar(); // Inicializa los pines GPIO y la UART.

    while(true) { // Bucle infinito.
        boton.get_estado_ciclo(); // Obtiene y muestra el estado actual del ciclo.
        boton.iniciar_o_pausar_ciclo(); // Inicia o pausa el ciclo dependiendo del estado del botón.
        sleep_ms(500); // Espera 500 milisegundos.
    }

    return 0; // Retorna 0 para indicar que el programa ha finalizado correctamente.
}
