#include <iostream>
#include "Student.h"
#include "Faculty.h"
#include "Student.h"
#include "GenBST.h"
#include "GenStack.h"


using namespace std;

class Manager
{
    public:
        GenBST<Faculty>* masterFaculty;
        GenBST<Student>* masterStudent;
        GenStack<Record>* rollbackList;

        Manager();
        ~Manager();
        int main();

        void GetUserInput();
        int atoi(std::string num);
};