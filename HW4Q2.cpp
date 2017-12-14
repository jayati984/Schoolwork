#include <iostream>
using namespace std;

void enterTime (int& hoursParameter, int& minutesParameter, char& timeOfDayParameter);
void convertTime (int& hoursParameter, int& minutesParameter, char& timeOfDayParameter);
void outputTime (int& hoursParameter, int& minutesParameter, char& timeOfDayParameter);

int main()
{
    int hours, minutes;
    char timeOfDay, answer;
    do
    {
    enterTime (hours, minutes, timeOfDay);
    convertTime (hours, minutes, timeOfDay);
    outputTime (hours, minutes, timeOfDay);
    cout << "Would you like to convert the time again? (y(yes) OR n(no)) " << endl;
    cin >> answer;
    }while ((answer == 'y') || (answer == 'Y'));
    
    return 0;
}

void enterTime (int& hoursParameter, int& minutesParameter, char& timeOfDayParameter)
{
    cout << "Enter the the time(hours) as two integers less than 24: " << endl;
    cin >> hoursParameter;
    cout << "Enter the the time(minutes) as two integers less than 60: " << endl;
    cin >> minutesParameter;
}
void convertTime (int& hoursParameter, int& minutesParameter, char& timeOfDayParameter)
{
    if (hoursParameter>12)
    {
        hoursParameter = hoursParameter - 12;
        timeOfDayParameter = 'P';
    }
    if (hoursParameter == 00)
    {
        hoursParameter = 12;
        timeOfDayParameter ='A';
    }
    else
    {
        hoursParameter = hoursParameter;
        timeOfDayParameter = 'A';
    }
}
void outputTime (int& hoursParameter, int& minutesParameter, char& timeOfDayParameter)
{
    if(timeOfDayParameter == 'A')
    {
        cout << "The 12-hour notation is: " << hoursParameter << ":" << minutesParameter << " " << "A.M." << endl;
    }
    else
    {
        cout << "The 12-hour notation is: " << hoursParameter << ":" << minutesParameter << " " << "P.M." << endl;
    }
}