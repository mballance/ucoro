
cmake_minimum_required(VERSION 3.11)
project(ucoro C CXX ASM)
#set_property(SOURCE foo.s APPEND PROPERTY COMPILE_OPTIONS "-x" "assembler-with-cpp")

include(ExternalProject)

if (NOT PACKAGES_DIR)
    set(PACKAGES_DIR ${CMAKE_SOURCE_DIR}/packages)

    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(src)