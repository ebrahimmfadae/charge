cmake_minimum_required(VERSION 3.13)
project (charge)
include_directories(src lib)
set(SOURCES 
    src/main.cpp
    src/models/Alloymaker.cpp
    src/models/Alloymaker.h
    src/models/Chemical.cpp
    src/models/Chemical.h
    src/models/Composition.cpp
    src/models/Composition.h
    src/models/Standard.cpp
    src/models/Standard.h
    src/optimizer/Variable.cpp
    src/optimizer/Variable.h
    src/optimizer/Solution.cpp
    src/optimizer/Solution.h
)
set(LPSOLVE_DIR ${CMAKE_SOURCE_DIR}/lib/lpsolve)
add_library(lpsolve SHARED IMPORTED)
set_target_properties(lpsolve PROPERTIES
    IMPORTED_LOCATION ${LPSOLVE_DIR}/liblpsolve55.so
    INTERFACE_INCLUDE_DIRECTORIES ${LPSOLVE_DIR}
)
add_executable(charge ${SOURCES})
target_link_libraries(charge lpsolve)