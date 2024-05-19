cmake_minimum_required(VERSION 3.24)
project(L5)

set(CMAKE_CXX_STANDARD 20)

add_executable(L5 main.cpp UI.cpp scooter.cpp repo.cpp controller.cpp)
