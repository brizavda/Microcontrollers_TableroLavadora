from machine import Pin
from time import sleep

import onewire
from ds18x20 import DS18X20

import binascii

ow = onewire.OneWire(Pin(4),) 

sensor = DS18X20(ow) 

direcciones = sensor.scan()
id = direcciones[0]

while (True):
    sensor.convert_temp()
    sleep (1)
    temperatura = sensor.read_temp(id)
    print (temperatura)