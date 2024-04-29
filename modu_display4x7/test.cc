#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "modu_display4x7.cc"
using namespace std;

int main() {
    modu_display4x7 display(0x3f, 0x38, 0x77, 0x76, 1000); 
    display.inicializar();
    while (true) {
        display.encenderDisplay4x7();
    }
    return 0;
}
