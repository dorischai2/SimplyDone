#include <fstream>

namespace toDoProject{
    const int MAX_ITEM_LEN = 100;
    const int MAX_FILENAME_LEN = 50;
    struct toDo //struct instead of class because access is required for operators
    {
        char status[5];
        char item[MAX_ITEM_LEN];

        toDo& operator<<(std::fstream& f);
    };
    //Return a int within given range
    int getInt(int min, int max);

    //Display content of the to do list
    void viewList();

    //Ask user for file name input
    void getFileName(char* filename);

    //Modify the content of the to do list
    void modifyList();

    //operator overload:

}