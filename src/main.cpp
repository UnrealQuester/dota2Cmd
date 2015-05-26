#include <iostream>
#include <map>
#include <stdexcept>
#include "dota2api/apirequest.hpp"

dota2::Query parseArguments(int argc, char *argv[])
{
    dota2::Query arguments;
    auto argumentException = std::runtime_error("Expected arguments in the form of --arg=value");
    for(int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        size_t pos = arg.find("--");
        if(pos != 0)
        {
            throw argumentException;
        }

        pos = arg.find('=');
        if(pos == std::string::npos)
        {
            throw argumentException;
        }
        auto key = arg.substr(2, pos - 2);
        auto value = arg.substr(pos + 1);
        arguments.insert({key, value});
    }
    return arguments;
}

int handleRequest(const std::string &query, const std::string &key, const dota2::Query &arguments)
{
    std::map<std::string, std::string> modes =
    {
        {"details", dota2::MATCHDETAILS_API},
        {"history", dota2::MATCHHISTORY_API},
        {"heroes" , dota2::HEROES_API},
        {"items"  , dota2::ITEMS_API},
    };
    auto mode = modes.find(query);
    if(mode == modes.end())
    {
        std::cerr << query << " is not a valid query. Valid values are" << std::endl;
        for(const auto &mode : modes)
        {
            std::cerr << "  " << mode.first << std::endl;
        }
        return EXIT_FAILURE;
    }
    dota2::APIRequest request(mode->second, key, arguments);
    std::cout << request.runRequest() << std::endl;
    return 0;
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cerr << "Expected query type" << std::endl;
        return EXIT_FAILURE;
    }
    dota2::Query arguments;
    try
    {
        auto args = parseArguments(argc - 2, argv + 2);
        arguments.insert(args.begin(), args.end());
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    auto keyIter = arguments.find("key");
    if(keyIter == arguments.end())
    {
        std::cerr << "Steam API key required" << std::endl;
        return EXIT_FAILURE;
    }
    std::string key = keyIter->second;
    return handleRequest(argv[1], key, arguments);
}
