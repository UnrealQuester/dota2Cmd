set(CPP-NETLIB_BUILD_TESTS OFF CACHE BOOL "Build the unit tests.")
set(CPP-NETLIB_BUILD_EXAMPLES OFF CACHE BOOL "Build the examples")
add_subdirectory(cppnetlib)
find_package(Threads)
find_package(cppnetlib REQUIRED)
find_package(Boost 1.54.0 REQUIRED system filesystem thread date_time chrono)
include_directories(${CPPNETLIB_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
add_library(dota2api dota2api/apirequest.cpp)
target_link_libraries(dota2api ${CPPNETLIB_LIBRARIES})
set(BOOST_CLIENT_LIBS
    ${Boost_THREAD_LIBRARY}
    ${Boost_DATE_TIME_LIBRARY}
    ${Boost_CHRONO_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY})
target_link_libraries(dota2api ${BOOST_CLIENT_LIBS} ${CMAKE_THREAD_LIBS_INIT})
