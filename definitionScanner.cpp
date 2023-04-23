#include <vector>

#include "definitionScanner.hpp"

void treatSpaces(std::string& str)
{
    // Let's remove non-essential space characters

    for(unsigned i=0; i<str.size(); i++)
    {

    }
}


/* /brief The goal of this function is to detect struct declaration keyword
 *        inside source code.
 *
 * /return the character number corresponding to the line in question.
 */
size_t DefinitionScanner::lookForStruct(const std::string& sourceCode, const std::string& structName)
{
    // 1. LETS TREAT THE SPACE (contained inside the string)




    // 2. LET'S TREAT "typedef struct" CASE

    std::vector<size_t> positions; // holds all the positions that sub occurs within str

    size_t pos = findStr(sourceCode, "typedef struct ");
    while(pos != std::string::npos)
    {
        positions.push_back(pos);
        pos = sourceCode.find("typedef struct",pos+1);
    }

    for(size_t pos : positions)
    {
        if(matchKeyword(sourceCode, structName, pos))
            return pos;
    }

    return std::string::npos;
}


size_t DefinitionScanner::findStr(const std::string& initialString, const std::string& strToFind, size_t startingFrom)
{
    // let's browse the two strings we want to compare.
    for(unsigned i=startingFrom,j=0; i<initialString.size() && j<strToFind.size(); ++i)
    {
        // if we encounter a space character on both sides.
        if(isspace(initialString[i]) && isspace(strToFind[j]))
        {
            // skip space character for both strings.
            while(isspace(initialString[i++]));
            while(isspace(initialString[j++]));
        }
        else if(initialString[i] != strToFind[j])
        {
            return false;
        }
        else
        {
            ++j;
        }
    }

    return true;
}

bool DefinitionScanner::matchKeyword(const std::string& initialString, const std::string& keyword, size_t startingFrom)
{
    for(unsigned i=0; i<keyword.size() && i+startingFrom<initialString.size(); ++i)
    {
        if(initialString[i+startingFrom] != keyword[i])
            return false;
    }
    return true;
}
