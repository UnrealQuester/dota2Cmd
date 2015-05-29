#include "apirequest.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <boost/network/protocol/http/client.hpp>
using namespace boost::network;
using namespace boost::network::http;

dota2::APIRequest::APIRequest(const std::string &request, const std::string &key, const dota2::Query &query)
{
    url = std::string(API_SERVER) + "/" + request + "?key=" + key;
    for(auto q : query)
    {
        url+= "&" + q.first + "=" + urlEncode(q.second);
    }
}

dota2::APIRequest::APIRequest(const std::string &url)
{
    setUrl(url);
}

std::string dota2::APIRequest::getUrl()
{
    return url;
}

void dota2::APIRequest::setUrl(const std::string &url)
{
    this->url = url;
}

std::string dota2::APIRequest::runRequest()
{
    client::request request(url);
    request << header("Connection", "close");
    client client;
    client::response response = client.get(request);
    return body(response);
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
