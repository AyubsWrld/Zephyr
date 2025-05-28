

add_library( libserialize STATIC z_serialize.cpp ) 
target_include_directories( libserialize PUBLIC ${CMAKE_SOURCE_DIR}/include/serialize )
