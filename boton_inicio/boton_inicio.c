#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const uint LED_PIN = 16; // Utiliza el pin GP16 para el LED
const uint BUTTON_PIN = 9; // Utiliza el pin GP9 para el botón
const uint SEGMENT_PINS[] = {2, 3, 4, 5, 6, 7, 8}; // Pines para los segmentos del display de 7 segmentos

bool led_on = false; // Variable para rastrear si el LED está encendido o apagado
int counter = 9; // Contador para la cuenta regresiva

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
        gpio_set_outover(SEGMENT_PINS[i], GPIO_OVERRIDE_INVERT); // Invierte los valores
    }

    while (true) {
        if (led_on) {
            printf("Ciclo iniciado\n");
            display_number(counter);
            if (counter > 0) {
                counter--;
            } else {
                counter = 9; // Reinicia el contador cuando llega a 0
            }
        } else {
            printf("Ciclo pausado\n");
        }
        sleep_ms(1000); // Espera un segundo antes de actualizar el número en el display
    }

    return 0;
}

void display_number(int number) {
    const int bits[10] = {
        0x3f,  // 0
        0x06,  // 1
        0x5b,  // 2
        0x4f,  // 3
        0x66,  // 4
        0x6d,  // 5
        0x7d,  // 6
        0x07,  // 7
        0x7f,  // 8
        0x6f   // 9
    };

    // Activa los segmentos correspondientes según la configuración del número
    uint32_t mask = bits[number];
    for (int i = 0; i < 7; ++i) {
        if ((mask >> i) & 1) {
            gpio_put(SEGMENT_PINS[i], 1);
        } else {
            gpio_put(SEGMENT_PINS[i], 0);
        }
    }
}

void gpio_callback(uint gpio, uint32_t events) {
    if (!gpio_get(BUTTON_PIN)) { // Solo si el botón está presionado
        led_on = !led_on; // Cambia el estado del LED
        gpio_put(LED_PIN, led_on); // Enciende o apaga el LED según el estado
        while (!gpio_get(BUTTON_PIN)); // Espera hasta que el botón se suelte
    }
}