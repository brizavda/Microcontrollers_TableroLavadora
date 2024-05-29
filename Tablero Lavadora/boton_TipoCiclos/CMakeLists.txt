cmake_minimum_required(VERSION 3.13)

add_executable(boton_TipoCiclos
        boton_TipoCiclos.cc
        test.cc
        )

# pull in common dependencies
target_link_libraries(boton_TipoCiclos pico_stdlib)

pico_enable_stdio_usb(boton_TipoCiclos 1)
pico_enable_stdio_uart(boton_TipoCiclos 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(boton_TipoCiclos)