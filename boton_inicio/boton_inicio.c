#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Función para mostrar un número en un display de 7 segmentos
void display_number(int number);

// Declaración de la función de callback para manejar eventos de GPIO
void gpio_callback(uint gpio, uint32_t events);

int main() {
    stdio_init_all();
    

    // Definición de pines GPIO
    uint led_pin = 16; // Utiliza el pin GP16 para el LED
    uint button_pin = 9; // Utiliza el pin GP9 para el botón
    uint segment_pins[] = {2, 3, 4, 5, 6, 7, 8}; // Pines para los segmentos del display de 7 segmentos

    // Inicialización del botón
    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_IN);
    gpio_pull_up(button_pin);

    // Inicialización de los pines del display de 7 segmentos
    for (int i = 0; i < 7; ++i) {
        gpio_init(segment_pins[i]);
        gpio_set_dir(segment_pins[i], GPIO_OUT);
        gpio_set_outover(segment_pins[i], GPIO_OVERRIDE_INVERT); // Invertir los valores
    }

    bool led_on = false; // Variable para rastrear si el LED está encendido o apagado
    int counter = 9; // Contador para la cuenta regresiva
    uint64_t last_time = time_us_64(); // Guarda el tiempo actual en microsegundos

    // Inicialización del LED
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
    gpio_put(led_pin, 0); // Comienza apagado

    while (true) {
        // Verifica el estado del botón y actualiza el estado del LED
        if (!gpio_get(button_pin)) { // Solo si el botón está presionado
            led_on = !led_on; // Cambia el estado del LED
            gpio_put(led_pin, led_on); // Enciende o apaga el LED según el estado
            while (!gpio_get(button_pin)); // Espera hasta que el botón se suelte
        }

        // Actualiza el temporizador cada segundo
        uint64_t current_time = time_us_64();
        if (current_time - last_time >= 1000000) {
            last_time = current_time;
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
        }

        sleep_ms(100); // Pequeña pausa para evitar sobrecarga de la CPU
    }

    return 0;
}

// Función para mostrar un número en un display de 7 segmentos
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

    uint segment_pins[] = {2, 3, 4, 5, 6, 7, 8}; // Pines para los segmentos del display de 7 segmentos

    // Activa los segmentos correspondientes según la configuración del número
    uint32_t mask = bits[number];
    for (int i = 0; i < 7; ++i) {
        if ((mask >> i) & 1) {
            gpio_put(segment_pins[i], 1);
        } else {
            gpio_put(segment_pins[i], 0);
        }
    }
}
