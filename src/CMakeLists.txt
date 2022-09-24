

list(APPEND ucoro_SRC ucoro.c)
list(APPEND ucoro_SRC ucoro_x86_64.S)

message(STATUS "ucoro_SRC ${ucoro_SRC}")
add_library(ucoro ${ucoro_SRC})