cmake_minimum_required(VERSION 3.13)

add_executable(boton_Temporizador
        boton_Temporizador.cc
        test.cc
        )

# pull in common dependencies
target_link_libraries(boton_Temporizador pico_stdlib)

pico_enable_stdio_usb(boton_Temporizador 1)
pico_enable_stdio_uart(boton_Temporizador 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(boton_Temporizador)