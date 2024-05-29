#include <stdio.h>
#include <iostream> // Incluye la biblioteca estándar de entrada y salida.
#include "pico/stdlib.h" // Incluye la biblioteca de pico estándar.
#include "hardware/gpio.h" // Incluye la biblioteca de GPIO del hardware.
#include "boton_NivelAgua.h"
#include "../include/pin_list.h"

int main() {
    stdio_init_all();

    // Crear instancias de los botones
    BotonNivelAgua botonNivelAgua(BOTON_LVL_AGUA);

    // Inicializar los botones
    botonNivelAgua.inicializar();


    while (true) {
        // Actualizar el nivel de agua seleccionado
        int nivelAgua = botonNivelAgua.get_nivel();

        // Mostrar el nivel de agua seleccionado
        // Esto es opcional, solo para propósitos de demostración
        printf("Nivel de agua seleccionado: %d\n", nivelAgua);


    }

    return 0;
}