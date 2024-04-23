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
        gpio_set_outover(gpio, GPIO_OVERRIDE_INVERT);
    }

    gpio_init(BOTON_FASES);
    gpio_set_dir(BOTON_FASES, GPIO_IN);
    gpio_pull_up(BOTON_FASES); // Activar pull-up en el botón
}

//Función para detectar botones
int detectarBotonPresionado() {
    if (!gpio_get(BOTON_FASES)) {
        return 1;
    } else if (!gpio_get(BOTON_FASES)) {
        return 2;
    } else if (!gpio_get(BOTON_FASES)) {
        return 3;
    }
    return 0;
}
//Función para cambiar la secuencia
void cambiarSecuencia(int *boton_previo, int boton_actual, bool *ejecutando) {
    if (boton_actual != boton_actual) {
            *boton_previo = boton_actual;
            *ejecutando = false; // Detener la secuencia actual
            while (!gpio_get(boton_actual == 1 ? BOTON_FASES : boton_actual == 2 ? BOTON_FASES : BOTON_FASES)) {} // Esperar a que se suelte el botón
        }
}

//Función para ejecutar la secuencia
void ejecutarSecuencia(int boton_actual, bool *ejecutando) {
    if (*ejecutando) {
        switch (boton_actual) {
            case 1:
                for (int i = 0; i < 4; i++) {
                    int32_t mascara = secLavar[i] << SECOND_GPIO;
                    gpio_set_mask(mascara);      // Activar segmentos según la máscara
                    gpio_clr_mask(mascara);      // Apagar segmentos
                }
                break;

            case 2:
                for (int i = 0; i < 8; i++) {
                    int32_t mascara = secEnjuagar[i] << SECOND_GPIO;
                    gpio_set_mask(mascara);      // Activar segmentos según la máscara
                    gpio_clr_mask(mascara);      // Apagar segmentos
                }
                break;

            case 3:
                for (int i = 0; i < 6; i++) {
                    int32_t mascara = secCentrifugar[i] << SECOND_GPIO;
                    gpio_set_mask(mascara);      // Activar segmentos según la máscara
                    gpio_clr_mask(mascara);      // Apagar segmentos
                }
                break;

            default:
                break;
        }
    } else {
        // Si no se está ejecutando ninguna secuencia, mantener los segmentos apagados
        gpio_clr_mask((1 << 7) - 1 << SECOND_GPIO); // Apagar todos los segmentos
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