#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_PIN 3
#define BOTON_PRESS 4

int main()

{
    // Inicializar la salida estándar
    stdio_init_all();

    // Inicializar los pines GPIO para el LED y el botón
    gpio_init(LED_PIN);
    gpio_init(BOTON_PRESS);

    // Establecer la dirección de los pines GPIO
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BOTON_PRESS, GPIO_IN);

    // Activar resistencia pull-up para el botón
    gpio_pull_up(BOTON_PRESS);

    /**
    // Bucle principal
    while(true){

        // Parpadear el LED brevemente
        gpio_put(LED_PIN, 1);
        sleep_ms(1);
        gpio_put(LED_PIN, 0);
        sleep_ms(1);

        // Apagar el LED durante un tiempo más largo (simulando pausa entre parpadeos)
        gpio_put(LED_PIN, 0);
        sleep_ms(100);

        // Leer el estado del botón de presión
        if (gpio_get(BOTON_PRESS) == 1){
            // Si el botón está presionado, la lavadora está apagada
            printf("Lavadora apagada\n");
            sleep_ms(10);
        } else {
            // Si el botón no está presionado, la lavadora está encendida
            printf("Lavadora encendida\n");
            sleep_ms(10);
        }
    }  **/

    // Variable para almacenar el estado de la lavadora
    bool estado_lavadora = false;

    while (true)
    {
        // Este bucle while mejora la sensación del usuario al momento de apagar
        // la lavadora. Si se mantiene pulsado el botón, se queda en un bucle infinito
        // para evitar que se vuelva a encender la lavadora.
        while (gpio_get(BOTON_PRESS) == 0)
        {
            sleep_ms(2);
        }

        // Imprime el estado de la lavadora
        printf("Lavadora apagada\n");
        sleep_ms(50);

        // Si el estado del botón es 0, entonces el botón está presionado
        // y la lavadora se encenderá.
        if (gpio_get(BOTON_PRESS) == 0)
        {
            // Se le asigna el estado de encendido a la variable.
            estado_lavadora = true;

            // Un bucle infinito hará que la lavadora se mantenga encendida
            while (estado_lavadora)
            {
                // El LED permanecerá encendido.
                gpio_put(LED_PIN, 1);
                sleep_ms(500);

                // Mensaje tentativo para depurar y monitorear el estado de la lavadora
                printf("Lavadora encendida\n");
                sleep_ms(500);

                // Si el botón recibe en algún momento el valor de 0,
                // entonces el estado de la lavadora se asignará a falso, apagando la lavadora.
                if (gpio_get(BOTON_PRESS) == 0)
                {
                    sleep_ms(700);
                    gpio_put(LED_PIN, 0);
                    estado_lavadora = false;
                    sleep_ms(100);
                }
            }
        }
    }
}
