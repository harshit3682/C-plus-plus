#include <iostream>
#include <string.h>
using namespace std;

class student
{
    char name[30];
    int rollno;
    int sem;

public:
    void putdata()
    {
        cout << "Name= " << name << endl;
        cout << "Sem= " << sem << endl;
        cout << "Rollno= " << rollno << endl;
    }
    void getdata()
    {
        cout << "Name= ";
        cin >> name;
        cout << "Sem= ";
        cin >> sem;
        cout << "Rollno= ";
        cin >> rollno;
    }
};

int main()
{
    int n, i = 0;
    cout << "Enter no. of students= ";
    cin >> n;

    student s1[n];
    cout << endl;
    cout << "ENTERING OF STUDENT'S DATA: " << endl;
    while (i < n)
    {
        cout << endl;
        cout << "Student " << i + 1 << " data: ";
        cout << endl;
        s1[i].getdata();
        i++;
    }

    cout << endl;
    cout << "DISPLAYING OF STUDENT'S DATA: " << endl;
    i = 0;
    cout << endl;
    while (i < n)
    {
        cout << endl;
        cout << "Student " << i + 1 << " data: ";
        cout << endl;
        s1[i].putdata();
        i++;
    }
}