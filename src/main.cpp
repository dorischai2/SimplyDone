#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include "toDo.h"

// alias for this namespace
namespace fs = std::filesystem;
using namespace toDoProject;

int main()
{
    fs::path toDoDir = fs::path("..") / "toDoLists";
    std::vector<std::string> toDoFiles;

    // get list of to do lists in the current directory
    for (const auto& file : fs::directory_iterator(toDoDir)) {
        if (file.is_regular_file() && file.path().extension() == ".csv") {
            toDoFiles.push_back(file.path().filename().string());
        }
    }

    int selection = -1;
    while(selection)
    {
        std::cout << "+++++ Welcome to SimplyDone! Hope you have a productive day :) +++++\n\n" 
                     "Here's a list of to-do lists on record: \n";
        for (int i = 0; i < toDoFiles.size(); ++i) {
            std::cout << "  " << i + 1 << ". " << toDoFiles[i] << std::endl;
        }
        std::cout << "Which one would you like to view or modify? \n";
        std::cout << " > ";
        selection = getInt(0, toDoFiles.size());
        std::string fileName = toDoFiles[selection - 1];
        
        std::cout << "You chose file: " << fileName << std::endl;

        // exit early for testing purpose
        selection = 0;
        
    //             "What would you like to do today?\n"
    //             "1. view to do list\n"
    //             "2. modify to do list\n"
    //             "3. delete to do list\n"
    //             "0 to exit\n"
    //             "Your choice: ";
    //     selection = getInt(0, 3);

    //     switch (selection)
    //     {
    //         case 1:
    //             viewList();
    //             break;
    //         case 2:
    //             modifyList();
    //             break;
    //         case 3:
    //             break;
    //     }
    }

    return 0;
}
