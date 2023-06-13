cmake_minimum_required(VERSION 3.23)
project(BatallaNaval)

set(CMAKE_CXX_STANDARD 14)

add_executable(BatallaNaval main.cpp juego.cpp juego.h jugador.cpp jugador.h barco.cpp barco.h tablero.cpp tablero.h)
