#ifndef DETAILS_HPP_MJPFIVFI
#define DETAILS_HPP_MJPFIVFI

#include "baserequest.hpp"
#include "json/json-forwards.h"
#include "history.hpp"

namespace dota2
{
    class Details
    {
        public:
            Details(const Json::Value &json);
    };

    class DetailsRequest : public BaseRequest
    {
        public:
            typedef Details obj;

            DetailsRequest &id(MatchID id);
    };
}

#endif /* end of include guard: DETAILS_HPP_MJPFIVFI */
