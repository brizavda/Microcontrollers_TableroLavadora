#include "boton_fases.h"
#include "../include/pin_list.h"

// Inicializar la variable estática delay
uint32_t BotonFases::delay = 250000; // Tiempo inicial: 250 ms

BotonFases::BotonFases() {
    fase_actual = 1;
    fase_anterior = 0;
}

void BotonFases::configurarGPIOs() {
    printf("Control de secuencia en display de 7 segmentos\n");

    for (int gpio = SECOND_GPIO; gpio < SECOND_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BOTON_FASES);
    gpio_set_dir(BOTON_FASES, GPIO_IN);
    gpio_pull_up(BOTON_FASES); // Activar pull-up en el botón
}

void BotonFases::cambiarFase() {
    if (botonFasesPresionado()) {
        fase_actual = (fase_actual % 3) + 1;
    }
}

void BotonFases::mostrarFase() {
    if (fase_actual != fase_anterior) {
        switch (fase_actual) {
            case 1:
                printf("Fase actual: %d - Lavado\n", fase_actual);
                break;
            case 2:
                printf("Fase actual: %d - Enjuague\n", fase_actual);
                break;
            case 3:
                printf("Fase actual: %d - Centrifugado\n", fase_actual);
                break;
            default:
                break;
        }
        fase_anterior = fase_actual;
    }
}