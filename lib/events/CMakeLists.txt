
add_library( libevents STATIC events.cpp ) 
target_include_directories( libevents PUBLIC ${CMAKE_SOURCE_DIR}/include/events )
