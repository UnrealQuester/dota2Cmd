#include "apirequest.hpp"

dota2::APIRequest::APIRequest(std::string request, std::string key)
{
    url = std::string(API_SERVER) + "/" + request + "?key=" + key;
}

std::string dota2::APIRequest::getUrl()
{
    return url;
}
