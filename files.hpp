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



#endif // FILES_HPP
