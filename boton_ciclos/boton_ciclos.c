#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 4

int main(){

    stdio_init_all();
    printf("Ciclos de lavadora - Normal(1), Delicado(2), Rápido(3)\n");

    gpio_init(BOTON_PRESS);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);
    gpio_pull_up(BOTON_PRESS);

    int ciclos = 0;
    
    bool button_pressed = false;

    while(true){

        while (gpio_get(BOTON_PRESS) == 0)
        {
            button_pressed = true;
            sleep_ms(100);
        }

        if (button_pressed == true){
            
            if (ciclos != 3)
            {
                ciclos++;
            }else{
                ciclos = 1;
            }

        }

        cambio_de_nivel = false;
        sleep_ms(50);

        if (ciclos == 0)
        {
            printf("Selecciona el nivel de agua\n");
            sleep_ms(50);
        }
        else if (ciclos == 1)
        {
            printf("Ciclo Normal\n");
            sleep_ms(50);
        }
        else if (ciclos == 2)
        {
            printf("Ciclo Delicado\n");
            sleep_ms(50);
        }
        else if (ciclos == 3)
        {
            printf("Ciclo Rapido\n");
            sleep_ms(50);
        }
    }

}