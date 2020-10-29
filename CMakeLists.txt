cmake_minimum_required(VERSION 3.14)
project(CS120Project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS120Project3 main.cpp Warrior.h Warrior.cpp Juggernaut.h Juggernaut.cpp Archer.h Archer.cpp Weapon.h Weapon.cpp Enemy.h Enemy.cpp Battle.h Battle.cpp)

add_executable(testing testing.cpp Warrior.h Warrior.cpp Juggernaut.h Juggernaut.cpp Archer.h Archer.cpp Weapon.h Weapon.cpp Enemy.h Enemy.cpp Battle.h Battle.cpp)