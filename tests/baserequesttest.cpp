#include "dota2api/baserequest.hpp"
#include "gtest/gtest.h"

class BaseRequestDerived : public dota2::BaseRequest
{
    public:
        BaseRequestDerived (dota2::BaseRequest::Query query)
        {
            this->query = query;
        };
};

TEST(BaseRequest, getQuery)
{
    dota2::BaseRequest::Query query{{"1", ""}, {"foo", "bar"}};
    EXPECT_EQ
        (
         BaseRequestDerived(query).getQuery(),
         query
        );
}
