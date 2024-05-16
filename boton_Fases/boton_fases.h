#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

class BotonFases{
    private:
        int secCompleto[5]; /**@brief Arreglo que contiene la secuencia para el ciclo completo. */
        int secLavar[4];    /**@brief Arreglo que contiene la secuencia para la fase de lavado. */
        int secEnjuagar[8]; /**@brief Arreglo que contiene la secuencia para la fase de enjuague. */
        int secCentrifugar[6];  /**@brief Arreglo que contiene la secuencia para la fase de centrifugado. */
        int fase_actual;    /**@brief Fase actual del ciclo de lavado. */
        int fase_anterior;  /**< @brief Fase anterior del ciclo de lavado. */
        static uint32_t delay; /**@brief Tiempo de espera en microsegundos para la ejecución de la secuencia. */
        /**
     * @brief Verifica si el botón de fases está presionado.
     * @return true si el botón está presionado, false en caso contrario.
     */
        bool botonFasesPresionado();

    public:
        BotonFases(); // Constructor
    /**
     * @brief Configura los GPIOs necesarios para el control de secuencias y botones.
     */
        void configurarGPIOs();
    /**
     * @brief Cambia la fase actual si se detecta el botón de fases presionado.
     */
        void cambiarFase();
    /**
     * @brief Muestra la fase actual por el monitor serial.
     */
        void mostrarFase();
    /**
     * @brief Ejecuta la secuencia en el display de 7 segmentos correspondiente a la fase actual.
     */
        void ejecutarSecuencia();
};