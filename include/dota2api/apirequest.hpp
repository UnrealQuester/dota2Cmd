#include <string>
#include <map>

namespace dota2
{

    const auto MATCHHISTORY_API = "IDOTA2Match_570/GetMatchHistory/V1/";
    const auto MATCHDETAILS_API = "IDOTA2Match_570/GetMatchDetails/V1/";
    const auto HEROES_API       = "IEconDOTA2_570/GetHeroes/V1/";
    const auto ITEMS_API        = "IEconDOTA2_570/GetGameItems/V1/";
    const auto API_SERVER       = "https://api.steampowered.com";

    typedef std::map<std::string, std::string> Query;
    class APIRequest
    {
        public:
            APIRequest(const std::string &request, const std::string &key, const Query &query = Query());
            APIRequest(const std::string &url);
            void setUrl(const std::string &url);
            std::string getUrl();
            std::string runRequest();

        private:
            static std::string urlEncode(const std::string &value);

            std::string url;
    };
}
