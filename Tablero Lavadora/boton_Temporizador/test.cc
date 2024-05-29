#include <stdio.h>
#include "boton_temporizador.h"
#include "../include/pin_list.h"

int main() {
    stdio_init_all();

    // Crear instancias de los botones
    BotonTemporizador botonTemporizador(BOTON_TEMP);

    // Inicializar los botones
    botonTemporizador.inicializar();
    int tiempo = 0;

    while (true) {

        tiempo = botonTemporizador.aumentar_tiempo();

        printf("Tiempo del temporizador: %02d", tiempo);

        sleep_ms(200); // Pequeña pausa entre iteraciones
    }

    return 0;
}