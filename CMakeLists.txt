cmake_minimum_required(VERSION 2.8.9)
project (charge)
include_directories(src/models src/build-model)
set( SOURCES 
    src/main.cpp 
    src/models/Alloymaker.cpp 
    src/models/Composition.cpp
    src/models/CompositionCollection.cpp
    src/models/Uncountable.cpp
)
add_executable(charge ${SOURCES})