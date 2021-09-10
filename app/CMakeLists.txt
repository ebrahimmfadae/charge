cmake_minimum_required(VERSION 3.13)

add_executable(app main.cpp)

# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtkmm-3.0)

target_include_directories(app PRIVATE ${GTK_INCLUDE_DIRS})
target_link_directories(app PRIVATE ${GTK_LIBRARY_DIRS})
target_link_libraries(app PRIVATE ${GTK_LIBRARIES})

# Add other flags to the compiler
add_definitions(${GTK_CFLAGS_OTHER})