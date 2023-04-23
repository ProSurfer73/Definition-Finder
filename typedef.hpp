#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP

#include <string>
#include <unordered_map>

#include "definitionScanner.hpp"

/**< deals with typedef inside source code. */
class Typedef
{
public:
    /** \brief detect and automatically add typedef definitions to its database.
     *
     * \param the source code we want to analyse.
     * \return the number of typedefs found and added.
     *
     */
    void analyseTypedef(const std::string& sourceCode);

    /** \brief transform a typedef name to its definition following the database registered.
     *
     * \param name of the unknown type (will be replaced by the new name contained in the database).
     * \return true if the transformation occured, false otherwise.
     *
     */
    bool transform(std::string& typeName) const;

    /** \brief get the number of typedef registered.
     *
     * \return the number of typedefs registered inside the database.
     *
     */
    size_t getSize() const;

    /** \brief let's print the database to std::cout (for debuging purposes).
     */
    void printAll() const;

private:
    /** \brief retrieve the keyword among source code.
     *
     * \param sourceCode the source code.
     * \param pos the position at which we want the type name to be retrieved.
     * \return the name of the type found.
     */
    std::string retrieveTypeName(const std::string& sourceCode, size_t& pos);

private:
    /**< the database containing types and their counterpart definitions */
    std::unordered_map<std::string,std::string> typedefs;
};



#endif // TYPEDEF_HPP
