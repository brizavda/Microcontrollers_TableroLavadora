#include <stdio.h>
#include "boton_nivel_agua.h"
#include "boton_temporizador.h"
#include "../include/pin_list.h"

int main() {
    stdio_init_all();

    BotonNivelAgua botonNivelAgua(BOTON_LVL_AGUA);
    botonNivelAgua.inicializar(); // Inicializar el botón de nivel de agua

    BotonTemporizador botonTemporizador(BOTON_TEMP);
    botonTemporizador.inicializar(); // Inicializar el botón de temporizador

    int nivelAgua = 1; // Nivel de agua por defecto
    int minutos = 0;
    int segundos = 0;

    while (true) {
        nivelAgua = botonNivelAgua.get_nivel(); // Obtener el nivel de agua actual
        printf("Nivel de agua seleccionado: %d\n", nivelAgua);

        botonTemporizador.aumentar_tiempo(minutos, segundos); // Aumentar tiempo si se presiona el botón de temporizador

        // Otras tareas del programa
        sleep_ms(50); // Pequeña pausa entre iteraciones del bucle
    }
    return 0;
}
