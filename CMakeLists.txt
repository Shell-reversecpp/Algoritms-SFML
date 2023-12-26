cmake_minimum_required(VERSION 3.26)
project(SFML_GAME)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

add_executable(SFML_GAME main.cpp
        Game.cpp
        Game.h
        Shapes.cpp
        Shapes.h)
target_link_libraries(SFML_GAME sfml-graphics sfml-window)