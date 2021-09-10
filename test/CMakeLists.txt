add_executable(test main.cpp)

# Link Boost, SQLite, optimizer
find_package(Boost 1.71 REQUIRED COMPONENTS unit_test_framework)
target_include_directories(test PRIVATE ${BOOST_INCLUDE_DIRS})
target_link_libraries(test LINK_PUBLIC sqlite3 optimizer)