#include <iostream>
using namespace std;

int main()
{
	double weight;
	double numberOfMinutes;
	double totalCalories;
	int numberOfMETS;
	
	cout << "Enter your weight in pounds: " << endl;
	cin >> weight;
        cout << "Enter the number of minutes you spent on the activity: " << endl;
        cin >> numberOfMinutes;
        cout << "Enter the number of METS for that activity: " << endl;
        cin >> numberOfMETS;
        totalCalories = 0.0175 * numberOfMETS * (weight/2.2) * numberOfMinutes;

        cout << "The total number of calories burned is: " << totalCalories << endl;
        return 0;
}
	









