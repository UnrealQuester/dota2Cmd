#include <iostream>
#include <algorithm>
#include <set>
#include "dota2api/apirequest.hpp"
#include "json/json.h"

const std::string indent1 = "    ";
const std::string indent2 = indent1 + indent1;
const std::string indent3 = indent2 + indent1;

struct EnumItem
{
    std::string name;
    std::string localizedName;
    int id;

    EnumItem(std::string name, std::string localizedName, int id) :
        name(name), localizedName(localizedName), id(id) {};

    bool operator <(const EnumItem &item) const
    {
        return id < item.id;
    }
};
typedef std::set<EnumItem> EnumItems;

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

std::string toEnumName(std::string str)
{
    auto replace = [](char c) { return c == ' ' || c == '-'; };
    std::replace_if(str.begin(), str.end(), replace, '_');
    auto invalid = [](char c) {return c != '_' && !isalpha(c);};
    str.erase(std::remove_if(str.begin(), str.end(), invalid), str.end());
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
    print(indent2, "if(iter == ", name, ".end())");
    print(indent3, "return ", displayName, "::Unknown;");
    print(indent2, "return iter->second;");
    print(indent1, "}");
}

void generateIntMap(const EnumItems &enumItems, std::string name, std::string displayName)
{
    print(indent1, "const std::map<int, ", displayName, "> ", name, "({");
    for(const auto& value : enumItems)
    {
        print(indent2, "{", "(int)", displayName, "::", value.name, ",", displayName, "::", value.name, "},");
    }
    print(indent1, "});");
}

void generateHeader(std::string name)
{
    print("#ifndef ", toUpper(name), "_HPP_GENERATED");
    print("#define ", toUpper(name), "_HPP_GENERATED");
    print();
    print("#include <map>");
}

void generateEnumClass(const EnumItems &enumItems, std::string displayName)
{
    print(indent1, "enum class ", displayName);
    print(indent1, "{");
    for(const auto& value : enumItems)
    {
        print(indent2, value.name, " = ", value.id, ",");
    }
    print(indent1, "};");
}

void generateEnum(Json::Value json, std::string name, std::string displayName)
{
    EnumItems enumItems;
    enumItems.emplace("Unknown", "Unknown", 0);
    std::map<std::string, int> names;

    for(const auto& value : json["result"][name])
    {
        auto localizedName = value["localized_name"].asString();
        auto name = toEnumName(localizedName);
        auto &nameCount = names[name];
        if(nameCount++)
            name += std::to_string(nameCount);
        enumItems.emplace(name, localizedName, value["id"].asInt());
    }

    generateHeader(name);
    print();
    print("namespace dota2");
    print("{");
    generateEnumClass(enumItems, displayName);
    print();
    generateIntMap(enumItems, name, displayName);
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
