import time
from machine import Pin, PWM

# Configuración del zumbador en el pin GP14
zumbador = PWM(Pin(14))