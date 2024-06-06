cmake_minimum_required(VERSION 3.28)
project(201807124_EDD_Practica)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(201807124_EDD_Practica
        json.hpp
        main.cpp
        NodoAvion.h
        NodoPasajero.h
        Pasajeros.h)
