# Find Lpsolve
set(LPSOLVE_DIR ${CMAKE_SOURCE_DIR}/core/libs/lpsolve)
add_library(lpsolve SHARED IMPORTED)
set_target_properties(lpsolve PROPERTIES
    IMPORTED_LOCATION ${LPSOLVE_DIR}/liblpsolve55.so
    INTERFACE_INCLUDE_DIRECTORIES ${LPSOLVE_DIR}
)

# Link Lpsolve
set(SOURCES 
    models/Alloymaker.cpp
    models/Chemical.cpp
    models/Composition.cpp
    models/Standard.cpp
    optimization/Variable.cpp
    optimization/Solution.cpp
)
add_library(core STATIC ${SOURCES})
target_include_directories(core PRIVATE ${CMAKE_SOURCE_DIR}/core/libs)
target_link_libraries(core PRIVATE lpsolve)