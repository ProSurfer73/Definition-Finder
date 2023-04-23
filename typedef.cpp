#include <cctype>
#include <iostream>
#include "typedef.hpp"

void Typedef::analyseTypedef(const std::string& sourceCode)
{
    // let's start to search for the keyword at the begining of the file.
    size_t currentPosition = 0;

    // as long as we find another 'typedef ' keyword inside the source code.
    while( (currentPosition=DefinitionScanner::findStr(sourceCode, "typedef ", currentPosition)) != std::string::npos )
    {
        // let's move to the keyword.
        currentPosition += 8;

        // let's retrieve the 2 type names of the typedef.
        std::string firstType = retrieveTypeName(sourceCode, currentPosition);
        std::string secondType = retrieveTypeName(sourceCode, currentPosition);

        // let's register them into the database.
        typedefs.emplace(firstType, secondType);
    }
}


bool Typedef::transform(std::string& typeName) const
{
    // let's first count how much definitions there is for this type name.
    auto nbFound = typedefs.count(typeName);

    // If there are no definition or a numbre of definition > 1, then convertion is no possible.
    if(nbFound == 0 || nbFound > 1)
        return false;

    // If we are here, then the convertion is possible, let's convert it.
    typeName = (typedefs.find(typeName))->second;
    return true;
}


size_t Typedef::getSize() const
{
    // let's return the number of definitions contained inside the database.
    return typedefs.size();
}

std::string Typedef::retrieveTypeName(const std::string& sourceCode, size_t& pos)
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

void Typedef::printAll() const
{
    std::cout << "number of elements: " << getSize() << std::endl;

    for(const auto& p : typedefs)
    {
        std::cout << "1:" << p.first;
        std::cout << " 2:" << p.second << std::endl;
    }
}
