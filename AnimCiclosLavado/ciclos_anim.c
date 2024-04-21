#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 1
#define FIRST_GPIO 2

// Arreglo para definir la secuencia base para todos los ciclos
int secCiclos[5] = {0x01, 0x20, 0x40, 0x04, 0x08}; // Secuencia en forma de "S"