cmake_minimum_required(VERSION 2.8)
project(RDMM)

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
endif()

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

#aux_source_directory(source SOURCE_LIST)

file(GLOB SOURCE_LIST source/*.cpp)
file(GLOB HEADER_LIST source/*.h)

file(GLOB_RECURSE LI_SOURCE_LIST source/mylib/*.cpp source/mylib/*.h)

source_group("Header Files" FILES $(HEADER_LIST))
source_group("Source Files" FILES $(SOURCE_LIST))
source_group("MyLib Files" FILES $(LI_SOURCE_LIST))

add_executable(rdmm ${SOURCE_LIST} ${HEADER_LIST} ${LI_SOURCE_LIST})
target_link_libraries(rdmm ${OpenCV_LIBS})

project(RDM)
set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
endif()

#find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

#aux_source_directory(source SOURCE_LIST)

file(GLOB CPP_LIST src/*.cpp)
file(GLOB HPP_LIST src/*.h)

source_group("Header Files" FILES $(HPP_LIST))
source_group("Source Files" FILES $(CPP_LIST))

add_executable(rdm ${CPP_LIST} ${HPP_LIST})
target_link_libraries(rdm ${OpenCV_LIBS})