#ifndef STRINGS_HPP
#define STRINGS_HPP

#include <string>

/// useful functions related to string manipulation.

/** \brief remove all space related characters from a string.
 *
 * \param the string forçm which we want to remove all the space related characters.
 */
void clearSpaces(std::string& str);

/** \brief lower all the alpha characters of a given string.
 *
 * \param the string to be modified.
 */
void lowerString(std::string& str);

/** \brief replace a keyword to another inside a string.
 *
 * \param str the main string.
 * \param the initial keyword.
 * \param the final keyword.
 * \return true if the keyword was found and replaced, false otherwise.
 */
bool simpleReplace(std::string& str, const std::string& from, const std::string& to);

/** \brief check if a string has a specific ending.
 *
 * \param the full string.
 * \param the endind.
 * \return true if the full string has the string ending at its very end, false if it does not.
 */
bool hasEnding (std::string const &fullString, std::string const &ending);

/** \brief Checks if two strings are equal, case insensitively.
  * \param str1 the first string.
  * \param str2 the second string.
  * \return true if str1 equal str2 case insensitively, otherwise false.
  */
bool equalInsensitive(const std::string& str1, const std::string& str2);

#endif // STRINGS_HPP
