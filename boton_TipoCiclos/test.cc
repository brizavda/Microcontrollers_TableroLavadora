#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_TipoCiclo.h"

int main() {
    stdio_init_all();

    BotonCiclos botonCiclos;
    botonCiclos.inicializar(); // Configurar GPIOs necesarios

    while (true) {
        botonCiclos.cambiarDisplay(); // Cambiar la fase si se presiona el botón

        // Mostrar fase seleccionada por serial
        botonCiclos.mostrarDisplay();

        // Ejecutar la secuencia de LED según la fase actual
        botonCiclos.seleccionCiclo();

        sleep_ms(50); // Pequeña pausa entre ciclos
    }
}