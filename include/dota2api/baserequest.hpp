#ifndef BASEREQUEST_HPP_QQ0GJW3K
#define BASEREQUEST_HPP_QQ0GJW3K

#include <map>
#include <string>

namespace dota2
{
    class BaseRequest
    {
        public:
            typedef std::map<std::string, std::string> Query;
            Query getQuery() const;

        protected:
            Query query;
            BaseRequest() {  };
    };
}

#endif /* end of include guard: BASEREQUEST_HPP_QQ0GJW3K */
