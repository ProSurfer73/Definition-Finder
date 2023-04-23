#ifndef FILES_HPP
#define FILES_HPP

#include <vector>
#include <string>

/** \brief gives the list of all the files that are a directory (and its subdirectories).
 *
 * \param the path to the directory.
 * \param the list of the files (with absolute path) are going to be pushed back into this array.
 * \return true if the directory was opened correctly, false if there was an error while opening it.
 *
 */
bool explore_directory(std::string dirname, std::vector<std::string>& files);

/** \brief read a file, and put all of its content into a string.
 *
 * \param buffer string buffer.
 * \param filePath path to the file in question.
 * \return true if the file was opened and read normally, false otherwise.
 */
bool retrieveFileBuffer(std::string& buffer, const std::string& filePath);

#endif // FILES_HPP
