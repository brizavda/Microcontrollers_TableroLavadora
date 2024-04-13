#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint LED_PIN = 16; // Utiliza el pin GP16 para el LED
const uint BUTTON_PIN = 9; // Utiliza el pin GP9 para el botón

bool led_on = false; // Variable para rastrear si el LED está encendido o apagado

void gpio_callback(uint gpio, uint32_t events);

int main() {
    stdio_init_all();
    printf("Press the button to toggle the LED!\n");

    // Inicializa el LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0); // Comienza apagado

    // Inicializa el botón
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        if (led_on) {
            printf("Ciclo iniciado\n");
        } else {
            printf("Ciclo pausado\n");
        }
        sleep_ms(1000); // Pequeña pausa para evitar sobrecarga de la CPU
    }

    return 0;
}

void gpio_callback(uint gpio, uint32_t events) {
    if (!gpio_get(BUTTON_PIN)) { // Solo si el botón está presionado
        led_on = !led_on; // Cambia el estado del LED
        gpio_put(LED_PIN, led_on); // Enciende o apaga el LED según el estado
        while (!gpio_get(BUTTON_PIN)); // Espera hasta que el botón se suelte
    }
}
