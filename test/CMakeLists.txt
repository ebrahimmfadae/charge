# /usr/include/boost
find_package(Boost 1.71 REQUIRED COMPONENTS unit_test_framework)

# creates the executable
add_executable(test solve_test.cpp)
# indicates the include paths
target_include_directories(test PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(test LINK_PUBLIC Charge)