#ifndef BOTON_PAUSA_H
#define BOTON_PAUSA_H

#include "../include/pin_list.h"
#include "hardware/gpio.h"

// Declaración de la variable cicloIniciado como externa
extern bool cicloIniciado;

// Prototipo de la función de devolución de llamada
void botonCallback(uint gpio, uint32_t events);

#endif
