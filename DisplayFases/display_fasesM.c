#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define PRIMER_GPIO 2
#define BOTON_GPIO1 11 // Botón para la animación circular
#define BOTON_GPIO2 12 // Botón para la animación de infinito
#define BOTON_GPIO3 13 // Botón para la animación 'S'

//Arreglos para definir las diferentes secuencias para cada botón
int secLavar[4] = {0x01, 0x22, 0x14, 0x08};                             // Secuencia como en cascada
int secEnjuagar[8] = {0x01, 0x02, 0x40, 0x10, 0x08, 0x04, 0x40, 0x20};  // Secuencia de animación de infinito
int secCentrifugar[6] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20};            // Secuencia de animación circular

// Función para inicializar los GPIOs y configurar los botones
void configurarGPIOs() {
    printf("Control de secuencia en display de 7 segmentos\n");

    for (int gpio = PRIMER_GPIO; gpio < PRIMER_GPIO + 7; gpio++) {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    gpio_init(BOTON_GPIO1);
    gpio_set_dir(BOTON_GPIO1, GPIO_IN);
    gpio_pull_up(BOTON_GPIO1); // Activar pull-up en el botón

    gpio_init(BOTON_GPIO2);
    gpio_set_dir(BOTON_GPIO2, GPIO_IN);
    gpio_pull_up(BOTON_GPIO2); // Activar pull-up en el botón

    gpio_init(BOTON_GPIO3);
    gpio_set_dir(BOTON_GPIO3, GPIO_IN);
    gpio_pull_up(BOTON_GPIO3); // Activar pull-up en el botón
}

//Función para detectar botones
int detectarBotonPresionado() {
    if (!gpio_get(BOTON_GPIO1)) {
        return 1;
    } else if (!gpio_get(BOTON_GPIO2)) {
        return 2;
    } else if (!gpio_get(BOTON_GPIO3)) {
        return 3;
    }
    return 0;
}
//Función para cambiar la secuencia
void cambiarSecuencia(int *boton_previo, int boton_actual, bool *ejecutando) {
    if (boton_actual != boton_actual) {
            *boton_previo = boton_actual;
            *ejecutando = false; // Detener la secuencia actual
            while (!gpio_get(boton_actual == 1 ? BOTON_GPIO1 : boton_actual == 2 ? BOTON_GPIO2 : BOTON_GPIO3)) {} // Esperar a que se suelte el botón
        }
}

//Función para ejecutar la secuencia
void ejecutarSecuencia(int boton_actual, bool *ejecutando) {
    if (*ejecutando) {
        switch (boton_actual) {
            case 1:
                for (int i = 0; i < 4; i++) {
                    int32_t mascara = secLavar[i] << PRIMER_GPIO;
                    gpio_set_mask(mascara);      // Activar segmentos según la máscara
                    gpio_clr_mask(mascara);      // Apagar segmentos
                }
                break;

            case 2:
                for (int i = 0; i < 8; i++) {
                    int32_t mascara = secEnjuagar[i] << PRIMER_GPIO;
                    gpio_set_mask(mascara);      // Activar segmentos según la máscara
                    gpio_clr_mask(mascara);      // Apagar segmentos
                }
                break;

            case 3:
                for (int i = 0; i < 6; i++) {
                    int32_t mascara = secCentrifugar[i] << PRIMER_GPIO;
                    gpio_set_mask(mascara);      // Activar segmentos según la máscara
                    gpio_clr_mask(mascara);      // Apagar segmentos
                }
                break;

            default:
                break;
        }
    } else {
        // Si no se está ejecutando ninguna secuencia, mantener los segmentos apagados
        gpio_clr_mask((1 << 7) - 1 << PRIMER_GPIO); // Apagar todos los segmentos
        *ejecutando = true; // Activar la secuencia para que se ejecute continuamente
    }
}

int main(){
    stdio_init_all();

    configurarGPIOs();

    int boton_previo = 0; // Variable para rastrear el último botón presionado
    int boton_actual = 0;  // Variable para rastrear el botón actual activo
    bool ejecutando = false;    // Estado del modo de secuencia

    while(true){
        //Función para detectar botones
        boton_actual = detectarBotonPresionado();
        //Función para cambiar la secuencia
        cambiarSecuencia(&boton_previo, boton_actual, &ejecutando);
        //Función para ejecutar la secuencia
        ejecutarSecuencia(boton_actual, &ejecutando);
        sleep_ms(100);
    }
}