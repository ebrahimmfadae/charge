# /usr/include/boost
find_package(Boost 1.71 REQUIRED COMPONENTS unit_test_framework)
add_executable(test charge_test.cpp)
target_include_directories(test PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(test LINK_PUBLIC Charge)