#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonCiclos{
    private:
        int secCiclos[5];
        int cicloActual; 
        int cicloAnterior;
        static uint32_t delayNormal; 
        static uint32_t delayDelicado;
        static uint32_t delayRapido;
        

    public:
        BotonCiclos(); // Constructor
    /**
     * @brief Configura los GPIOs necesarios para el control de secuencias y botones.
     */
        void configurarGPIOs();
    /**
     * @brief Cambia la fase actual si se detecta el botón de fases presionado.
     */
        void cambiarCiclo();
    /**
     * @brief Muestra la fase actual por el monitor serial.
     */
        int mostrarCiclo();
    /**
     * @brief Ejecuta la secuencia en el display de 7 segmentos correspondiente a la fase actual.
     */
        void ejecutarSecuencia();
    /**
     * @brief Verifica si el botón de fases está presionado.
     * @return true si el botón está presionado, false en caso contrario.
     */
        bool botonCiclosPresionado();
};