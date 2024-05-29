#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_fases.h"

int main() {
    stdio_init_all();

    BotonFases botonFases;
    botonFases.configurarGPIOs(); // Configurar GPIOs necesarios

    while (true) {
        botonFases.cambiarFase(); // Cambiar la fase si se presiona el botón

        // Mostrar fase seleccionada por serial
        botonFases.mostrarFase();

        // Ejecutar la secuencia de LED según la fase actual
        botonFases.ejecutarSecuencia();

        sleep_ms(50); // Pequeña pausa entre ciclos
    }
}