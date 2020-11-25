cmake_minimum_required(VERSION 3.8)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_DEBUG_POSTFIX "-d")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

project(ray)

add_subdirectory(src/raycore)
add_subdirectory(src/ray)
