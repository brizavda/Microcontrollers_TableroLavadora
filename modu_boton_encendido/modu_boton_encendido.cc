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
   
}

int boton_encendido::leer_boton()
{

}

void boton_encendido::encender_o_apagar_lavadora()
{

}

void boton_encendido::actualizar_led()
{

}

void boton_encendido::inicializar()
{

}

bool boton_encendido::get_estado_lavadora()


}