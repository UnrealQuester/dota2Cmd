#ifndef HISTORY_HPP_BW780OCF
#define HISTORY_HPP_BW780OCF

#include <vector>
#include <stdint.h>
#include "baserequest.hpp"
#include "json/json-forwards.h"
#include "gamemode.hpp"

namespace dota2
{
    using MatchID = int;
    class History
    {
        public:
            History(const std::vector<MatchID> &matchIDs);
            History(const Json::Value &json);
            const std::vector<MatchID> &getMatchIDs() const;

        private:
            std::vector<MatchID> matchIDs;
    };

    enum SkillLevel
    {
        ANY,
        NORMAL,
        HIGH,
        VERY_HIGH,
    };

    class HistoryRequest : public BaseRequest
    {
        public:
            typedef History obj;

            HistoryRequest &hero(int heroID);
            HistoryRequest &gameMode(GameMode gameMode);
            HistoryRequest &skillLevel(SkillLevel skillLevel);
            HistoryRequest &minPlayers(int minPlayerCount);
            HistoryRequest &account(uint64_t accountID);
            HistoryRequest &league(uint64_t leagueID);
            HistoryRequest &startAt(uint64_t matchID);
            HistoryRequest &matches(int numMatches);
            HistoryRequest &tournament(bool tournamentOnly);
    };
} // namespace dota2

#endif /* end of include guard: HISTORY_HPP_BW780OCF */
