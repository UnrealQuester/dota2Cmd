include_directories(${dota2cmd_SOURCE_DIR}/include ${dota2cmd_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} dota2api)
