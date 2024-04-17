#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define BUTTON_GPIO 2
#define SEGMENT_A_GPIO 3
#define SEGMENT_B_GPIO 4
#define SEGMENT_C_GPIO 5
#define SEGMENT_D_GPIO 6
#define SEGMENT_E_GPIO 7
#define SEGMENT_F_GPIO 8
#define SEGMENT_G_GPIO 9

void display_7seg_init(int a_pin, int b_pin, int c_pin, int d_pin, int e_pin, int f_pin, int g_pin) {
    gpio_init(a_pin);
    gpio_set_dir(a_pin, GPIO_OUT);
    gpio_init(b_pin);
    gpio_set_dir(b_pin, GPIO_OUT);
    gpio_init(c_pin);
    gpio_set_dir(c_pin, GPIO_OUT);
    gpio_init(d_pin);
    gpio_set_dir(d_pin, GPIO_OUT);
    gpio_init(e_pin);
    gpio_set_dir(e_pin, GPIO_OUT);
    gpio_init(f_pin);
    gpio_set_dir(f_pin, GPIO_OUT);
    gpio_init(g_pin);
    gpio_set_dir(g_pin, GPIO_OUT);
}

void display_7seg_display_number(int number) {
    // Define los patrones para mostrar los números del 0 al 9 en el display de 7 segmentos
    const int patterns[10][7] = {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}  // 9
    };

    if (number >= 0 && number <= 9) {
        gpio_put(SEGMENT_A_GPIO, patterns[number][0]);
        gpio_put(SEGMENT_B_GPIO, patterns[number][1]);
        gpio_put(SEGMENT_C_GPIO, patterns[number][2]);
        gpio_put(SEGMENT_D_GPIO, patterns[number][3]);
        gpio_put(SEGMENT_E_GPIO, patterns[number][4]);
        gpio_put(SEGMENT_F_GPIO, patterns[number][5]);
        gpio_put(SEGMENT_G_GPIO, patterns[number][6]);
    }
}

int main() {
    stdio_init_all();
    printf("Presiona el botón para iniciar el ciclo de lavado\n");

    // Inicializa la salida para el botón
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);

    // Inicializa el display de 7 segmentos
    display_7seg_init(SEGMENT_A_GPIO, SEGMENT_B_GPIO, SEGMENT_C_GPIO, SEGMENT_D_GPIO, SEGMENT_E_GPIO, SEGMENT_F_GPIO, SEGMENT_G_GPIO);

    int minutos = 0;
    int segundos = 0;
    int numero_display = 0;

    while (true) {
        // Actualiza el display de 7 segmentos según el número
        display_7seg_display_number(numero_display);

        if (gpio_get(BUTTON_GPIO) == 0) {
            // Espera hasta que se suelte el botón
            while (gpio_get(BUTTON_GPIO) == 0) {
                sleep_ms(10);
            }
            // Incrementa el tiempo en 30 segundos
            segundos += 30;
            if (segundos >= 60) {
                minutos += segundos / 60;
                segundos %= 60;
            }
            // Incrementa el número del display
            numero_display++;
            if (numero_display > 9) {
                numero_display = 0;
            }
            // Muestra el tiempo total y el mensaje
            printf("Tiempo total de ciclo de lavado: %d minutos y %d segundos\n", minutos, segundos);
        }
        sleep_ms(200); // Breve pausa para evitar múltiples incrementos por un solo botón
    }
    return 0;
}
