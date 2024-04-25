cmake_minimum_required(VERSION 3.13)

add_executable(boton_temp
        boton_temp.cc
        prueba.cc
        )

# pull in common dependencies
target_link_libraries(boton_temp pico_stdlib)

pico_enable_stdio_usb(boton_temp 1)
pico_enable_stdio_uart(boton_temp 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(boton_temp)