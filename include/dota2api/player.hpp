#ifndef PLAYER_HPP_OOWASTDI
#define PLAYER_HPP_OOWASTDI

#include "json/json-forwards.h"
#include "heroes.hpp"
#include "items.hpp"
#include <stdint.h>
#include <vector>

namespace dota2
{
    const uint32_t privateAccountID = 0xFFFFFFFF;
    class Player
    {
        public:
            Player() = default;
            Player(const Json::Value &);
            uint32_t getAccountID() const;
            unsigned int getKills() const;
            unsigned int getDeaths() const;
            unsigned int getAssists() const;
            unsigned int getNetWorth() const;
            unsigned int getExperiencePerMinute() const;
            unsigned int getGoldPerMinute() const;
            unsigned int getDenies() const;
            unsigned int getLastHits() const;
            unsigned int getLevel() const;
            Hero getHero() const;
            const std::vector<Item> &getItems() const;

        private:

            void readItems(const Json::Value &);
            uint32_t accountID = 0;
            unsigned int kills = 0;
            unsigned int deaths = 0;
            unsigned int assists = 0;
            unsigned int netWorth = 0;
            unsigned int experiencePerMinute = 0;
            unsigned int goldPerMinute = 0;
            unsigned int lastHits = 0;
            unsigned int denies = 0;
            unsigned int level = 0;
            Hero hero = Hero::Unknown;
            std::vector<Item> items;
    };
}

#endif /* end of include guard: PLAYER_HPP_OOWASTDI */
