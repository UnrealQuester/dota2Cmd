#ifndef DETAILS_HPP_MJPFIVFI
#define DETAILS_HPP_MJPFIVFI

#include "baserequest.hpp"
#include "json/json-forwards.h"
#include "history.hpp"
#include "team.hpp"
#include "buildings.hpp"
#include <chrono>

namespace dota2
{
    class Details
    {
        public:
            using timePoint = std::chrono::seconds;

            Details(const Json::Value &json);
            MatchID getMatchID() const;
            Team getWinningTeam() const;
            timePoint getStartTime() const;
            timePoint getFirstBloodTime() const;
            const BuildingStatus& getBuildingsStatusDire() const;
            const BuildingStatus& getBuildingsStatusRadiant() const;

        private:

            MatchID matchID;
            Team winningTeam;
            timePoint startTime;
            timePoint firstBloodTime;
            BuildingStatus buildingStatusDire;
            BuildingStatus buildingStatusRadiant;
    };

    class DetailsRequest : public BaseRequest
    {
        public:
            typedef Details obj;

            DetailsRequest &id(MatchID id);
    };
}

#endif /* end of include guard: DETAILS_HPP_MJPFIVFI */
