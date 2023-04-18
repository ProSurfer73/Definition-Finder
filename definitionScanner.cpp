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
int DefinitionScanner::lookForStruct(const std::string& sourceCode, const std::string& structName)
{
    // 1. LETS TREAT THE SPACE (contained inside the string)




    // 2. LET'S TREAT "typedef struct" CASE

    std::vector<size_t> positions; // holds all the positions that sub occurs within str

    size_t pos = sourceCode.find("typedef struct", 0);
    while(pos != std::string::npos)
    {
        positions.push_back(pos);
        pos = sourceCode.find("typedef struct",pos+1);


    }
}
