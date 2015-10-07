#include <iostream>
#include <algorithm>
#include "dota2api/apirequest.hpp"
#include "json/json.h"

const std::string indent1 = "    ";
const std::string indent2 = indent1 + indent1;
const std::string indent3 = indent2 + indent1;

std::string toUpper(std::string str)
{
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
    return str;
}

std::string toLower(std::string str)
{
    std::transform(str.begin(), str.end(),str.begin(), ::tolower);
    return str;
}

void print(std::initializer_list<std::string> const& args)
{
    for(const auto &arg : args)
    {
        std::cout << arg;
    }
    std::cout << std::endl;
}

namespace std
{
    std::string to_string(std::string s)
    {
        return s;
    }
}

template<class... Args>
void print(Args... args)
{
    print({std::to_string(args)...});
}

void generateConversionInt(std::string name, std::string displayName)
{
    std::string variableName = toLower(displayName);
    print(indent1, "inline ", displayName, " ", variableName, "FromInt(int ", variableName, ")");
    print(indent1, "{");
    print(indent2, "const auto iter = ", name, ".find(", variableName, ");");
    print(indent2, "if iter == ", name, ".end())");
    print(indent3, "return ", displayName, "::Unknown;");
    print(indent2, "return iter->second");
    print(indent1, "}");
}

void generateEnum(Json::Value json, std::string name, std::string displayName)
{
    std::map<int, std::string> enumItems;
    for(const auto& value : json["result"][name])
        enumItems[value["id"].asInt()] = value["localized_name"].asString();
    print("#ifndef ", toUpper(name), "_HPP_GENERATED");
    print("#define ", toUpper(name), "_HPP_GENERATED");
    print();
    print("#include <map>");
    print();
    print("namespace dota2");
    print("{");
    print(indent1, "enum class ", displayName);
    print(indent1, "{");
    print(indent2, "Unknown = 0,");
    for(const auto& value : enumItems)
    {
        print(indent2, value.second, " = ", value.first, ",");
    }
    print(indent1, "};");
    print();
    print(indent1, "const std::map<int, ", displayName, "> ", name, "({");
    for(const auto& value : enumItems)
    {
        print(indent2, "{", value.first, ", ", displayName, "::", value.second, "},");
    }
    print(indent1, "});");
    generateConversionInt(name, displayName);
    print("}");
    print("#endif");
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        std::cerr << "Expected query type and key" << std::endl;
        return EXIT_FAILURE;
    }
    std::string query = argv[1];
    std::string key = argv[2];
    std::string lang = "en_us";

    std::map<std::string, std::string> modes =
    {
        {"heroes" , dota2::HEROES_API},
        {"items"  , dota2::ITEMS_API},
    };
    std::map<std::string, std::string> classes =
    {
        {"heroes" , "Hero"},
        {"items"  , "Item"},
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
    dota2::APIRequest request(mode->second, key, {{std::string("language"), lang}});
    try
    {
        generateEnum(request.runRequest(), mode->first, classes[query]);
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return EXIT_SUCCESS;
}
