#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define SECOND_GPIO 11 //Primer pin del display individual
#define BOTON_FASES 22 //Pin del botón de fases

//Arreglos para definir las diferentes secuencias para cada botón
int secLavar[4] = {0x01, 0x22, 0x14, 0x08};                             // Secuencia como en cascada
int secEnjuagar[8] = {0x01, 0x02, 0x40, 0x10, 0x08, 0x04, 0x40, 0x20};  // Secuencia de animación de infinito
int secCentrifugar[6] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20};            // Secuencia de animación circular

// Función para inicializar los GPIOs y configurar los botones
void configurarGPIOs() {
    printf("Control de secuencia en display de 7 segmentos\n");

    for (int gpio = SECOND_GPIO; gpio < SECOND_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
    }

    gpio_init(BOTON_FASES);
    gpio_set_dir(BOTON_FASES, GPIO_IN);
    gpio_pull_up(BOTON_FASES); // Activar pull-up en el botón
}

// Función para verificar el estado del botón
bool botonFasesPresionado() {
    static bool ultimoEstado = true;
    bool estadoActual = !gpio_get(BOTON_FASES);

    if (estadoActual != ultimoEstado) {
        ultimoEstado = estadoActual;
        return estadoActual;
    }

    return false;
}

// Función para cambiar el ciclo actual al presionar el botón
int cambiarFase(int fase_actual) {
    if (botonFasesPresionado()) {
        // Cambiar al siguiente ciclo al presionar el botón
        fase_actual = (fase_actual % 3) + 1;
        return fase_actual;
    }
    return fase_actual;
}

// Función para mostrar el ciclo seleccionado por serial
void mostrarFase(int fase_actual, int fase_anterior) {
    if (fase_actual != fase_anterior) {
        switch (fase_actual) {
            case 1:
                printf("Fase actual: %d - Lavado\n", fase_actual);
                break;
            case 2:
                printf("Fase actual: %d - Enjuague\n", fase_actual);
                break;
            case 3:
                printf("Fase actual: %d - Centrifugado\n", fase_actual);
                break;
            default:
                break;
        }
    }
}

/// Función para ejecutar la secuencia de LED según el ciclo actual
void ejecutarSecuencia(int fase_actual) {
    switch (fase_actual) {
        case 1:
            for (int i = 0; i < 4; i++) {
                int32_t mask = secLavar[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                sleep_ms(250);               // Esperar un tiempo
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;

        case 2:
            for (int i = 0; i < 8; i++) {
                int32_t mask = secEnjuagar[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                sleep_ms(250);               // Esperar un tiem
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;

        case 3:
            for (int i = 0; i < 6; i++) {
                int32_t mask = secCentrifugar[i] << SECOND_GPIO;
                gpio_set_mask(mask); // Activar los segmentos correspondientes
                sleep_ms(250);               // Esperar un tiem
                gpio_clr_mask(mask); // Apagar los segmentos del display
            }
            break;

        default:
            break;
    }
}

int main(){
    stdio_init_all();

    configurarGPIOs();

    int fase_actual = 1;
    int fase_anterior = 0;

    while (true) {
        // Cambiar fase si se presiona el botón
        fase_actual = cambiarFase(fase_actual);

        // Mostrar fase seleccionado por serial
        mostrarFase(fase_actual, fase_actual);

        // Ejecutar la secuencia de LED según la fase actual
        ejecutarSecuencia(fase_actual);

        fase_anterior = fase_actual; // Actualizar la fase anterior
    }
}