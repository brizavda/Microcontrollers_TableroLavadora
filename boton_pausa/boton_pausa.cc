#include "boton_pausa.h"
#include <cstdio>
#include "../include/pin_list.h"
#include "hardware/gpio.h"

// Implementación de la función de devolución de llamada
void botonCallback(uint gpio, uint32_t events) {
    if (!cicloIniciado) {
        printf("Ciclo iniciado\n");
        gpio_put(LED_PIN_1, 1); // Encender el LED rojo
        cicloIniciado = true;
    } else {
        printf("Ciclo pausado\n");
        gpio_put(LED_PIN_1, 0); // Apagar el LED rojo
        cicloIniciado = false;
    }
}
