#include "dota2api/history.hpp"
#include "gtest/gtest.h"

TEST(History, getMatchIDs)
{
    dota2::History h({});
    EXPECT_EQ
        (
         h.getMatchIDs(),
         std::vector<dota2::MatchID>()
        );
}
