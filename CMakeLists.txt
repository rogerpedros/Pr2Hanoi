cmake_minimum_required(VERSION 3.9)
project(Pr2Hanoi)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pr2Hanoi
        discos.c
        hanoi_basico.c
        hanoi_list.h
        hanoi_list.c
        main.c
        moviments.c
        torres.c)
