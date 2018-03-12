cmake_minimum_required(VERSION 3.9)
project(Pr2Hanoi)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pr2Hanoi
        main.c
        hanoi_list.h
        hanoi_list.c
        hanoi_engine.c

        list_operations.c
        utils.c hanoi_engine.h)
