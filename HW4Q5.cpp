#include <iostream>
using namespace std;

double convertToMPH(int paceInMinutesParameter, int paceInSecondsParameter);
double convertToMPH(double kilometersPerHourParameter);

int main()
{
    int paceInMinutes, paceInSeconds;
    double kilometersPerHour;
    char answer;
    do
    {
    cout << "Enter the pace in minutes per mile: " << endl;
    cin >> paceInMinutes;
    cout << "Enter the pace in seconds per mile: " << endl;
    cin >> paceInSeconds;
    cout << "The speed in miles per hour is: " << convertToMPH(paceInMinutes, paceInSeconds) << endl;
    
    cout << "Enter the speed in kilometers per hour: " << endl;
    cin >> kilometersPerHour;
    cout << "The speed in miles per hour is: " << convertToMPH(kilometersPerHour) << endl;
    
    cout << "Do you want to test it again?(Enter y(yes)/n()no) " << endl;
    cin >> answer;
    }while ((answer == 'y') || (answer == 'Y'));
    
    return 0;
    
}
double convertToMPH(int paceInMinutesParameter, int paceInSecondsParameter)
{
    return (60/(paceInMinutesParameter + (paceInSecondsParameter/60))); 
}
double convertToMPH(double kilometersPerHourParameter)
{
    return (kilometersPerHourParameter/1.61);
}
