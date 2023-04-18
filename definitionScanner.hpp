#ifndef DEFINITION_SCANNER_HPP
#define DEFINITION_SCANNER_HPP

#include <string>

class DefinitionScanner
{
public:
    static int lookForStruct(const std::string& sourceCode, const std::string& structName);

    static int lookForFunction();

};


#endif // DEFINITION_SCANNER_HPP
