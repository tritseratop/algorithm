# CMakeList.txt : CMake project for sorting, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Include sub-projects.
add_subdirectory ("insertion_sort")
add_subdirectory ("quick_sort")
add_subdirectory ("merge_sort")

add_executable (test factorial.cpp)

# TODO: Add tests and install targets if needed.
