from machine import Pin
import utime

# Function to initialize GPIOs
def init_ultrasonic(trigger_pin_num: int, echo_pin_num: int):
    trigger = Pin(trigger_pin_num, Pin.OUT)
    echo = Pin(echo_pin_num, Pin.IN)
    return trigger, echo