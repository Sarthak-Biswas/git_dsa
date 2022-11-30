cmake_minimum_required(VERSION 3.23)
project(git_dsa)

set(CMAKE_CXX_STANDARD 14)

add_executable(topological_sort graphs/dfs/topological_sort.cpp)
add_executable(bfs graphs/bfs/bfs.cpp)

add_executable(djikstras graphs/bfs/djikstras.cpp)