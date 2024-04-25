#include "boton_fases.h"
#include "../include/pin_list.h"

// Inicializar la variable estática delay
uint32_t BotonFases::delay = 250000; // Tiempo inicial: 250 ms

BotonFases::BotonFases() 
    : secLavar{0x01, 0x22, 0x14, 0x08},
      secEnjuagar{0x01, 0x02, 0x40, 0x10, 0x08, 0x04, 0x40, 0x20},
      secCentrifugar{0x01, 0x02, 0x04, 0x08, 0x10, 0x20},
      fase_actual(1),
      fase_anterior(0)
{}

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

void BotonFases::ejecutarSecuencia() {
    switch (fase_actual) {
        case 1:
            for (int i = 0; i < 4; i++) {
                int32_t mask = secLavar[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (uint32_t j = 0; j < delay; j++) {} // Esperar utilizando un bucle
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;

        case 2:
            for (int i = 0; i < 8; i++) {
                int32_t mask = secEnjuagar[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (uint32_t j = 0; j < delay; j++) {} // Esperar utilizando un bucle
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;

        case 3:
            for (int i = 0; i < 6; i++) {
                int32_t mask = secCentrifugar[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (uint32_t j = 0; j < delay; j++) {} // Esperar utilizando un bucle
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;

        default:
            break;
    }
}

bool BotonFases::botonFasesPresionado() {
    static bool ultimoEstado = true;
    bool estadoActual = !gpio_get(BOTON_FASES);

    if (estadoActual != ultimoEstado) {
        ultimoEstado = estadoActual;
        return estadoActual;
    }

    return false;
}