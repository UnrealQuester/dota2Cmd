#include "details.hpp"

dota2::DetailsRequest &dota2::DetailsRequest::id(MatchID id)
{
    query.insert({"match_id", std::to_string(id)});
    return *this;
}
