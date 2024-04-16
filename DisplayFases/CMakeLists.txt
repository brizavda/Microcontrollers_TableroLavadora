cmake_minimum_required(VERSION 3.13)

add_executable(DisplayFases
        display_fases.c
        )

# pull in common dependencies
target_link_libraries(DisplayFases pico_stdlib)
# create map/bin/hex file etc.
pico_add_extra_outputs(DisplayFases)