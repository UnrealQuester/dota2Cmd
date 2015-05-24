add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(testrunner test.cpp)
target_link_libraries(testrunner gtest gtest_main)
