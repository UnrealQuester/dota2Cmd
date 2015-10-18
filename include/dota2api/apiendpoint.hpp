#ifndef APIENDPOINT_HPP_7PXYTQE5
#define APIENDPOINT_HPP_7PXYTQE5
#include <utility>

namespace dota2
{
    template<typename Backend>
    class APIEndpoint
    {
        public:
            template<typename T>
            APIEndpoint(T &&backend) :
                backend(std::forward<T>(backend)) { }

            template<typename Request>
            typename Request::obj query(const Request &request)
            {
                return backend.query(request);
            }

        protected:
            Backend backend;
    };
} // namespace dota2

#endif /* end of include guard: APIENDPOINT_HPP_7PXYTQE5 */
