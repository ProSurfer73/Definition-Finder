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
        std::string firstType = DefinitionScanner::retrieveTypeName(sourceCode, currentPosition);
        std::string secondType = DefinitionScanner::retrieveTypeName(sourceCode, currentPosition);

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

void Typedef::printAll() const
{
    std::cout << "number of elements: " << getSize() << std::endl;

    for(const auto& p : typedefs)
    {
        std::cout << "1:" << p.first;
        std::cout << " 2:" << p.second << std::endl;
    }
}
