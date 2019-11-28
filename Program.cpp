#include <iostream>
#include "Manager.h"

using namespace std;


int main()
{
    Manager *m = new Manager();
    while(1)
    {
        m->GetUserInput();
    }
    return 0;
}