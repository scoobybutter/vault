cmake_minimum_required(VERSION 3.20)
project(vault)

set(CMAKE_CXX_STANDARD 14)


add_executable(HeapSort sorting/HeapSort.cpp)
add_executable(MergeSort sorting/MergeSort.cpp)
add_executable(Heap data-structures/Heap.cpp)