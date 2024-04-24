#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonFases{
    private:
        int fase_actual;
        int fase_anterior;
        static uint32_t delay; // Tiempo de espera en microsegundos
        
    public:
        BotonFases(); // Constructor

        void configurarGPIOs();
        void cambiarFase();
        void mostrarFase();
        void ejecutarSecuencia();
};