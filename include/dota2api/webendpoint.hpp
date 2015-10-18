#ifndef WEBENDPOINT_HPP_LMF8SPBL
#define WEBENDPOINT_HPP_LMF8SPBL

#include <string>
#include "apiendpoint.hpp"
#include "baserequest.hpp"
#include "json/json.h"

namespace dota2
{
    class HistoryRequest;
    class History;
    class WebAPIBackend
    {
        public:
            WebAPIBackend(std::string key);

            History query(const HistoryRequest &request);

        protected:
            Json::Value _query(std::string        urlFragment,
                               const BaseRequest &reuqest);

        private:
            std::string key;
    };
    typedef APIEndpoint<WebAPIBackend> WebEndpoint;
} // namespace dota2

#endif /* end of include guard: WEBENDPOINT_HPP_LMF8SPBL */
