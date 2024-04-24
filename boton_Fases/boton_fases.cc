#include "boton_fases.h"

// Inicializar la variable estática delay
uint32_t BotonFases::delay = 250000; // Tiempo inicial: 250 ms

BotonFases::BotonFases() {
    fase_actual = 1;
    fase_anterior = 0;
}