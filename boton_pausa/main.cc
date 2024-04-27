#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_pausa.h"

using namespace std;

int main() {
    BotonPausaInicio boton = BotonPausaInicio();
    boton.inicializar();

    while(true) {
        boton.get_estado_ciclo();
        boton.iniciar_o_pausar_ciclo();
        sleep_ms(500);
    }

    return 0;
}
