cmake_minimum_required( VERSION 3.16 ) 

project( 
  "Zephyr" VERSION 1.0 
  LANGUAGES C CXX 
  DESCRIPTION "Lightweight RPC framework" 
)


message("[SOURCEDIR]: ${CMAKE_SOURCE_DIR}")

set( CMAKE_EXPORT_COMPILE_COMMANDS TRUE ) 
set( "[EXPORT_COMPILE_COMMANDS]: " ${CMAKE_EXPORT_COMPILE_COMMANDS}) 

add_subdirectory( ${CMAKE_SOURCE_DIR}/lib/serialize )
add_subdirectory( ${CMAKE_SOURCE_DIR}/lib/server )
add_subdirectory( ${CMAKE_SOURCE_DIR}/lib/events )

add_executable( main ${CMAKE_SOURCE_DIR}/src/main.cpp )

target_link_libraries( main PUBLIC libserialize libserver libevents )



