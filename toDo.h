#include <fstream>
#include <string>

namespace toDoProject{

    struct toDo //struct instead of class because access is required for operators
    {
        std::string status;
        std::string item;

        toDo& operator<<(std::fstream& f);
    };

    class toDoList {
        int itemCount {0};
        toDo* tdArr {nullptr};
        std::string fileName {};
    public:
        toDoList() {};

        void getFileName();
        

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