#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define FIRST_GPIO 0
#define COMMUN_1 8
#define COMMUN_2 9
#define COMMUN_3 10
#define COMMUN_4 11
#define BUTTON_GPIO 13
#define LED_PIN 14

// Mapas de bits para mostrar las palabras "HOLA" y "BYE" en un display de 7 segmentos
int palabra_HOLA[4] = {
    0x76, // H
    0x3F, // O
    0x38, // L
    0x77  // A
};

int palabra_BYE[3] = {
    0x7C, // b
    0x6E, // y
    0x79  // e
};

int main(){
    stdio_init_all();

    // Configurar GPIOs para los segmentos del display
    for (int gpio = FIRST_GPIO; gpio < FIRST_GPIO + 7; gpio++){
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0); // Apagar todos los segmentos al inicio
    }

    // Configurar pines de los dígitos comunes del display
    gpio_init(COMMUN_1);
    gpio_set_dir(COMMUN_1, GPIO_OUT);
    gpio_put(COMMUN_1, 1); // Apagar el dígito común 1
    gpio_init(COMMUN_2);
    gpio_set_dir(COMMUN_2, GPIO_OUT);
    gpio_put(COMMUN_2, 1); // Apagar el dígito común 2
    gpio_init(COMMUN_3);
    gpio_set_dir(COMMUN_3, GPIO_OUT);
    gpio_put(COMMUN_3, 1); // Apagar el dígito común 3
    gpio_init(COMMUN_4);
    gpio_set_dir(COMMUN_4, GPIO_OUT);
    gpio_put(COMMUN_4, 1); // Apagar el dígito común 4

    // Configurar pin del botón como entrada con pull-up
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    // Configurar pin del LED como salida
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}