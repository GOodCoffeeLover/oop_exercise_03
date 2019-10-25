cmake_minimum_required ( VERSION 2.8 )

project(oop_exercise_03)

set(CMAKE_CXX_STANDART_17)
set(CMAKE_CXX_FLAGS "-std=c++11")
add_executable( oop_exercese_03 main.cpp Figures.cpp)
