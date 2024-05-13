#include <iostream>
#include <fstream>
#include "toDo.h"

// using namespace std;
using namespace toDoProject;

int main()
{
    // std::ifstream file;
    // file.ope("todo.txt", )
    int selection = -1;
    while(selection)
    {
        std::cout << "+++++Welcome to your to do list+++++\n" 
                "What would you like to do today?\n"
                "1. view to do list\n"
                "2. modify to do list\n"
                "3. delete to do list\n"
                "0 to exit\n"
                "Your choice: ";
        selection = getInt(0, 3);

        switch (selection)
        {
            case 1:
                viewList();
                break;
            case 2:
                modifyList();
                break;
            case 3:
                break;
        }
    }

    return 0;
}

// (check) have different to do lists
// support status for lists (class?)
// support correct numbering