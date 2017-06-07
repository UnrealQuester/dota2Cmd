find_package(CURL REQUIRED)
add_library(dota2::curl UNKNOWN IMPORTED)
set_target_properties(dota2::curl PROPERTIES
    IMPORTED_LOCATION "${CURL_LIBRARIES}"
    INTERFACE_INCLUDE_DIRECTORIES "${CURL_INCLUDE_DIRS}"
    )

add_library(dota2api dota2api/apirequest.cpp dota2api/history.cpp
    dota2api/baserequest.cpp dota2api/webendpoint.cpp dota2api/details.cpp
    dota2api/gamemode.cpp dota2api/player.cpp)
target_compile_features(dota2api PUBLIC cxx_std_11)
add_library(jsoncpp jsoncpp/jsoncpp.cpp)
target_compile_features(jsoncpp PUBLIC cxx_std_11)
target_link_libraries(dota2api dota2::curl jsoncpp)
