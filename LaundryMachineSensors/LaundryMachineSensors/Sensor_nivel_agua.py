from machine import ADC 
from time import sleep

class SensorNivelAgua():
    
    def __init__(self, x: int) -> None:
        self.sensor_pin = ADC(x)
        
    def lectura_valor(self) -> str:
        
        valor_analogico = self.sensor_pin.read_u16()
        
    
        if valor_analogico < 850:
            return "Sin agua"
        elif valor_analogico > 851 and valor_analogico < 24000:
            return "Nivel_agua bajo"
        elif valor_analogico > 24001 and valor_analogico < 24999: 
            return "Nivel_agua media"
        else: 
            return "Nivel_agua lleno"
            