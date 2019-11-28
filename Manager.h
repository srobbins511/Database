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
        GenBST masterFaculty;
        GenBST masterStudent;
        GenStack<record> rollbackLis;

}