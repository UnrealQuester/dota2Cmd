find_package(CURL)
add_library(dota2api dota2api/apirequest.cpp dota2api/history.cpp
    dota2api/baserequest.cpp dota2api/webendpoint.cpp dota2api/details.cpp
    dota2api/gamemode.cpp dota2api/player.cpp)
add_library(jsoncpp jsoncpp/jsoncpp.cpp)
target_link_libraries(dota2api ${CURL_LIBRARIES} jsoncpp)
include_directories(${CURL_INCLUDE_DIRS})
