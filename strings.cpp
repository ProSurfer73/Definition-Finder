#include <algorithm>
#include "strings.hpp"

void lowerString(std::string& str)
{
    for(unsigned i=0;i<str.size();++i)
        str[i] = std::tolower(str[i]);
}

void clearSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

bool simpleReplace(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

bool hasEnding (std::string const &fullString, std::string const &ending)
{
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

// Let's check if the two strings ar eequal or not.
// we consider the characters to be case insensitive.
bool equalInsensitive(const std::string& str1, const std::string& str2)
{
    bool sameString = true;

    for(unsigned i=0; i<str1.size(); ++i)
    {
        if(toupper(str1[i])!=toupper(str2[i]))
            sameString = false;
    }

    return sameString;
}
