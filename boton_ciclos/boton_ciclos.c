#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BOTON_PRESS 4 // Definición del pin utilizado para el botón de selección de ciclos

int main(){

    stdio_init_all(); // Inicialización de la comunicación estándar para imprimir mensajes
    printf("Ciclos de lavadora - Normal(1), Delicado(2), Rápido(3)\n"); // Mensaje de bienvenida

    gpio_init(BOTON_PRESS); // Inicialización del pin del botón
    gpio_set_dir(BOTON_PRESS, GPIO_IN); // Configuración del pin como entrada
    gpio_pull_up(BOTON_PRESS); // Habilitación de resistencia pull-up para el pin

    int ciclos = 0; // Variable para almacenar el ciclo actual seleccionado
    
    bool button_pressed = false; // Variable para indicar si el botón ha sido presionado

    while(true){

        while (gpio_get(BOTON_PRESS) == 0) // Espera hasta que se presione el botón
        {
            button_pressed = true; // Se marca el botón como presionado
            sleep_ms(100); // Se espera un corto tiempo para evitar múltiples lecturas del botón
        }

        if (button_pressed == true){ // Si el botón ha sido presionado

            if (ciclos != 3) // Incrementa el contador de ciclos (si no está en el ciclo 3)
            {
                ciclos++; 
            }else{
                ciclos = 1; // Reinicia el ciclo a 1 si ya está en el ciclo 3
            }

        }

        button_pressed = false; // Restablece el estado del botón a no presionado
        sleep_ms(50); // Espera un corto tiempo antes de continuar

        // Muestra un mensaje correspondiente al ciclo seleccionado
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
 
