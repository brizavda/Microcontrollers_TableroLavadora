#include <iostream>
#include "../include/pin_list.h"
#include <stdio.h>

bool cicloIniciado = false;

void botonCallback() {
    if (!cicloIniciado) {
        std::cout << "Ciclo iniciado" << std::endl;
        digitalWrite(LED_PIN_1, HIGH); // Encender el LED rojo
        cicloIniciado = true;
    } else {
        std::cout << "Ciclo pausado" << std::endl;
        digitalWrite(LED_PIN_1, LOW); // Apagar el LED rojo
        cicloIniciado = false;
    }
}

int main() {
    wiringPiSetup();
    pinMode(BOTON_START, INPUT);
    pinMode(LED_PIN_1, OUTPUT);

    std::cout << "Presiona para iniciar tu ciclo de lavado" << std::endl;

    wiringPiISR(BOTON_START, INT_EDGE_FALLING, &botonCallback);

    while (true) {
        // El programa permanece en este bucle infinito
    }

    return 0;
}
