cmake_minimum_required(VERSION 3.13)

add_executable(boton_Nivel_agua
        boton_nivel_agua.cc
        prueba2.cc
        )

# pull in common dependencies
target_link_libraries(boton_Nivel_agua pico_stdlib)

pico_enable_stdio_usb(boton_Nivel_agua 1)
pico_enable_stdio_uart(boton_Nivel_agua 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(boton_Nivel_agua)