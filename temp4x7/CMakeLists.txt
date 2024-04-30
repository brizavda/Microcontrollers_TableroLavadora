cmake_minimum_required(VERSION 3.13)

add_executable(temp4x7
        boton_temp.cc
        prueba.cc
        )

# pull in common dependencies
target_link_libraries(temp4x7 pico_stdlib)

pico_enable_stdio_usb(temp4x7 1)
pico_enable_stdio_uart(temp4x7 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(temp4x7)