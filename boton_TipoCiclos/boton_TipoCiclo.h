#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class botonCiclos{
    private:
        int cicloNormal[4];    /**@brief Arreglo que contiene la secuencia para la fase de lavado. */
        int cicloDelicado[8]; /**@brief Arreglo que contiene la secuencia para la fase de enjuague. */
        int cicloRapido[6];
        int cicloActual;
        int cicloAnterior;
        static uint32_t delay; 
        bool btnPress()

    public:
        botonCiclos()
        void inicializar()
        void cambiarDisplay()
        void mostrarDisplay()
        void seleccionCiclo()
}