#include <iostream>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "../include/pin_list.h"

class BotonPausaInicio
{
private:
    bool estado_ciclo = false;
    int valor = 1;

public:
    BotonPausaInicio();
    int leer_boton();
    void iniciar_o_pausar_ciclo();
    void inicializar();
    bool get_estado_ciclo();
};

BotonPausaInicio::BotonPausaInicio()
{
    this->estado_ciclo = estado_ciclo;
    this->valor = valor;
}

int BotonPausaInicio::leer_boton()
{
    return gpio_get(BOTON_START);
}

void BotonPausaInicio::iniciar_o_pausar_ciclo()
{
    valor = leer_boton();
    if (valor == 0)
    {
        if (estado_ciclo == false)
        {
            estado_ciclo = true;
        }
        else
        {
            estado_ciclo = false;
        }
    }
}



void BotonPausaInicio::inicializar()
{

    gpio_init(BOTON_START);

    gpio_set_dir(BOTON_START, GPIO_IN);

    gpio_pull_up(BOTON_START);
}

bool BotonPausaInicio::get_estado_ciclo()
{
    if (estado_ciclo == false)
    {
        printf("Ciclo pausado\n");
    }
    else
    {
        printf("Ciclo iniciado\n");
    }
    return estado_ciclo;
}