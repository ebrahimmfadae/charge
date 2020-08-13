cmake_minimum_required(VERSION 3.13)
project (charge)
include_directories(src)
set(SOURCES 
    src/main.cpp 
    src/models/Alloymaker.cpp
    src/models/Chemical.cpp
    src/models/Composition.cpp
    src/models/Standard.cpp
    src/optimizer/Variable.cpp
)
add_library(lpsolve SHARED IMPORTED)
set_target_properties(lpsolve PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/src/lpsolve/liblpsolve55.so
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/src/lpsolve
)
add_executable(charge ${SOURCES})
target_link_libraries(charge lpsolve)