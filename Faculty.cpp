#include <iostream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
    ID = 0;
    name = "John Doe";
    level = "Freshman";
    department = "Biology";
    advisees = new GenDoubleLinkedList<int>();
}

Faculty::Faculty(int id, string n, string l, string m)
{
    ID = id;
    name = n;
    level = l;
    department = m;
    advisees = new GenDoubleLinkedList<int>();
}

Faculty::~Faculty()
{
    delete advisees;
}

bool Faculty::operator==(Faculty f1)
{
    return (this->ID == f1.ID && this->name == f1.name && this->level == f1.level && this->department == f1.department);
}

bool Faculty::operator>=(Faculty f1)
{
    if(this->advisees->getSize() >= f1.advisees->getSize())
    {
        return true;
    }
    return false;
}

bool Faculty::operator<=(Faculty f1)
{
    if(this->advisees->getSize() <= f1.advisees->getSize())
    {
        return true;
    }
    return false;
}

bool Faculty::operator>(Faculty f1)
{
    if(this->advisees->getSize() > f1.advisees->getSize())
    {
        return true;
    }
    return false;
}

bool Faculty::operator<(Faculty f1)
{
    if(this->advisees->getSize() < f1.advisees->getSize())
    {
        return true;
    }
    return false;
}

/*std::string Faculty::toString()
{
    std::string word = "|";
    word += ID + "|";
    word += name + "|";
    word += level + "|";
    word += department + "|";
    while(!advisees->isEmpty())
    {
        word += *advisees->removeFront() + "|";
    }
    return word;
}*/

Record* Faculty::toRecord(bool op)
{
    std::string info = "|" + name + "|" + level + "|" + department + "|";
    while(!advisees->isEmpty())
    {
        info += *advisees->removeFront() + "|";
    }
    Record* temp = new Record(false,op,ID,info);
    return temp;
}

void Faculty::print()
{
    cout<<"ID Number: " + ID << endl;
    cout<<"Name: " + name << endl;
    cout<<"Level: " + level << endl;
    cout<<"Department: " + department << endl;
    cout<<"Advisee's: " << endl;
    advisees->printList();
}