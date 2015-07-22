#ifndef BUILDINGS_HPP_Q0KHXQGJ
#define BUILDINGS_HPP_Q0KHXQGJ

#include <bitset>

namespace dota2
{
    enum class Buildings
    {
        Top_Melee,
        Top_Ranged,
        Middle_Melee,
        Middle_Ranged,
        Bottom_Melee,
        Bottom_Ranged,
        Top_Tier_1,
        Top_Tier_2,
        Top_Tier_3,
        Middle_Tier_1,
        Middle_Tier_2,
        Middle_Tier_3,
        Bottom_Tier_1,
        Bottom_Tier_2,
        Bottom_Tier_3,
        Ancient_Bottom,
        Ancient_Top,
    };

    class BuildingStatus
    {
        public:
            using Status = std::bitset<17>;

            BuildingStatus()
            {
                buildingsStatus.set();
            }

            BuildingStatus(uint8_t barracksStatus, uint16_t towerStatus)
            {
                set(barracksStatus, towerStatus);
            }


            void set(uint8_t barracksStatus, uint16_t towerStatus)
            {
                buildingsStatus = Status (
                     (barracksStatus & 63)
                     | ((towerStatus & 2047) << 6)
                    );
            }

            bool get(Buildings building) const
            {
                return buildingsStatus[(int)building];
            }

            const Status& getStatus() const
            {
                return buildingsStatus;
            }

        private:

            Status buildingsStatus;
    };
}

#endif /* end of include guard: BUILDINGS_HPP_Q0KHXQGJ */
