#include "dota2api/apirequest.hpp"
#include "gtest/gtest.h"

TEST(APIRequest, Init) {
    dota2::APIRequest request(dota2::MATCHHISTORY_API, "key");
    EXPECT_EQ(request.getUrl(), "https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V1/?key=key");
}
