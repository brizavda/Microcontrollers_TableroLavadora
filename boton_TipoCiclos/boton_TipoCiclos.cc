#include <iostream>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_TipoCiclos.h"
#include "../include/pin_list.h"

uint32_t botonCiclos::delay = 2500000; // Tiempo inicial: 250 ms

botonCiclos::botonCiclos():
    tipoCiclos{0x01, 0x20, 0x40, 0x04, 0x08},
    cicloActual(1),
    cicloAnterior(0)
{}

void botonCiclos::inicializar()
{
    for (int gpio = SECOND_GPIO; gpio < SECOND_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BOTON_CICLOS);
    gpio_set_dir(BOTON_CICLOS, GPIO_IN);
    gpio_pull_up(BOTON_CICLOS); // Activar pull-up en el botón
}

int botonCiclos::btnTipoCiclosPress()
{
    static bool ultimoCiclo = true;
    bool cicloActual = !gpio_get(BOTON_CICLOS);

    if (cicloActual != ultimoCiclo) {
        ultimoCiclo = cicloActual;
        return cicloActual;
    }

    return false;
}

void botonCiclos::cambiarDisplay(int cicloActual)
{
    if (botonFasesPresionado()) {
        cicloActual = (cicloActual % 3) + 1;
        return cicloActual;
    }
    return cicloActual;
}

void botonCiclos::mostrarDisplay(int cicloActual, int cicloAnterior)
{
    if (cicloActual != cicloAnterior) {
        switch (cicloActual) {
            case 1:
                printf("Ciclo seleccionado: %d - Ciclo Normal\n", cicloActual);
                break;
            case 2:
                printf("Ciclo seleccionado: %d - Ciclo Delicado\n", cicloActual);
                break;
            case 3:
                printf("Ciclo seleccionado: %d - Ciclo Rápido\n", cicloActual);
                break;
            default:
                break;
        }
    }
}

void botonCiclos::seleccionCiclo(int cicloActual)
{
    switch (cicloActual)
    {
    case 1:
        for (int i = 0; i < 5; i++) {
                int32_t mask = secCiclos[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (int j = 0; j < 1500000; j++) { // Simular 100 ms
                    // Esperar
                }
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
        break;

    case 2:
        for (int i = 0; i < 5; i++) {
                int32_t mask = secCiclos[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (int j = 0; j < 2750000; j++) { // Simular 200 ms
                    // Esperar
                }
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;
        break;

    case 3:
        for (int i = 0; i < 5; i++) {
                int32_t mask = secCiclos[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (int j = 0; j < 575000; j++) { // Simular 50 ms
                    // Esperar
                }
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;
        break;
    
    default:
        break;
    }
}

