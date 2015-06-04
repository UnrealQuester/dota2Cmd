cmake_minimum_required(VERSION 2.8.3)
project(dota2cmd)
set(PROJECT_NAME dota2cmd)
include(CheckCXXCompilerFlag)
if(UNIX)
    set(BUILD_SHARED_LIBS ON)
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no
        C++11 support. Please use a different C++ compiler.")
    endif()
else()
    set(BUILD_SHARED_LIBS OFF)
endif()
if (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0501)
endif(WIN32)

if(BUILD_SHARED_LIBS)
    set(Boost_USE_STATIC_LIBS OFF)
else()
    set(Boost_USE_STATIC_LIBS ON)
endif()
find_package(Boost 1.54.0 REQUIRED system filesystem thread date_time chrono
    regex)
set(BOOST_CLIENT_LIBS
    ${Boost_THREAD_LIBRARY}
    ${Boost_REGEX_LIBRARY}
    ${Boost_DATE_TIME_LIBRARY}
    ${Boost_CHRONO_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY})
include_directories(${Boost_INCLUDE_DIRS})

set(CPP-NETLIB_BUILD_TESTS OFF CACHE BOOL "Build the unit tests.")
set(CPP-NETLIB_BUILD_EXAMPLES OFF CACHE BOOL "Build the examples")
add_subdirectory(include/cppnetlib)
find_package(cppnetlib REQUIRED)
include_directories(${CPPNETLIB_INCLUDE_DIRS})

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)
enable_testing()
add_test(NAME UnitTests COMMAND testrunner)
