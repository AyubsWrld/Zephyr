
add_library( libserver STATIC server_init.cpp ) 
target_include_directories( libserver PUBLIC ${CMAKE_SOURCE_DIR}/include/server PUBLIC ${CMAKE_SOURCE_DIR}/include/events )
