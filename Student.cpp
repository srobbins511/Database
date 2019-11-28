#include <iostream>
#include "Student.h"



using namespace std;

Student::Student()
{
    ID = 0;
    name = "John Doe";
    level = "Freshman";
    major = "Computer Science";
    GPA = 2.0;
    advisor = 0;
}

Student::Student(int id, string n, string l, string m, double gpa, int adv)
{
    ID = id;
    name = n;
    level = l;
    major = m;
    GPA = gpa;
    advisor = adv;
}

Student::~Student()
{

}

bool Student::operator==(Student s1)
{
    return (this->ID == s1.ID && this->name == s1.name && this->level == s1.level && this->major == s1.major && this->GPA == s1.GPA && this->advisor == s1.advisor);
}

bool Student::operator>=(Student s1)
{
    if(this->GPA >= s1.GPA)
    {
        return true;
    }
    return false;
}

bool Student::operator>(Student s1)
{
    if(this->GPA > s1.GPA)
    {
        return true;
    }
    return false;
}

bool Student::operator<=(Student s1)
{
    if(this->GPA <= s1.GPA)
    {
        return true;
    }
    return false;
}

bool Student::operator<(Student s1)
{
    if(this->GPA < s1.GPA)
    {
        return true;
    }
    return false;
}

std::string Student::toString()
{
    std::string word = "|";
    word += ID + "|";
    word += name + "|" ;
    word += level + "|";
    word += major + "|"; 
    word += to_string(GPA) + "|"; 
    word += advisor + "|";
    return word;
}

Record* Student::toRecord(bool op)
{
    std::string info = "|";
    info += name + "|";
    info += level + "|";
    info += major + "|";
    info += to_string(GPA) + "|";
    info += advisor + "|";
    Record* temp = new Record(true,op,ID,info);
    return temp;
}