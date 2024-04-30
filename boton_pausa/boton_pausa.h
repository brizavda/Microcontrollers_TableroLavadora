#ifndef BOTON_PAUSA_INICIO_H
#define BOTON_PAUSA_INICIO_H

#include <iostream> 
#include <vector> 
#include <stdio.h>
#include "pico/stdlib.h" 
#include "hardware/gpio.h" 
#include "../include/pin_list.h" 

using namespace std; // @brief Utiliza el espacio de nombres estándar.

class BotonPausaInicio { // @brief Declaración de la clase BotonPausaInicio.
private:
    bool ciclo_iniciado = false; // @brief Variable privada para almacenar el estado del ciclo (iniciado o pausado).
    int valor = 1; // @brief Variable privada para almacenar el valor del botón.

public:
    BotonPausaInicio(); // @brief Constructor de la clase.
    int leer_boton(); // @brief Método para leer el estado del botón de inicio/pausa.
    void iniciar_o_pausar_ciclo(); // @brief Método para iniciar o pausar el ciclo.
    void actualizar_led(); // @brief Método para actualizar el estado del LED.
    void inicializar(); // @brief Método para inicializar los pines GPIO y la UART.
    bool get_estado_ciclo(); // @brief Método para obtener el estado actual del ciclo.
};

#endif /* BOTON_PAUSA_INICIO_H */ // @brief Fin de la declaración de preprocesador #ifndef y #define.
