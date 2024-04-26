cmake_minimum_required(VERSION 3.13)

add_executable(boton_pausa
    boton_pausa.cc
    main.cc
)

target_link_libraries(boton_pausa pico_stdlib)


pico_enable_stdio_usb(boton_pausa 1)
pico_enable_stdio_uart(boton_pausa 0)

pico_add_extra_outputs(boton_pausa)