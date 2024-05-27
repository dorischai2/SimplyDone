/*
This document is purely for documenting my design of the application

***Data structures:
 - toDo class - contains each toDo item including 
    - std::string status: (NEW, WIP, DONE) - perhaps store in an array so can prompt for a selection of status
    - std::string item: the actual item
    - above two items separated by comma

    - method display
    - method enterStatus
    - method enterDescription

 - toDoList class: contains information of a certain list
    - number of items in the list
    - a dynamic array of toDo objects that stores the information
    
    other notes:
    - rule of 5 should be implemented since dynamic resource is present
    - 


*** Application logic:
 - main will display a menu with welcome message and three menu options 
    - view
    - modify
    - delete
    - 0 for exit

    view:
        - since the application will support several different to-do lists, main will then prompt user
        for the filename they wish to open & view
        - some user-input validation such as checking if entry ended with .txt (or perhaps csv?)
        - check if file can be opened, if not, prompt user to enter again. 
        - if file is openable, call toDoList(filename) to read in the data, and display method to
        display the to-do list
        - provide user option to exit to previous menu
    
    modify:
        - similar logic as view in terms of opening & reading
        - prompt user whether they want to add to list or modify existing items
            - if add:
                - collect status
                - collect item
                - display item & confirm with user to add to list
                - write to the file in append mode to add to list
            - if modify:
                - collect index of the item
                - collect new status and item
                - reflect the change in appropriate record
                - save to file the change
    delete:
        - similar logic as above in terms of opening & reading file
        - prompt for deleting the file or only certain record
            - use filesystem lib to remove file
            - use element shifting to remove an element


*** Future features to implement:
 - display a list of filenames in current directory for user to choose instead of having user to 
 enter the file name
 - integrate MongoDB to manage data

*/