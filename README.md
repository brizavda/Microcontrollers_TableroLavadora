# MELODIAS DE LA LAVADORA

El archivo [melodias.py](melodias.py) contiene cinco funciones que realizan cindo melodias distintas para una acción o momento específico del proceso de la lavadora.

## Lista de melodias:

1. Melodía de Inicio del ciclo de lavado
2. Melodía de Encendido de la lavadora
3. Melodía de Apagado de la lavadora
4. Melodía de Pausado del ciclo de lavado
5. Melodía de Finalización del ciclo de lavado


## Funciones de las melodías

- `void reproducir_tono()`:
Esta función configura la frecuencia y volumen del zumbador pasivo.

- `void reproducir_melodia()`:
Esta función se encarga de reproducir las notas de cada melodía.

- `void melodia_encendido()`:
Reproduce la melodía de encendido de la lavadora.

- `void melodia_inicio()`:
Reproduce la melodía de inicio del ciclo de lavado.

- `void melodia_final()`:
Reproduce la melodía de la finalización del ciclo de lavado.

- `void melodia_apagado()`:
Reproduce la melodía de apagado de la lavadora.

- `void melodia_pausa()`:
Reproduce la melodía de pausado del ciclo de lavado.

## Materiales de ensamble del prototipo
    - Raspberry Pi Pico H / WH
    - 1 zumbador pasivo
    - 2 cables jumper
    - 1 protoboard
## Instrucciones de uso
1. Conecta el GPIO 14 de la raspberry al extremo positivo del zumbador pasivo.
2. Conecta el otro extremo del zumbador a GROUND (Tierra -)
3. En el archivo que desees usar las melodias, importa el módulo melodias.
4. Dependiendo de tu lógica, llama a las respectivas funciones de las melodias que deseas usar.
5. Carga tu proyecto a la raspberry y ejecuta tu programa.