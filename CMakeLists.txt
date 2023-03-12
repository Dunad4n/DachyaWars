cmake_minimum_required(VERSION 3.24)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Task_2 main.cpp Entities/Character.h Entities/Farmer.cpp Entities/Farmer.h Utils/Vector2.cpp Utils/Vector2.h Entities/Mole.cpp Entities/Mole.h)
