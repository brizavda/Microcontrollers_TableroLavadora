#include "BotonNivelAgua.h"
#include "pin_list.h"
#include <stdio.h>

BotonNivelAgua::BotonNivelAgua(uint gpio) : BOTON_GPIO(gpio) {
    gpio_init(BOTON_GPIO);
    gpio_set_dir(BOTON_GPIO, GPIO_IN);
    gpio_pull_up(BOTON_GPIO);
}

bool BotonNivelAgua::is_pressed() {
    return (gpio_get(BOTON_GPIO) == 0);
}

void BotonNivelAgua::control_nivel_agua() {
    enum NivelAgua { MINIMO, MEDIO, MAXIMO };
    NivelAgua nivel_actual = MINIMO; // Comenzamos con el nivel mínimo

    while (true) {
        // Espera hasta que se presione el botón
        while (!is_pressed()) {
            sleep_ms(10);
        }

        // Cambia al siguiente nivel de agua
        switch (nivel_actual) {
            case MINIMO:
                nivel_actual = MEDIO;
                break;
            case MEDIO:
                nivel_actual = MAXIMO;
                break;
            case MAXIMO:
                nivel_actual = MINIMO;
                break;
        }

        // Configura el nivel de agua
        switch (nivel_actual) {
            case MINIMO:
                printf("Nivel de agua: Mínimo\n");
                break;
            case MEDIO:
                printf("Nivel de agua: Medio\n");
                break;
            case MAXIMO:
                printf("Nivel de agua: Máximo\n");
                break;
        }

        // Espera hasta que se suelte el botón
        while (is_pressed()) {
            sleep_ms(10);
        }
    }
}
