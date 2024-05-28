import utime
from sensor_Ultrasonic import init_ultrasonic, measure_distance
from machine import I2C
from ssd1306 import SSD1306_I2C

def main():
    # Initialize GPIOs
    trigger_pin = 15
    echo_pin = 14
    trigger, echo = init_ultrasonic(trigger_pin, echo_pin)
    
    while True:
        # Measure distance
        distancia = measure_distance(trigger, echo)
        print("Distancia:", distancia, "cm")
        
        # Delay for x seconds before next measurement
        utime.sleep(1)

if __name__ == "__main__":
    main()