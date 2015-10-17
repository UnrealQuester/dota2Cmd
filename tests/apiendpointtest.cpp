#include "dota2api/apiendpoint.hpp"
#include "gtest/gtest.h"

class DummyObj
{
    public:
        int i;
        DummyObj(int i)
        {
            this->i = i;
        }
};

class DummyRequest
{
    public:
        using obj = DummyObj;
        DummyRequest(int request) :
            request(request) {  }

        int request;
};

class DummyBackend
{
    public:
        DummyBackend(int mult) :
            mult(mult) { }

        int query(DummyRequest req)
        {
            return req.request * mult;
        }

    private:
        int mult;
};

TEST(APIEndpoint, Query)
{
    // The Endpoint should run the request through its backend and
    // return the resulting object
    dota2::APIEndpoint<DummyBackend> endpoint((DummyBackend(2)));

    EXPECT_EQ(endpoint.query(DummyRequest(3)).i, 6);
}
