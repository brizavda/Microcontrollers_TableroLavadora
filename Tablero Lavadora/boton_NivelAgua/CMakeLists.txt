cmake_minimum_required(VERSION 3.13)

add_executable(boton_NivelAgua
    boton_NivelAgua.cc
    test.cc
)

target_link_libraries(boton_NivelAgua pico_stdlib)


pico_enable_stdio_usb(boton_NivelAgua 1)
pico_enable_stdio_uart(boton_NivelAgua 0)

pico_add_extra_outputs(boton_NivelAgua)