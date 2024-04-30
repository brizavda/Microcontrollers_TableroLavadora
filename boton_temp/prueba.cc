#include <stdio.h>
#include "boton_nivel_agua.h"
#include "boton_temporizador.h"
#include "../include/pin_list.h"

int main() {
    stdio_init_all();

    // Crear instancias de los botones
    BotonNivelAgua botonNivelAgua(BOTON_LVL_AGUA);
    BotonTemporizador botonTemporizador(BOTON_TEMP);

    // Inicializar los botones
    botonNivelAgua.inicializar();
    botonTemporizador.inicializar();

    int minutos = 0;
    int segundos = 0;

    while (true) {
        // Actualizar el nivel de agua seleccionado
        int nivelAgua = botonNivelAgua.get_nivel();

        // Mostrar el nivel de agua seleccionado
        // Esto es opcional, solo para propósitos de demostración
        // printf("Nivel de agua seleccionado: %d\n", nivelAgua);

        // Aumentar el tiempo del temporizador si se presiona el botón
        botonTemporizador.aumentar_tiempo(minutos, segundos);

        // Mostrar el tiempo del temporizador
        // Esto es opcional, solo para propósitos de demostración
        // printf("Tiempo del temporizador: %02d:%02d\n", minutos, segundos);

        sleep_ms(200); // Pequeña pausa entre iteraciones
    }

    return 0;
}