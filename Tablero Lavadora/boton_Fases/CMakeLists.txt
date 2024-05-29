cmake_minimum_required(VERSION 3.13)

add_executable(boton_Fases
        boton_fases.cc
        test.cc
        )

# pull in common dependencies
target_link_libraries(boton_Fases pico_stdlib)

pico_enable_stdio_usb(boton_Fases 1)
pico_enable_stdio_uart(boton_Fases 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(boton_Fases)