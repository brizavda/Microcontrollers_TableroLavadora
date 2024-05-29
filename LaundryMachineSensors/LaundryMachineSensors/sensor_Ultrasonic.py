from machine import Pin
import utime

# Function to initialize GPIOs
def init_ultrasonic(trigger_pin_num: int, echo_pin_num: int):
    trigger = Pin(trigger_pin_num, Pin.OUT)
    echo = Pin(echo_pin_num, Pin.IN)
    return trigger, echo


def measure_distance(trigger: Pin, echo: Pin) -> str:
    """Mide la distancia utilizando un sensor ultrasónico y devuelve un mensaje 
    dependiendo de la distancia medida.

    Args:
        trigger (Pin): El pin que envía el pulso de disparo.
        echo (Pin): El pin que recibe el eco.

    Returns:
        str: Un mensaje que indica el estado de la ropa dependiendo de la distancia medida.
    """
    # Enviar un pulso de 10 microsegundos al trigger
    trigger.high()
    utime.sleep(0.00001)
    trigger.low()

    comienzo = 0
    final = 0

    # Esperar a que el pin echo se ponga en alto
    while echo.value() == 0:
        comienzo = utime.ticks_us()
    
    # Esperar a que el pin echo se ponga en bajo
    while echo.value() == 1:
        final = utime.ticks_us()
    
    # Calcular la duración y la distancia
    duracion = final - comienzo
    distancia = (duracion * 0.0343) / 2

    # Determinar el mensaje basado en la distancia
    if distancia > 10:
        return "Error:"
    elif distancia > 7:
        return "No hay ropa"
    elif distancia > 5:
        return "Poca ropa"
    elif distancia > 4:
        return "Ropa suficiente"
    else:
        return "Demasiada ropa"
