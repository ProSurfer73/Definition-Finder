/*
 * The point of this program is to find the definition of one or more elements inside a folder.
 *
 *
 */

#include <iostream>
#include <vector>

#include "files.hpp"
#include "scanner.hpp"


using namespace std;

int main()
{
    /// test procedure

    //std::cout << "test procedure:" << std::endl;

    // First comparison.
    //std::cout << "1. " << (DefinitionScanner::findStr("int  main", "int main")!=std::string::npos) << std::endl;


    /// main program

    // Welcoming message
    std::cout << "Welcome to definition searcher.\n" << std::endl;

    // User input related variables
    std::string userInput;
    std::vector<std::string> fileList;

    // Let's ask for directories
    do
    {
        std::cout << "Please type the name of a folder (or nothing to continue):" << std::endl;

        std::getline(std::cin, userInput);

        if(!userInput.empty())
        {
            if(!explore_directory(userInput, fileList))
                std::cout << "/!\\ Can't open the directory path provided /!\\" << std::endl;
        }

    }
    while(!userInput.empty());

    // If there is no file to scan, let's quit the program.
    if(fileList.empty())
        return 0;

    std::cout << "Now please type the definition you would like to find:" << std::endl;
    std::cout << "1. structure (struct keyword)." << std::endl;
    std::cout << "2. function definition." << std::endl;
    std::cout << "3. any type." << std::endl;

    do
    {
        // let's get input string fro: the user.
        getline(std::cin, userInput);

        //
        size_t (*pointer)(const std::string&, const std::string&) = nullptr;
        std::string typeName;

        if(userInput == "1")
        {
            // look for struct definition.
            pointer = &(DefinitionScanner::lookForStruct);

            std::cout << "Now please enter type name: ";
            std::getline(std::cin, typeName);
        }
        else if(userInput == "2")
        {
            // look for function definition.
            ///pointer = &(DefinitionScanner::lookForFunction);
        }
        else if(userInput == "3")
        {
            // look for any type, really.
        }
        else if(!userInput.empty())
        {
            // incorrect user input.
            std::cout << "incorrect input, please retry." << std::endl;
        }




        if(pointer != nullptr)
        {
            std::string fileBuffer;
            unsigned nbResults = 0;

            for(const std::string& filePath : fileList)
            {
                retrieveFileBuffer(fileBuffer, filePath);

                size_t y = (*pointer)(fileBuffer, typeName);

                if(y != std::string::npos)
                {
                    std::cout << filePath << std::endl;
                    ++nbResults;
                }
            }

            std::cout << nbResults << " results found." << std::endl;

        }


    }
    while(!userInput.empty());



    return 0;
}
