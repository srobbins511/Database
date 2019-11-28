#include <iostream>
#include "Record.h"


using namespace std;

Record::Record()
{
    originStudent = true;
    opInsert = true;
    ID = 0;
    info = "";
}

Record::Record(bool student, bool op, int id, std::string information)
{
    originStudent = student;
    opInsert = op;
    ID = id;
    info = information;
}

Record::~Record()
{
    
}