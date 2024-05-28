from machine import Pin
from time import sleep
import onewire
from ds18x20 import DS18X20

class SensorTemperatura():
    
    def __init__(self, x: int) -> None:
        self.__x = x
        ow = onewire.OneWire(Pin(self.__x)) 
        self.sensor = DS18X20(ow) 
    
        

    def lectura_sensor(self) -> int:
    
        direcciones = self.sensor.scan()
        self.id = direcciones[0]
        self.sensor.convert_temp()
        sleep (1)
        temperatura = self.sensor.read_temp(self.id)
        return temperatura