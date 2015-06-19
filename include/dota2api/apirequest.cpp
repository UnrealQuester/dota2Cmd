#include "apirequest.hpp"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <curl/curl.h>

dota2::APIRequest::APIRequest(const std::string &request, const std::string &key, const dota2::Query &query)
{
    url = std::string(API_SERVER) + "/" + request + "?key=" + key;
    for(auto q : query)
    {
        url+= "&" + q.first + "=" + urlEncode(q.second);
    }
    this->query = query;
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

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    ((std::string *)userp)->append((char *) contents, realsize);
    return realsize;
}

Json::Value dota2::APIRequest::runRequest()
{
    CURLcode res;
    CURL *curl = curl_easy_init();
    std::string responseBody;
    if(!curl)
    {
        throw std::runtime_error("failed to initialize curl");
    }
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBody);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    {
        curl_easy_cleanup(curl);
        throw std::runtime_error(curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
    Json::Value json;
    Json::Reader().parse(responseBody, json);
    return json;
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
