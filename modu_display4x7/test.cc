#include <iostream>
#include <vector>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "modu_display4x7.cc"
using namespace std;

int main()
{

    modu_display4x7 display = modu_display4x7();
    display.inicializar();

    display.establecerCrono4x7(1000, 1, 150);
    display.establecerPalabraDisplay4x7(0xff, 0xff, 0xff, 0xff, 1000, 10);
}
