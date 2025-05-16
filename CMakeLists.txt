cmake_minimum_required( VERSION 3.16 ) 

project( 
  "Zephyr" VERSION 1.0 
  LANGUAGES C CXX 
  DESCRIPTION "Lightweight RPC framework" 
)


message("[SOURCEDIR]: ${CMAKE_SOURCE_DIR}")

add_executable( main ${CMAKE_SOURCE_DIR}/src/main.cpp )



