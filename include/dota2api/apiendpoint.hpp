#ifndef APIENDPOINT_HPP_7PXYTQE5
#define APIENDPOINT_HPP_7PXYTQE5

namespace dota2
{
    template<typename Backend>
    class APIEndpoint
    {
        public:
            APIEndpoint(Backend backend) : backend(backend) { };

            template<typename Request>
            typename Request::obj query(const Request &request)
            {
                return backend.query(request);
            }

        protected:
            Backend backend;
    };
}

#endif /* end of include guard: APIENDPOINT_HPP_7PXYTQE5 */
