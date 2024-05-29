#include <iostream>            // Incluye la biblioteca estándar de entrada y salida.
#include <vector>              // Incluye la biblioteca para utilizar vectores.
#include <stdio.h>             // Incluye la biblioteca estándar de entrada y salida en C.
#include "pico/stdlib.h"       // Incluye la biblioteca de pico estándar.
#include "hardware/gpio.h"     // Incluye la biblioteca de GPIO del hardware.
#include "boton_InicioPausa.cc" // Incluye el archivo de encabezado de la clase BotonPausaInicio.

int main()
{
    BotonPausaInicio boton = BotonPausaInicio(); // Crea una instancia de la clase BotonPausaInicio.
    boton.inicializar();                         // Inicializa los pines GPIO y la UART.

    while (true)
    { // Bucle infinito.
    boton.get_estado_ciclo();
        boton.iniciar_o_pausar_ciclo();
        sleep_ms(100);
        
        
    }
}