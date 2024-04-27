#include <iostream>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "boton_TipoCiclo.h"
#include "../include/pin_list.h"

uint32_t BotonCiclos::delayDelicado = 2750000; // Tiempo inicial: 250 ms
uint32_t BotonCiclos::delayRapido = 575000; // Tiempo inicial: 50 ms
uint32_t BotonCiclos::delayNormal = 1500000; // Tiempo inicial: 50 ms

BotonCiclos::BotonCiclos()
  : tipoCiclos{0x01, 0x20, 0x40, 0x04, 0x10},
    cicloActual(1),
    cicloAnterior(0)
{}

void BotonCiclos::inicializar()
{
    for (int gpio = SECOND_GPIO; gpio < SECOND_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BOTON_CICLOS);
    gpio_set_dir(BOTON_CICLOS, GPIO_IN);
    gpio_pull_up(BOTON_CICLOS); // Activar pull-up en el botón
}

bool BotonCiclos::btnTipoCiclosPress()
{
    static bool ultimoCiclo = true;
    bool cicloActual = !gpio_get(BOTON_CICLOS);

    if (cicloActual != ultimoCiclo) {
        ultimoCiclo = cicloActual;
        return cicloActual;
    }

    return false;
}

void BotonCiclos::cambiarDisplay()
{
    if (btnTipoCiclosPress()) {
        cicloActual = (cicloActual % 3) + 1;
    }
}

void BotonCiclos::mostrarDisplay()
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
        cicloAnterior = cicloActual;
    }
}

void BotonCiclos::seleccionCiclo()
{
    int32_t mask;

    switch (cicloActual)
    {
    case 1:
        for (int i = 0; i < 5; i++) {
                mask = tipoCiclos[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (uint32_t j = 0; j < delayNormal; j++) { // Simular 100 ms
                    // Esperar
                }
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
        break;

    case 2:
        for (int i = 0; i < 5; i++) {
                mask = tipoCiclos[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (uint32_t j = 0; j < delayDelicado; j++) { // Simular 200 ms
                    // Esperar
                }
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
        break;

    case 3:
        for (int i = 0; i < 5; i++) {
                mask = tipoCiclos[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                for (uint32_t j = 0; j < delayRapido; j++) { // Simular 50 ms
                    // Esperar
                }
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
        break;
    
    default:
        break;
    }
}

