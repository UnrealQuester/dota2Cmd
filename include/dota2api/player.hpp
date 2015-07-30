#ifndef PLAYER_HPP_OOWASTDI
#define PLAYER_HPP_OOWASTDI

#include "json/json-forwards.h"
#include <stdint.h>

namespace dota2
{
    const uint32_t privateAccountID = 0xFFFFFFFF;
    class Player
    {
        public:
            Player() = default;
            Player(const Json::Value &);
            uint32_t getAccountID();

        private:
            uint32_t accountID = 0;
    };
}

#endif /* end of include guard: PLAYER_HPP_OOWASTDI */
