
#ifndef DEFINITION_SCANNER_HPP
#define DEFINITION_SCANNER_HPP

#include <string>

#include "typedef.hpp"
class Typedef;

/**< Function to search for definitions inside provided source code. */
class DefinitionScanner
{
public:
    /** \brief look for structure defintion inside provided source code.
     *
     * \param the source code (of a file for example)
     * \param the name of the structure we want to find.
     * \return std::string::npos if not found, or the character number at which it was found.
     *
     */
    static size_t lookForStruct(const std::string& sourceCode, const std::string& structName, const Typedef& table);

    /** \brief print the structure definition.
     *
     * \param sourceCode the source code in which the structure definition was found.
     * \param characterNumber the character number at which the definition was found.
     */
    static void outputStructDef(const std::string& sourceCode, size_t characterNumber, std::ostream& stream);


    /** \brief look for function definition inside source code.
     *
     * \param
     * \param
     * \return std::string::npos if not found, or the character number at which it was found.
     *
     */
    static int lookForFunction();

private:
    /** \brief find if a string exists in one another (while ignoring space characters that may exist).
     *
     * \param string in which we want to find another string.
     * \param the short srting we are looking for.
     * \return std::
     *
     */
    static size_t findStr(const std::string& initialString, const std::string& strToFind, size_t startingFrom=0);

    /** \brief retrieve the keyword among source code.
     *
     * \param sourceCode the source code.
     * \param pos the position at which we want the type name to be retrieved.
     * \return the name of the type found.
     */
    static std::string retrieveTypeName(const std::string& sourceCode, size_t& pos);

/**< the class Typedef has to access to the methods findStr and matchKeyword. */
friend class Typedef;
};


#endif // DEFINITION_SCANNER_HPP
