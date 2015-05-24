#include <string>

namespace dota2
{

    constexpr auto MATCHHISTORY_API = "IDOTA2Match_570/GetMatchHistory/V1/";
    constexpr auto MATCHDETAILS_API = "IDOTA2Match_570/GetMatchDetails/V1/";
    constexpr auto HEROES_API       = "IEconDOTA2_570/GetHeroes/V1/";
    constexpr auto ITEMS_API        = "IEconDOTA2_570/GetGameItems/V1/";
    constexpr auto API_SERVER       = "https://api.steampowered.com";

    class APIRequest
    {
        public:
            APIRequest(std::string request, std::string key);
            std::string getUrl();

        private:
            std::string url;
    };
}
