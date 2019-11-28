#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "GenDoubleLinkedList.h"
#include "Record.h"


using namespace std;


class Faculty
{
    public:
        int ID;
        std::string name;
        std::string level;
        std::string department;
        GenDoubleLinkedList<int>* advisees;

        Faculty();
        Faculty(int id, string n, string l, string m);
        ~Faculty();

        std::string toString();
        Record* toRecord(bool op);

        bool operator==(Faculty f1);
        bool operator>=(Faculty f1);
        bool operator<=(Faculty f1);
        bool operator>(Faculty f1);
        bool operator<(Faculty f1);
};

#endif