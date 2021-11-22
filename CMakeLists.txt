cmake_minimum_required(VERSION 3.0)
 
project(main)
 
SET(CMAKE_BUILD_TYPE "Release")
set( CMAKE_CXX_FLAGS "-std=c++11" )

find_package( OpenCV 3 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
 
add_executable(main src/ipm_tran.cpp)
 
target_link_libraries( main ${OpenCV_LIBS} )

