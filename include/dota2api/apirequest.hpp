#include <string>
#include <map>

namespace dota2
{

    constexpr auto MATCHHISTORY_API = "IDOTA2Match_570/GetMatchHistory/V1/";
    constexpr auto MATCHDETAILS_API = "IDOTA2Match_570/GetMatchDetails/V1/";
    constexpr auto HEROES_API       = "IEconDOTA2_570/GetHeroes/V1/";
    constexpr auto ITEMS_API        = "IEconDOTA2_570/GetGameItems/V1/";
    constexpr auto API_SERVER       = "https://api.steampowered.com";

    typedef std::map<std::string, std::string> Query;
    class APIRequest
    {
        public:
            APIRequest(std::string request, std::string key, Query query = Query());
            std::string getUrl();
            std::string runRequest();

        private:
            static std::string urlEncode(const std::string &value);

            std::string url;
    };
}
