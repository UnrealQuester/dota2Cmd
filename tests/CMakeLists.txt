if(MSVC AND NOT BUILD_SHARED_LIBS)
    set(gtest_force_shared_crt ON CACHE BOOL "Force gtest to build with shared run-time")
endif()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(testrunner apirequest.cpp apiendpointtest.cpp historytest.cpp
    baserequesttest.cpp detailstest.cpp buildingstest.cpp)
target_link_libraries(testrunner gtest gtest_main dota2api)
