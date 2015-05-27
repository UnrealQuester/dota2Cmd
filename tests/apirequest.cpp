#include "dota2api/apirequest.hpp"
#include "gtest/gtest.h"

TEST(APIRequest, Init)
{
    dota2::APIRequest request(dota2::MATCHHISTORY_API, "key");
    EXPECT_EQ
        (
         request.getUrl(),
         "https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V1/?key=key"
        );
}

TEST(APIRequest, Query)
{
    dota2::Query query;
    query.insert({"hero_id", "1234"});
    dota2::APIRequest request(dota2::MATCHHISTORY_API, "key", query);
    EXPECT_EQ
        (
         request.getUrl(),
         "https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V1/?key=key&hero_id=1234"
        );

    query.insert({"name", "asdf"});
    request = dota2::APIRequest(dota2::MATCHHISTORY_API, "key", query);
    EXPECT_EQ
        (
         request.getUrl(),
         "https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V1/?key=key&hero_id=1234&name=asdf"
        );
}

TEST(APIRequest, Escaping)
{
    dota2::Query query;
    query.insert({"player_name", "foo bar"});
    dota2::APIRequest request(dota2::MATCHHISTORY_API, "key", query);
    EXPECT_EQ
        (
         request.getUrl(),
         "https://api.steampowered.com/IDOTA2Match_570/GetMatchHistory/V1/?key=key&player_name=foo%20bar"
        );
}

TEST(APIRequest, UrlConstructor)
{
    dota2::APIRequest request("foobar.com");
    EXPECT_EQ
        (
         request.getUrl(),
         "foobar.com"
        );
}

TEST(APIRequest, setUrl)
{
    dota2::APIRequest request("foobar.com");
    request.setUrl("barfoo.org");
    EXPECT_EQ
        (
         request.getUrl(),
         "barfoo.org"
        );
}

TEST(APIRequest, runRequestException)
{
    dota2::APIRequest request("failurl");
    EXPECT_THROW(request.runRequest(), std::exception);
}
