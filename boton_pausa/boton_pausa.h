#ifndef BOTON_PAUSA_H
#define BOTON_PAUSA_H

#include "../include/pin_list.h"
#include "hardware/gpio.h"

extern bool cicloIniciado;

// Definición del tipo de la función de devolución de llamada
typedef void (*gpio_irq_callback_t)(uint, uint32_t);

// Declaración de la función de devolución de llamada
void botonCallback(uint gpio, uint32_t events);

#endif
