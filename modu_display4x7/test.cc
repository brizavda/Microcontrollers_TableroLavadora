#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "modu_display4x7.cc"
using namespace std;

int main(){

    stdio_init_all();

    int palabra[4] = {
    0x76,
    0x3f,
    0x38,
    0x77,
};


    modu_display4x7 display = modu_display4x7(palabra);
    display.inializar();

    while (true)
    {
        display.encenderDisplay4x7();
    }
    

}