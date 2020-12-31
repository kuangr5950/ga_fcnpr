
#file(GLOB CPPFILES *.cpp)
#add_library(fcnpr SHARED ${CPPFILES} PandR_GA.h PandR_GA.cpp Astar.cpp)
#set_target_properties(fcnpr PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
#LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
#RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
#)
#target_link_libraries(fcnpr mockturtle)

file(GLOB CPPFILES *.cpp)
add_library(fcnpr SHARED ${CPPFILES})
set_target_properties(fcnpr PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
        #LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
        )
target_link_libraries(fcnpr mockturtle)
