find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
add_library(dota2api dota2api/apirequest.cpp)
target_link_libraries(dota2api ${CURL_LIBRARIES})
