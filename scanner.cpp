#include <vector>
#include <ostream>

#include "scanner.hpp"

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
size_t DefinitionScanner::lookForStruct(const std::string& sourceCode, const std::string& structName, const Typedef& table)
{
    // 1. LETS TREAT THE SPACE (contained inside the string)




    // 2. LET'S TREAT "struct " CASE

    std::vector<size_t> positions; // holds all the positions that sub occurs within str

    size_t pos = findStr(sourceCode, "struct ");
    while(pos != std::string::npos)
    {
        positions.push_back(pos);
        pos = findStr(sourceCode,"struct ",pos+1);
    }

    for(size_t pos : positions)
    {
        size_t copyPos = pos;
        if(retrieveTypeName(sourceCode, pos) == structName)
            return copyPos;
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

std::string DefinitionScanner::retrieveTypeName(const std::string& sourceCode, size_t& pos)
{
    // this variable will contain the type name.
    std::string typeName;

    for(; pos<sourceCode.size(); ++pos)
    {
        // if the typename is contained inside the string.
        if(isspace(sourceCode[pos]) && !typeName.empty())
        {
            // if it is the keyword struct or class, it does not count.
            // we have to see the next keyword.
            if(typeName == "struct" || typeName == "class")
                typeName.clear();
            else
                break;
        }
        else if(!isspace(sourceCode[pos]))
        {
            typeName += sourceCode[pos];
        }
    }

    return typeName;
}

void DefinitionScanner::outputStructDef(const std::string& sourceCode, size_t characterNumber, std::ostream& stream)
{
    int nbOpened=0;

    for(unsigned i=characterNumber; i<sourceCode.size(); ++i)
    {
        stream << sourceCode[i];

        if(sourceCode[i] == '{')
            nbOpened++;
        else if(sourceCode[i] == '}')
            nbOpened--;

        if(sourceCode[i] == ';' && nbOpened <= 0)
            break;
    }

    stream << '\n';
}

