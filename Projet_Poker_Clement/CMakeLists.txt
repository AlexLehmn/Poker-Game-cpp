cmake_minimum_required(VERSION 3.21)
project(Projet_Thune)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Projet_Thune
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        main.cpp
        Poker.cpp
        Poker.h)
