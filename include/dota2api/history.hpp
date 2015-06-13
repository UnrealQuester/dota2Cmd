#ifndef HISTORY_HPP_BW780OCF
#define HISTORY_HPP_BW780OCF

#include <vector>
#include <stdint.h>
#include <map>
#include <string>

namespace dota2
{
    using MatchID = int;
    class History
    {
        public:
            History(const std::vector<MatchID> &matchIDs);
            const std::vector<MatchID> &getMatchIDs() const;

        private:
            std::vector<MatchID> matchIDs;
    };

    enum GameMode {
        UNKNWOWN,
        ALL_PICK,
        CAPTAINS_MODE,
        RANDOM_DRAFT,
        SINGLE_DRAFT,
        ALL_RANDOM,
        INRO,
        DIRETIDE,
        REVERSE_CAPTAINS_MODE,
        GREEVILING,
        TUTORIAL,
        MID_ONLY,
        LEAST_PLAYED,
        NEW_PLAYER_POOL,
        COMPENDIUM_MATCHMAKING,
        CUSTOM,
        CAPTAINS_DRAFT,
        BALANCED_DRAFT,
        ABILITY_DRAFT,
        EVENT,
        ALL_RANDOM_DEATCH_MATCH,
        SOLO_MID,
    };

    enum SkillLevel {
        ANY,
        NORMAL,
        HIGH,
        VERY_HIGH,
    };

    class HistoryRequest
    {
        public:
            HistoryRequest &hero(int heroID);
            HistoryRequest &gameMode(GameMode gameMode);
            HistoryRequest &skillLevel(SkillLevel skillLevel);
            HistoryRequest &minPlayers(int minPlayerCount);
            HistoryRequest &account(uint64_t accountID);
            HistoryRequest &league(uint64_t leagueID);
            HistoryRequest &startAt(uint64_t matchID);
            HistoryRequest &matches(int numMatches);
            HistoryRequest &tournament(bool tournamentOnly);
            std::map<std::string, std::string> getQuery() const;

        private:
            std::map<std::string, std::string> query;
    };
}

#endif /* end of include guard: HISTORY_HPP_BW780OCF */
