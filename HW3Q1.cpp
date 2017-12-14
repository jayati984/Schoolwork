#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int age;
    double height;

    cout << "Enter your name: " << endl;
    cin >> name;
    
    if (name=="Katie")
    {
        cout << "Go to Winchester Mystery House " << endl;
    }
    else
    {
        cout << "Enter your age: " << endl;
        cin >> age;
        cout << "Enter your height in inches: " << endl;
        cin >> height;
    
    if ((age>12) && (height>=60))
        {
            cout << "Go to Great America " << endl;
        }
    else if ((age<12) && (height>=60))
        {
            cout << "Go to Carnival " << endl;
        }
    else if ((age>12) && (height<60))
        {
            cout << "Go to Mall " << endl;
        }
    else
        {
            cout << "Go to Chuck E. Cheese " << endl;
        }
    }
    return 0;
}


