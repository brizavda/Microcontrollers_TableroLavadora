DISPLAY DE FASES DE LAVADORA - Panel de lavadora

La función del código es controlar un microcontrolador Raspberry Pi Pico W y cambiar la secuencia o animación del display de 7 segmentos dependiendo del botón que se oprima.

Son 3 secuencias diferentes.
- Fase de lavado: Secuencia en cascáda.
- Fase de enjuage: Secuencia en "8" o infinito.
- Fase de centrifugado: Secuencia en círculo.

Materiales que se necesitaron para implementar el prototipo:
1. Display de 7 segmentos ánodo común x1
2. Botones DIL Push x3
3. Resistencias de 220 Ohms (recomendado) x7
4. Cables Jumper Tipo Macho-Macho x15
5. Raspberry Pi Pico W
6. Protoboard x1

EXPLICACIÓN:
Display de 7 segmentos:
  --A--
  F   B
  --G--
  E   C
  --D--

1. El primer botón controla la secuencia para la fase de lavado. Realiza una secuencia como en cascáda.
  --A--    -- --    -- --    -- --
           F   B
  -- -- -> -- -- -> -- -- -> -- --
                    E   C
  -- --    -- --    -- --    --D--

2. El segundo botón controla la secuencia para la fase de enjuague. Realiza una secuencia en "8" o infinito.
  --A--    -- --    -- --    -- --    -- --    -- --    -- --    -- --
               B                                                 F
  -- -- -> -- -- -> --G-- -> -- -- -> -- -- -> -- -- -> --G-- -> -- --
                             E                     C
  -- --    -- --    -- --    -- --    --D--    -- --    -- --    -- --

3. El tercer botón controla la secuencia para la fase de centrifugado. Realiza una secuencia en círculo.
  --A--    -- --    -- --    -- --    -- --    -- --
               B                               F
  -- -- -> -- -- -> -- -- -> -- -- -> -- -- -> -- --
                        C             E
  -- --    -- --    -- --    --D--    -- --    -- --

NOTA: Este ejemplo y la imágen del prototipo simulan las secuencias de las fases sin el display del tiempo. Las entradas GPIO y la forma de alambrar el prototipo dependerán de cómo se integren las demás funcionalidades del panel de la lavadora.