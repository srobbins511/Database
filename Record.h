#include <iostream>


using namespace std;

class Record
{
    public:
        bool originStudent;
        bool opInsert;
        int ID;
        std::string info;

        Record();
        Record(bool student, bool op, int id, std::string information);
        ~Record();
};