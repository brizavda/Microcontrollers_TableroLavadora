cmake_minimum_required(VERSION 3.13)

add_executable(PruebaAnimBarrido
        prueba_anim_barrido.c
        )

# pull in common dependencies
target_link_libraries(PruebaAnimBarrido pico_stdlib)
# create map/bin/hex file etc.
pico_add_extra_outputs(PruebaAnimBarrido)