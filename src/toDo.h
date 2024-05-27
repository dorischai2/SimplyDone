#include <fstream>
#include <string>

namespace toDoProject{
    const std::string statusArr[3] = {"NEW", "WIP", "Done"};

    struct toDo //struct instead of class because access is required for operators
    {
        std::string status {};
        std::string item {};
        // no constructor needed for now

        // display to cout
        std::iostream& display(std::iostream& os) const;

        // write to file
        std::fstream& write(std::fstream& of) const;

        //toDo& operator<<(std::fstream& f); -- this should be in toDoList perhaps
    };

    class toDoList {
        int itemCount {0};
        toDo* tdArr {nullptr};
        std::string fileName {};
    public:
        toDoList() {};
        toDoList(std::string fileNm);

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