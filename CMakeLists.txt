cmake_minimum_required(VERSION 3.5)
project(algo2_t1_memoria_dinamica)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tests.cpp Pila.cpp Pila.h)
add_executable(algo2_t1_memoria_dinamica ${SOURCE_FILES} Pila.cpp Pila.h)