#****************************************************************************
#* CMakeLists.txt
#*
#* Unit tests
#****************************************************************************

ExternalProject_Add(GTEST
    PREFIX gtest
    SOURCE_DIR "${PACKAGES_DIR}/gtest"
    CMAKE_CACHE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/gtest
        -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}

    )

file(GLOB TEST_SRCS "*.cpp" "*.h")

add_executable(ucoro_tests ${TEST_SRCS})    
add_dependencies(ucoro_tests GTEST
)
target_include_directories(ucoro_tests PRIVATE
    ${CMAKE_BINARY_DIR}/gtest/include
    ${CMAKE_SOURCE_DIR}/src/include
    )

target_link_directories(ucoro_tests PRIVATE
    ${CMAKE_BINARY_DIR}/gtest/lib
    ${CMAKE_BINARY_DIR}/gtest/lib64
    )

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Taking debug libs")
    list(APPEND TEST_LIBS ucoro gtestd gtest_maind)
else()
    message(STATUS "Taking release libs")
    list(APPEND TEST_LIBS ucoro gtest gtest_main)
endif()

target_link_libraries(ucoro_tests ${TEST_LIBS} pthread)
