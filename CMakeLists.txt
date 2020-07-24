cmake_minimum_required(VERSION 2.8.9)
project (charge)
set( SOURCES 
    src/main.cpp 
    src/model/Alloymaker.cpp 
    src/model/Composition.cpp
    src/model/CompositionCollection.cpp
    src/model/Uncountable.cpp
)
add_executable(charge ${SOURCES})