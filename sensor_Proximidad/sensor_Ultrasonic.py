from machine import Pin
import utime

# Function to initialize GPIOs
def init_ultrasonic(trigger_pin_num: int, echo_pin_num: int):
    trigger = Pin(trigger_pin_num, Pin.OUT)
    echo = Pin(echo_pin_num, Pin.IN)
    return trigger, echo

# Function to measure distance
def measure_distance(trigger: Pin, echo: Pin) -> float:
    # Send a 10 microsecond pulse to trigger
    trigger.high()
    utime.sleep(0.00001)
    trigger.low()

    # Wait for echo to start
    while echo.value() == 0:
        comienzo = utime.ticks_us()
    
    # Wait for echo to end
    while echo.value() == 1:
        final = utime.ticks_us()
    
    # Calculate the duration and distance
    duracion = final - comienzo
    distancia = (duracion * 0.0343) / 2
    return distancia
