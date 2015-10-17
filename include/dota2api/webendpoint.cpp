#include "webendpoint.hpp"
#include "history.hpp"
#include "apirequest.hpp"

dota2::WebAPIBackend::WebAPIBackend(std::string key) :
    key(key) { }

dota2::History dota2::WebAPIBackend::query(const dota2::HistoryRequest &request)
{
    return _query(dota2::MATCHHISTORY_API, request);
}

Json::Value dota2::WebAPIBackend::_query(std::string        urlFragment,
                                         const BaseRequest &request)
{
    dota2::APIRequest apiRequest(urlFragment, key, request.getQuery());

    return apiRequest.runRequest();
}

