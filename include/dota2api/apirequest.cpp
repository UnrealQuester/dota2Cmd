#include "apirequest.hpp"
#include <sstream>
#include <iomanip>

dota2::APIRequest::APIRequest(std::string request, std::string key, dota2::Query query)
{
    url = std::string(API_SERVER) + "/" + request + "?key=" + key;
    for(auto q : query)
    {
        url+= "&" + q.first + "=" + urlEncode(q.second);
    }
}

std::string dota2::APIRequest::getUrl()
{
    return url;
}

std::string dota2::APIRequest::urlEncode(const std::string &value)
{
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (const auto& c : value) {

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << '%' << std::setw(2) << int((unsigned char) c);
    }

    return escaped.str();
}
