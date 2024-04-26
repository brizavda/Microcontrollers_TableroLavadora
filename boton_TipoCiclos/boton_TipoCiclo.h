#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class botonCiclos{
    private:
        // Arreglo para definir la secuencia base para todos los ciclos
        int tipoCiclos[5]; /**@brief Arreglo que contiene la secuencia en forma de "S". */
        int cicloActual; /**@brief Tipo actual del ciclo de lavado. */
        int cicloAnterior; /**< @brief Tipo anterior del ciclo de lavado. */
        static uint32_t delay; /**@brief Tiempo de espera en microsegundos para la ejecución de la secuencia. */
        /**
         * @brief Verifica si el botónde tipo de ciclo está presionado.
         * @return true el botón está presionado, false en caso contrario.
         */
        bool btnTiposPress(); 
    public:
        botonCiclos() // Constructor
        /**
         * @brief Configura los GPIOs necesarios para el control de secuencias y botones.
         */
        void inicializar()
        /**
         * @brief Cambia la fase actual si se detecta el botón presionado.
         */
        void cambiarDisplay()
         /**
         * @brief Muestra la fase actual por el monitor serial.
         */
        void mostrarDisplay()
        /**
         * @brief Ejecuta la secuencia en el display de 7 segmentos correspondiente al tipo actual.
         */
        void seleccionCiclo()
}