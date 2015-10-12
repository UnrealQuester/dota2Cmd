add_executable(${PROJECT_NAME} main.cpp)
add_executable(enum_generator enum_generator.cpp)
target_link_libraries(${PROJECT_NAME} dota2api)
target_link_libraries(enum_generator dota2api)
