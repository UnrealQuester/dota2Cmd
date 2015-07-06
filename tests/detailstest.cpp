#include "dota2api/details.hpp"
#include "gtest/gtest.h"

TEST(DetailsRequest, filer)
{
    dota2::DetailsRequest request;

    request.id(12);
    auto query = request.getQuery();
    EXPECT_EQ
        (
            query["match_id"],
            "12"
        );
}
