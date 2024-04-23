#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
using namespace std;

#define LED_PIN 21
#define BOTON_PRESS 20

class boton_encendido
{
private:
    bool estado_lavadora = false;
    int valor = 1;

public:
    boton_encendido();
    void encender_o_apagar_lavadora(int);
    void actualizar_led();
    void inicializar();
    void get_estado_lavadora();
};

boton_encendido::boton_encendido()
{
    this->estado_lavadora = estado_lavadora;
    this->valor = valor;
}

void boton_encendido::encender_o_apagar_lavadora(int _valor)
{
    valor = _valor;
    if (valor == 0)
    {
        estado_lavadora == true;
    }
    else
    {
        estado_lavadora == true;
    }
}

void boton_encendido::actualizar_led()
{

    if (estado_lavadora == false)
    {
        gpio_put(LED_PIN, 1);
    }
    else
    {
        gpio_put(LED_PIN, 0);
    }
    sleep_ms(1);
}

void boton_encendido::inicializar()
{
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_init(BOTON_PRESS);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);

    gpio_pull_up(BOTON_PRESS);
}

void boton_encendido::get_estado_lavadora(){
    
}