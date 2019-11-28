#include <iostream>
#include "Manager.h"


using namespace std;


Manager::Manager()
{
    masterStudent = new GenBST<Student>();
    masterFaculty = new GenBST<Faculty>();
    rollbackList = new GenStack<Record>();
}

Manager::~Manager()
{
    delete masterStudent;
    delete masterFaculty;
    delete rollbackList;
}

void Manager::GetUserInput()
{
    std::string ans = "";
    cout<<"Operations List: " << endl;
    cout<<" 1. Print All Students" << endl;
    cout<<" 2. Print All Faculty" << endl;
    cout<<" 3. Find Student" << endl;
    cout<<" 4. Find Faculty" << endl;
    cout<<" 5. Find Student's Advisor" << endl;
    cout<<" 6. Print Faculties Advisee's" << endl;
    cout<<" 7. Add Student" << endl;
    cout<<" 8. Delete Student" << endl;
    cout<<" 9. Add Faculty" << endl;
    cout<<" 10. Delete Faculty" << endl;
    cout<<" 11. Change Student Advisor" << endl;
    cout<<" 12. Remove Advisee from Faculty" << endl;
    cout<<" 13. Rollback" << endl;
    cout<<" 14. Exit" << endl;

    cin >> ans;
    int tempID;
    int temp = atoi(ans);
    switch(temp)
    {
        case 1:
            masterStudent->printTree();
            break;
        case 2:
            masterFaculty->printTree();
            break;
        case 3:
            cout<<"Enter the Student ID" << endl;
            cin >> ans;
            tempID = atoi(ans);
            if(masterStudent->search(tempID))
            {
                masterStudent->getNode(tempID)->data->print();
            }
            break;
        case 4:
            cout<<"Enter the Faculty ID" << endl;
            cin >> ans;
            tempID = atoi(ans);
            if(masterFaculty->search(tempID))
            {
                masterFaculty->getNode(tempID)->data->print();
            }
            break;
        case 5:
            cout<< "Enter Student ID: " << endl;
            cin >> ans;
            tempID = atoi(ans);
            if(masterStudent->search(tempID))
            {
               cout<< masterStudent->getNode(tempID)->data->advisor << endl;
            }
            break;
        case 6:
            break;
        case 7:
            AddStudent();
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            exit(0);
            break;
    }
}


int Manager::atoi(std::string num)
{
    int number = 0;
    for(char c : num)
    {
        number*=10;
        if(c == '9')
        {
            number+=9;
        }
        else if(c == '8')
        {
            number+=8;
        }
        else if(c == '7')
        {
            number+=7;
        }
        else if(c == '6')
        {
            number+=6;
        }
        else if(c == '5')
        {
            number+=5;
        }
        else if(c == '4')
        {
            number+=4;
        }
        else if(c == '3')
        {
            number+=3;
        }
        else if(c == '2')
        {
            number+=2;
        }
        else if(c == '1')
        {
            number+=1;
        }
        else if(c == '0')
        {
            number+=0;
        }
        else{
            throw -1;
        }
    }
    return number;
}

void Manager::AddStudent()
{
    bool finished = false;
    std::string ans;
    std::string tempName;
    std::string tempLevel;
    std::string tempMajor;
    double tempGPA;
    int advisorID;
    int id;
    while(!finished){
        cout<<"Enter ID NUMBER: " << endl;
        cin >>ans;
        try
        {
            finished = true;
            id = atoi(ans);
        }
        catch(int)
        {
            cout<<"Unrecognized Input" << endl;
            finished = false;
        }

    }
    cout<< "Enter Student Name: " << endl;
    cin >>tempName;

    cout<<"Enter Student Level: \n1 for Freshman, 2 for Sophmore, 3 for Junior, 4 for Senior:" <<endl;
    int temp;
    cin>> temp;
    do{
        switch(temp)
        {
            case 1:
                tempLevel = "Freshman";
                break;
            case 2:
                tempLevel = "Junior";
                break;
            case 3:
                tempLevel = "Sophmore";
                break;
            case 4:
                tempLevel = "Senior";
                break;
            default:
                finished = false;
        }
    }while(!finished);

    cout<<"Enter Major: "<<endl;
    cin >>tempMajor;

    cout <<"Enter GPA" << endl;
    cin >> tempGPA;
    
    cout << "Enter Advisor ID: " << endl;
    cin >> advisorID;
    Student* s1 = new Student(id,tempName,tempLevel,tempMajor,tempGPA, advisorID);
    masterStudent->insert(id, s1);
    
}
