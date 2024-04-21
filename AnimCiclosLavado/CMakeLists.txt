cmake_minimum_required(VERSION 3.13)

add_executable(AnimCiclosLavado
    ciclos_anim.c
)

target_link_libraries(AnimCiclosLavado pico_stdlib)


pico_enable_stdio_usb(AnimCiclosLavado 1)
pico_enable_stdio_uart(AnimCiclosLavado 0)

pico_add_extra_outputs(AnimCiclosLavado)