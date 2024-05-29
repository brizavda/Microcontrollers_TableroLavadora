#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_TipoCiclo.h"

int main() {
    stdio_init_all();

    BotonCiclos BotonCiclos;
    BotonCiclos.configurarGPIOs(); // Configurar GPIOs necesarios

    while (true) {
        BotonCiclos.cambiarCiclo(); // Cambiar la fase si se presiona el botón

        // Mostrar fase seleccionada por serial
        BotonCiclos.mostrarCiclo();

        // Ejecutar la secuencia de LED según la fase actual
        BotonCiclos.ejecutarSecuencia();

        sleep_ms(50); // Pequeña pausa entre ciclos
    }
}