#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_fases.h"

int main(){

    stdio_init_all();

    BotonCiclos botonCiclos;
    botonCiclos.inicializar(); // Configurar GPIOs necesarios

    while (true)
    {
        botonciclos.cambiarDisplay();

        botonciclos.mostrarDisplay();

        botonciclos.seleccionCiclo();

        sleep_ms(50);
    }
    
}