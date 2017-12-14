#include <iostream>
using namespace std;

int main()
{
	double gallons;
	double liters;

	cout << "Enter the number of gallons: "<< endl;
	cin >> gallons;

	liters = gallons * 3.78541;

	cout << "The number of liters is: " << liters << endl;
	return 0;
}

