cmake_minimum_required(VERSION 3.13)

add_executable(modu_display4x7
    # modu_display4x7.cc
    test.cc
)

target_link_libraries(modu_display4x7 pico_stdlib)


pico_enable_stdio_usb(modu_display4x7 1)
pico_enable_stdio_uart(modu_display4x7 0)

pico_add_extra_outputs(modu_display4x7)
