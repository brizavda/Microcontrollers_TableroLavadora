#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "modu_display4x7.cc"
using namespace std;

int main() {

    modu_display4x7 display = modu_display4x7(0x00, 0x00, 0x00, 0x00, 1000, 1, true, 123);
    display.inicializar();

    while(true){
        display.establecerCrono4x7(10000, 1);

    }

    



}
    