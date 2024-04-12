#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint LED_PIN = 16; // Utiliza el pin GP16 para el LED
const uint BUTTON_PIN = 9; // Utiliza el pin GP9 para el botón
const uint SEGMENT_PINS[] = {2, 3, 4, 5, 6, 7, 8}; // Pines para los segmentos del display de 7 segmentos

bool timer_paused = true; // Comienza pausado
int counter = 9; // Comienza desde 9

void display_number(int number);
void gpio_callback(uint gpio, uint32_t events);

int main() {
    stdio_init_all();
    
    // Inicializa el LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0); // Comienza apagado

    // Inicializa el botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    // Inicializar los pines del display de 7 segmentos
    for (int i = 0; i < 7; ++i) {
        gpio_init(SEGMENT_PINS[i]);
        gpio_set_dir(SEGMENT_PINS[i], GPIO_OUT);
    }

    printf("Presione el botón para comenzar.\n");
    while (true) {
        if (!timer_paused) {
            display_number(counter);
            sleep_ms(1000); // Espera un segundo
            
            // Decrementa el contador y reinicia si alcanza menos de 0
            if (--counter < 0) {
                counter = 9;
            }
        }
    }
    
    return 0;
}

void display_number(int number) {
    // Define la configuración de los segmentos para cada número del 0 al 9
    // Cada bit representa si el segmento correspondiente debe estar encendido o apagado
    const uint8_t digit_config[10] = {
        0b11111100, // 0
        0b01100000, // 1
        0b11011010, // 2
        0b11110010, // 3
        0b01100110, // 4
        0b10110110, // 5
        0b10111110, // 6
        0b11100000, // 7
        0b11111110, // 8
        0b11110110  // 9
    };

    // Verifica si el número está dentro del rango válido
    if (number >= 0 && number <= 9) {
        // Activa los segmentos correspondientes según la configuración del número
        uint8_t segment_config = digit_config[number];
        for (int i = 0; i < 7; ++i) {
            // Enciende o apaga el pin GPIO correspondiente según el bit en la configuración del número
            gpio_put(SEGMENT_PINS[i], !(segment_config & (1 << i)));
        }
    } else {
        // Si el número no está dentro del rango válido, apaga todos los segmentos
        for (int i = 0; i < 7; ++i) {
            gpio_put(SEGMENT_PINS[i], 1); // Apaga el segmento
        }
    }
}

void gpio_callback(uint gpio, uint32_t events) {
    timer_paused = !timer_paused;
    gpio_put(LED_PIN, !timer_paused); // Enciende o apaga el LED según el estado

    if (timer_paused) {
        printf("Ciclo pausado en %d.\n", counter);
    } else {
        printf("Continuando el ciclo...\n");
    }
}
