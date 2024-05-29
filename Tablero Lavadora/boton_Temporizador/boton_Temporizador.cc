#include "boton_Temporizador.h"
#include <cstdio>

BotonTemporizador::BotonTemporizador(uint gpio) : BOTON_GPIO(gpio) {}

void BotonTemporizador::inicializar()
{
    gpio_init(BOTON_GPIO);
    gpio_set_dir(BOTON_GPIO, GPIO_IN);
    gpio_pull_up(BOTON_GPIO);
}

bool BotonTemporizador::is_pressed()
{
    return (gpio_get(BOTON_GPIO) == 0);
}


int BotonTemporizador::aumentar_tiempo()
{
    if (is_pressed())
    {
        // Aumentar el tiempo en 30 segundos al presionar el botón
        tiempo += 30;

        // Mostrar el tiempo del temporizador después de aumentarlo
        printf("Tiempo del temporizador: %02d\n", tiempo);

        // Registrar la última pulsación y esperar un pequeño retardo
        sleep_ms(10); // Retardo de 200 milisegundos (ajustar según sea necesario)
    }
    return tiempo;
    // Si el botón se suelta, actualizar la variable de última pulsació
}

int BotonTemporizador::limpiar_tiempo(){
    tiempo = 0; 
    return tiempo;
}
