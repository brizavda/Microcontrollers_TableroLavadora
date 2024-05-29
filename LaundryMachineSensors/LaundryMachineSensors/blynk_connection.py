import network
from time import sleep
import BlynkLib

# Reemplaza con tus credenciales y token de Blynk
SSID = '#WUAMC'  
PASSWORD = 'wificua6'  
BLYNK_AUTH = 'S7taOmoMRuVzJWM7wrT9QSHhDHbx74tb'

def connect_wifi(ssid, password):
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while not wlan.isconnected():
        print('Connecting to WiFi...')
        sleep(1)
    print('Connected to WiFi')
    print('Network config:', wlan.ifconfig())
    return wlan

def init_blynk(auth_token):
    return BlynkLib.Blynk(auth_token)

# Conecta a la red WiFi
wlan = connect_wifi(SSID, PASSWORD)

# Inicializa Blynk
blynk = init_blynk(BLYNK_AUTH)