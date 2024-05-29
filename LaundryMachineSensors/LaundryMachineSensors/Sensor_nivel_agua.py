from machine import ADC 
from time import sleep

class SensorNivelAgua():
    
    def __init__(self, x: int) -> None:
        self.sensor_pin = ADC(x)
        
    def lectura_valor(self) -> str:
        
        valor_analogico = self.sensor_pin.read_u16()
        print(valor_analogico)
    
        if valor_analogico < 700:
            return "Sin agua"
        elif valor_analogico > 700 and valor_analogico < 24000:
            return "Agua: bajo"
        elif valor_analogico > 24001 and valor_analogico < 24999: 
            return "Agua: media"
        else: 
            return "Agua; lleno"
            
            
    def valor_analogico(self) -> int: 
        valor_analogico = self.sensor_pin.read_u16()
        return valor_analogico 
        
            
