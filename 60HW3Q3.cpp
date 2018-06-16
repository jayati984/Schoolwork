#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Student
{
    public:
        Student();
        ~Student();
        Student& operator = (const Student& r);
        void output();
        void input();
        void reset();
    private:
        string name;
        int numClasses;
        string *classList;
};

int main()
{
    Student s1, s2;
    s1.input();
    cout << "STUDENT 1:" << endl;
    s1.output();
    s2=s1;
    cout << "COPY OF LIST OF CLASSES:" << endl;
    s2.output();
    s1.reset();
    cout << "STUDENT 1 AFTER COMPLETION:" << endl;
    s1.output();
    return 0;
}

Student::Student()
{
    name = "";
    numClasses = 0;
    classList = NULL;
}
Student::~Student()
{
    delete[] classList;
}
Student& Student::operator = (const Student& r)
{
    if (this == &r)
    {
        return *this;
    }
    else
    {
        numClasses = r.numClasses;
        delete[] classList;
        classList = new string[numClasses];
        for(int i = 0; i < numClasses; i++)
        {
            classList[i] = r.classList[i];
        }
        return *this;
    }
}
void Student::output()
{
    cout << "NAME: " << name << endl;
    cout << "NUMBER OF CLASSES: " << numClasses << endl;
    cout << "NAME OF CLASSES: " << endl;
    for (int i = 0; i < numClasses; i++)
    {
        cout << classList[i] << endl;
    }
    cout << endl;
}
void Student::input()
{
    cout << "Enter student name:" << endl;
    getline(cin, name);
    cout << "Enter the number of classes currently enrolled in:" << endl;
    cin >> numClasses;
    cin.ignore(1000, '\n');
    cout << "Enter the names of the classes currently enrolled in:" << endl;
    classList = new string[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
         getline(cin, classList[i]);
    }
    
}
void Student::reset()
{
    name = "";
    classList = NULL;
    numClasses = 0;
}