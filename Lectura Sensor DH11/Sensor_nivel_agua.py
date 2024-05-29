from machine import ADC 
from time import sleep

class SensorNivelAgua():
    
    def __init__(self, x: int) -> None:
        self.sensor_pin = ADC(x)
        
    def lectura_valor(self) -> str:
        
        valor_analogico = self.sensor_pin.read_u16()
        print(valor_analogico)
    
        if valor_analogico < 500:
            return "Sin agua"
        elif valor_analogico > 500 and valor_analogico < 30000:
            return "Nivel de agua bajo"
        elif valor_analogico > 30001 and valor_analogico < 32000: 
            return "Valor de agua media"
        else: 
            return "Nivel de agua lleno"
            