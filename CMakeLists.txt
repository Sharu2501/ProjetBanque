cmake_minimum_required(VERSION 3.29)
project(ProjetC__)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProjetC__
        source/Bank.cpp
        source/Account.cpp
        header/Bank.h
        header/Account.h
        Menu.cpp
)

target_include_directories(ProjetC__ PUBLIC source header)
