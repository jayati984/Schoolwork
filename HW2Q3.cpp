#include <iostream>
#include <string>
using namespace std;

int main()
{
    char day;
    cout << "Enter the day of the week using letters, Monday (A), Tuesday (B), Wednesday (C), Thursday (D), Friday (E)" << endl;
    cin >> day;
    
    switch (day)
    {
        case 'A':
            cout << "Monday: CSCI 10 at 1:00, PHIL 11A at 2:15, MATH 12 at 4:45 \n";
            break;
        case 'B':
            cout << "Tuesday: PHYS 2 at 12:10, CSCI 10 lab at 2:15 \n";
            break;
        case 'C':
            cout << "Wednesday: CSCI 10 at 1:00, PHIL 11A at 2:15, MATH 12 at 4:45 \n";
            break;
        case 'D':
            cout << "Thursday: PHYS 2 at 12:10 \n";
            break;
        case 'E':
            cout << "Friday: CSCI 10 at 1:00, PHIL 11A at 2:15, MATH 12 at 4:45 \n";
            break;
        default: 
            cout << "Number entered is not valid \n";
    }
    return 0;
}
