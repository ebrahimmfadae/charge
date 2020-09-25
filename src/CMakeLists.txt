cmake_minimum_required(VERSION 3.13)
include_directories(${CMAKE_SOURCE_DIR}/lib)
set(SOURCES 
    models/Alloymaker.cpp
    models/Chemical.cpp
    models/Composition.cpp
    models/Standard.cpp
    optimizer/Variable.cpp
    optimizer/Solution.cpp
)
set(LPSOLVE_DIR ${CMAKE_SOURCE_DIR}/lib/lpsolve)
add_library(lpsolve SHARED IMPORTED)
set_target_properties(lpsolve PROPERTIES
    IMPORTED_LOCATION ${LPSOLVE_DIR}/liblpsolve55.so
    INTERFACE_INCLUDE_DIRECTORIES ${LPSOLVE_DIR}
)
add_library(Charge STATIC ${SOURCES})
target_link_libraries(Charge PRIVATE lpsolve)