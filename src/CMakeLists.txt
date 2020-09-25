cmake_minimum_required(VERSION 3.13)
# link lpsolve library
set(LPSOLVE_DIR ${CMAKE_SOURCE_DIR}/libs/lpsolve)
include_directories(${CMAKE_SOURCE_DIR}/libs)
add_library(lpsolve SHARED IMPORTED)
set_target_properties(lpsolve PROPERTIES
    IMPORTED_LOCATION ${LPSOLVE_DIR}/liblpsolve55.so
    INTERFACE_INCLUDE_DIRECTORIES ${LPSOLVE_DIR}
)
#
set(SOURCES 
    models/Alloymaker.cpp
    models/Chemical.cpp
    models/Composition.cpp
    models/Standard.cpp
    optimizer/Variable.cpp
    optimizer/Solution.cpp
)
add_library(Charge STATIC ${SOURCES})
target_link_libraries(Charge PRIVATE lpsolve)