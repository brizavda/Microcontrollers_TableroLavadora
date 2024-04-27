#ifndef BOTON_PAUSA_INICIO_H
#define BOTON_PAUSA_INICIO_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/pin_list.h"

using namespace std;

class BotonPausaInicio {
private:
    bool ciclo_iniciado = false;
    int valor = 1;

public:
    BotonPausaInicio();
    int leer_boton();
    void iniciar_o_pausar_ciclo();
    void actualizar_led();
    void inicializar();
    bool get_estado_ciclo();
};

#endif /* BOTON_PAUSA_INICIO_H */
