set(SOURCES 
    models/Alloymaker.cpp
    models/Chemical.cpp
    models/Composition.cpp
    models/Standard.cpp
    solver/Variable.cpp
    solver/Solution.cpp
)
add_library(optimizer STATIC ${SOURCES})

# Link Lpsolve
set(LPSOLVE_DIR ${CMAKE_SOURCE_DIR}/optimizer/libs/lpsolve)
target_include_directories(optimizer PRIVATE ${CMAKE_SOURCE_DIR}/optimizer/libs)
add_library(lpsolve SHARED IMPORTED)
set_target_properties(lpsolve PROPERTIES
    IMPORTED_LOCATION ${LPSOLVE_DIR}/liblpsolve55.so
    INTERFACE_INCLUDE_DIRECTORIES ${LPSOLVE_DIR}
)
target_link_libraries(optimizer PRIVATE lpsolve)