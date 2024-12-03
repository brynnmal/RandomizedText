cmake_minimum_required(VERSION 3.29)
project(MakeSeuss)

set(CMAKE_CXX_STANDARD 20)

add_executable(MakeSeuss main.cpp hashNode.hpp hashNode.cpp hashMap.hpp hashMap.cpp makeSeuss.hpp makeSeuss.cpp)
