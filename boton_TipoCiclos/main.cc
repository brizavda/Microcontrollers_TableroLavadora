#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_TipoCiclo.h"

int main(){

    stdio_init_all();

    BotonCiclos botonCiclos;
    botonCiclos.inicializar(); // Configurar GPIOs necesarios

    while (true)
    {
        botonCiclos.cambiarDisplay();

        botonCiclos.mostrarDisplay();

        botonCiclos.seleccionCiclo();

        sleep_ms(50);
    }
    
}