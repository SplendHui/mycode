#include <iostream>
#include <string>

using namespace std;

class StudentId
{
  public:
    int id;

    StudentId()
    {
        cout << "StudentId constructor" << endl;
    }

    StudentId(int id)
    {
        cout << "StudentId(int id) " << endl;
        this->id = id;
    }
};

class Student
{
  public:
    StudentId id;
    string name;

    Student(string n, int i) : id(i), name(n)
    {
        cout << "Student Constructor" << endl;
    }

    Student(Student &s1) { cout << "Student &s1" << endl; }

    Student()
    {
        cout << "student no argu" << endl;
    }
    void operator=(Student s)
    {
        cout << "=" << endl;
    }
};

void print(Student stu)
{

    cout << &stu << endl;
    cout << stu.id.id << endl;
}

int main()
{

    Student s1("splend", 20);
    cout << "-----------" << endl;
    //Student s1;
    Student s2 = s1;
    cout << "----" << endl;
    cout << &s1 << endl;
    print(s1);
    return 0;
}