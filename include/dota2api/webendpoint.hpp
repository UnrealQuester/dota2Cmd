#ifndef WEBENDPOINT_HPP_LMF8SPBL
#define WEBENDPOINT_HPP_LMF8SPBL

#include <string>
#include "apiendpoint.hpp"
#include "baserequest.hpp"

namespace dota2
{
    class HistoryRequest;
    class WebAPIBackend
    {
        public:
            WebAPIBackend(std::string key);

            std::string query(const HistoryRequest &request);

        protected:
            std::string _query(std::string urlFragment, const BaseRequest &reuqest);

        private:
            std::string key;
    };
    typedef APIEndpoint<WebAPIBackend> WebEndpoint;
}

#endif /* end of include guard: WEBENDPOINT_HPP_LMF8SPBL */
