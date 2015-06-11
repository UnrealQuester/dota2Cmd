#ifndef HISTORY_HPP_BW780OCF
#define HISTORY_HPP_BW780OCF

#include <vector>

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
}

#endif /* end of include guard: HISTORY_HPP_BW780OCF */
