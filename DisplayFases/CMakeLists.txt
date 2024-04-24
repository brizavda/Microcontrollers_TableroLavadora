cmake_minimum_required(VERSION 3.13)

add_executable(DisplayFases
        display_fasesM.c
        )

# pull in common dependencies
target_link_libraries(DisplayFases pico_stdlib)

pico_enable_stdio_usb(DisplayFases 1)
pico_enable_stdio_uart(DisplayFases 0)
# create map/bin/hex file etc.
pico_add_extra_outputs(DisplayFases)