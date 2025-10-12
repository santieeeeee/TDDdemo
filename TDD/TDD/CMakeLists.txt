cmake_minimum_required(VERSION 3.14)
project(TDDproject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(TDDlib STATIC
  MathExpression.cpp
  MathExpression.h
)

add_executable(TDD
  main.cpp
)
target_link_libraries(TDD
  PRIVATE TDDlib
)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TDD PROPERTY CXX_STANDARD 20)
endif()

add_executable(TDDtests
  tests/test.cpp
)
target_link_libraries(TDDtests
  PRIVATE
    TDDlib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TDDtests)
