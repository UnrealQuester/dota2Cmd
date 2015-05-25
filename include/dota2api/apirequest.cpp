#include "apirequest.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <curl/curl.h>

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

static size_t writeCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
        ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
}

std::string dota2::APIRequest::runRequest()
{
    std::string buffer;
    CURL* c;
    c = curl_easy_init();
    if(!c)
    {
        throw std::runtime_error("Unable to initialize curl");
    }
    curl_easy_setopt(c, CURLOPT_URL, url.c_str());
    curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(c, CURLOPT_WRITEDATA, &buffer);
    CURLcode res = curl_easy_perform(c);
    curl_easy_cleanup(c);
    if(res != CURLE_OK)
    {
        throw std::runtime_error(curl_easy_strerror(res));
    }
    return buffer;
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
