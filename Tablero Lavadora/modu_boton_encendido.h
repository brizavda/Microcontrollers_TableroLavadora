#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "..\include\lista_pin.h"

using namespace std;

class boton_encendido
{
private:
    bool estado_lavadora = false;
    int valor = 1;

public:
    boton_encendido();
    int leer_boton();
    void encender_o_apagar_lavadora();
    void actualizar_led();
    void inicializar();
    bool get_estado_lavadora();
};

boton_encendido::boton_encendido()
{
    this->estado_lavadora = estado_lavadora;
    this->valor = valor;
}

int boton_encendido::leer_boton()
{
    return gpio_get(BOTON_ON_OFF);
}

void boton_encendido::encender_o_apagar_lavadora()
{
    valor = leer_boton();
    if (valor == 0)
    {
        if (estado_lavadora == false)
        {
            estado_lavadora = true;
        }
        else
        {
            estado_lavadora = false;
        }
    }

    actualizar_led();
}

void boton_encendido::actualizar_led()
{

    if (estado_lavadora == false)
    {
        gpio_put(LED_PIN_1, 0);
    }
    else
    {
        gpio_put(LED_PIN_1, 1);
    }
}

void boton_encendido::inicializar()
{
    stdio_init_all();

    gpio_init(LED_PIN_1);
    gpio_init(BOTON_ON_OFF);
    gpio_set_dir(LED_PIN_1, GPIO_OUT);
    gpio_set_dir(BOTON_ON_OFF, GPIO_IN);

    gpio_pull_up(BOTON_ON_OFF);
}

bool boton_encendido::get_estado_lavadora()
{
    if (estado_lavadora == false)
    {
        printf("Lavadora apagada\n");
    }
    else
    {
        printf("Lavadora encendida\n");
    }
    return estado_lavadora;
}