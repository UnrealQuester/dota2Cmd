find_package(CURL)
add_library(dota2api dota2api/apirequest.cpp dota2api/history.cpp
    dota2api/baserequest.cpp dota2api/webendpoint.cpp)
target_link_libraries(dota2api ${CURL_LIBRARIES})
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(dota2api)
