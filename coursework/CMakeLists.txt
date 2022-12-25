project(Program)
set(CMAKE_CXX_STANDART 17)

find_library(LIB_PQXX pqxx)
find_library(LIB_PQ pq)

add_executable(main main.cpp)

target_link_libraries(main ${LIB_PQXX} ${LIB_PQ})