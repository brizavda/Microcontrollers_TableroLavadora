from machine import Pin
import onewire
from ds18x20 import DS18X20
from time import sleep

import binascii

ow = onewire.OneWire(Pin(4)) #Prepara GPIO4 para usar con OneWire

sensor = DS18X20(ow) #define un sensor en ese pin

direcciones = sensor.scan()  #Lee el ID del sensor conectado
id=direcciones[0]

#Pasa el ID a formato de texto e imprime
idHex = binascii.hexlify(bytearray(id)) 
print ("ID=",idHex)

#Lee e imprime la temperatura cada 1 segundo
while (True):
    
    try:
        sensor.convert_temp ()
        sleep (1)
        temperatura = sensor.read_temp (id)
        
    except:
        print ("Error en sensor!")
        sleep (1)
        
    else:
        print (temperatura)