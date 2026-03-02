cmake_minimum_required(VERSION 4.1)
project(little_library VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(llib INTERFACE)
target_include_directories(llib INTERFACE llib llib/containers llib/util)

add_executable(test_all)
target_sources(test_all PRIVATE test/main.cxx)
