#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Record.h"


using namespace std;


class Student
{
    public:
        int ID;
        std::string name;
        std::string level;
        std::string major;
        double GPA;
        int advisor;

        Student();
        Student(int id, string n, string l, string m, double gpa, int adv);
        ~Student();

        std::string toString();
        void print();
        Record* toRecord(bool op);


        bool operator==(Student s1);
        bool operator>=(Student s1);
        bool operator<=(Student s1);
        bool operator<(Student s1);
        bool operator>(Student s1);
};

#endif