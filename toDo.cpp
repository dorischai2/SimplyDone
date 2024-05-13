#include <fstream>
#include <iostream>
#include "toDo.h"

using namespace std;
namespace toDoProject {

    toDo& toDo::operator<<(std::fstream& f)
    {
        f.getline(status, 5);
        return *this;
    }

    int getInt(int min, int max)
    {
        int val = 0;
        cin >> val;
        while (cin.fail() || val < min || val > max)
        {
            cout << "Invalid integer input, try again: ";
            cin.clear();
            cin.ignore(12000, '\n'); //flush buffer
            cin >> val;
        }
        cin.ignore(12000, '\n');
        return val;
    }

    void getFileName(char* filename)
    {
        cout << "Enter the name of the to do list you wish to open\n"
                ": ";
        cin >> filename;
    }

    void viewList()
    {
        int numOfItems = 0;
        char filename[MAX_FILENAME_LEN]; 
        toDo* toDoList = nullptr;

        getFileName(filename);
        fstream file(filename, ios::in);

        if (file.is_open())
        {
            char line[100];
            if(file.peek() != EOF)
            {
                if (file >> numOfItems) //probably need some safeguard here
                {
                    
                }
                
                // toDoList = new toDo[numOfItems];
                cout << "\n*** Doris's To Do List ***" << endl;
                cout << "There are " << numOfItems << " of items\n";
                while (file.getline(line, 100))
                {
                    cout << line << endl;
                }
                cout <<"*** End of list ***\n"<< endl;
            }
            else
            {
                cout << "\nTo Do list is empty!\n" << endl;
            }
        }
        else
        {
            cout << "ERROR: unable to open file :(\n";
        }

        file.close();
    }

    void modifyList()
    {
        int selection = 0;
        ofstream file;
        cout << "How would you like to modify?\n" 
                "1. append\n"
                "2. overwrite\n"
                ": ";
        selection = getInt(1, 2);

        switch (selection)
        {
            case 1: 
                file.open("todo.txt", ios::app);
                break;
            case 2:
                file.open("todo.txt", ios::trunc);
                break;
        }

        if(file.is_open())
        {
            // file << "nice";
            int count = 0;
            char item[100];
            cout << "How many items would you add? (max 10)" << endl;
            count = getInt(1, 10);

            for (int i = 0; i < count; i++)
            {
                cout << "Enter your #" << i + 1 << " item: " << endl;
                cin.getline(item, 100, '\n'); //>> item;
                // cin.ignore(100, '\n');
                file << i + 1 << ". " << item << endl;
            }

        }
        file.close();
    }
}