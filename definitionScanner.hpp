
#ifndef DEFINITION_SCANNER_HPP
#define DEFINITION_SCANNER_HPP

#include <string>

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
    static size_t lookForStruct(const std::string& sourceCode, const std::string& structName);

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

    /** \brief see if the given keyword exist at the exact position given.
     *
     * \param the big string we want to find our keyword.
     * \param the keyword we want to find.
     * \return true if the keyword is exactly at the position mentioned, false otherwise.
     *
     */
    static bool matchKeyword(const std::string& initialString, const std::string& keyword, size_t startingFrom);


};


#endif // DEFINITION_SCANNER_HPP
