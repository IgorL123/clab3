cmake_minimum_required(VERSION 3.17)
project(clab3)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(CMAKE_CXX_STANDARD 20)
add_executable(clab3 main.cpp BST.hpp DynamicArray.hpp Set.hpp person.hpp)

enable_testing()
add_executable(
        bst_test
        Tests/bst_test.cpp
        Tests/set_test.cpp)
target_link_libraries(
        bst_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(bst_test)