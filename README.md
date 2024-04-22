# Microcontrollers_TableroLavadora
El objetivo de este proyecto es crear un tablero de lavadora

## Prioridad de los botones

El siguiente apartado mostrara la prioridad de los botones dentro del proyecto de desarrollo de un tablero de lavadora.

| Botón | Funcionalidad | Prioridad |
|-------|---------------|-----------|
| Encendido/apagado |El botón permite que se encienda y se apague la lavadora | Alta: Sin este botón, la lavadora no puede ser utilizada en absoluto |
| Inicio/pausa | El botón inicia y pausa el ciclo de lavado | Alta: Es esencial el botón para el inicio de un ciclo de lavado |
| Ciclo de lavado | Permite seleccionar entre diferentes ciclos de lavado. | Media: Es importante para la personalización del ciclo de lavado |
| Tipo de lavado | Permite seleccionar el tipo de lavado | Alta: Es crucial para personalizar el proceso de lavado |
| Nivel del agua | Permite seleccionar el nivel del agua que usara el ciclo de lavado | Media: Es importante para la cantidad de agua que usara el ciclo de lavado | 
| Temporizador | Agrega tiempo al ciclo de lavado. | Medio: Determinara el tiempo que durara el ciclo de lavado | 

### Diagrama de actividades 

[](https://github.com/brizavda/Microcontrollers_TableroLavadora/blob/main/D.%20actividades%20tablero%20de%20lavadora-P%C3%A1gina-1.3.jpg)

### Pasos para el funcionamiento del tablero de lavadora

#### Actividad: Uso de la Lavadora 
1. Encender la lavadora
    - Presionar el botón de encendido/apagado
        - Si la lavadora está apagada:
            - Encender el LED
            - Mostrar mensaje "Lavadora encendida"
        - Si la lavadora está encendida:
            - Apagar el LED
            - Mostrar mensaje "Lavadora apagada"
2. Escoger el tipo de lavado
    - Presionar el segundo botón para seleccionar el tipo de lavado:
        - Opción a: Lavar
            - Ir al paso 4 (Selección de nivel de agua)
        - Opción b: Enjuagar
            - Ir al paso 5 (Temporizador)
        - Opción c: Centrifugar
            - Ir al paso 5 (Temporizador)
        - Opción d: Completo
            - Ir al paso 3 (Selección de ciclo de lavado)
3. Escoger el ciclo de lavado (Solo si se selecciona "Completo" en el paso 2)
    - Presionar el tercer botón para seleccionar el ciclo de lavado:
        - Opción a: Delicado
        - Opción b: Normal
        - Opción c: Rápido
        - Mostrar mensaje con la opción seleccionada
4. Escoger nivel del agua
    - Presionar el cuarto botón para seleccionar el nivel de agua:
        - Opción a: Mínimo
        - Opción b: Medio
        - Opción c: Máximo
        - Mostrar mensaje con la opción seleccionada
5. Temporizar el tiempo del ciclo de lavado
    - Presionar el quinto botón para agregar tiempo al ciclo de lavado (opcional):
        - Añadir 30 segundos al tiempo del ciclo
        - Mostrar mensaje "Tiempo agregado al ciclo"
6. Iniciar ciclo
    - Presionar el sexto botón para iniciar el ciclo de lavado:
        - Mostrar mensaje "Ciclo de lavado iniciado"
7. Fin del ciclo
    - Cuando el ciclo de lavado ha terminado:
        - Mostrar mensaje "Ciclo de lavado completado"
8. Apagar la lavadora
    - Presionar el botón de encendido/apagado para apagar la lavadora
        - Apagar el LED
        - Mostrar mensaje "Lavadora apagada"
9. Fin

### Uso de pines de la raspberry pi pico w

- Pines de botones: 6
- Pines de leds : 2
- Piens del 4 x 7segmentos : 11

**Total  19**

