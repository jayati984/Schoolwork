#include  <iostream>
using namespace std;

int main() 
{
	const double FRACTION_OF_SWEETENER = 0.001;
	double weightOfMouse;
	double amountOfSweetenerForMouse;
	double weightOfDieter;
	double amountOfSweetenerForDieter;
	double amountOfDietSodaForDieter;
	
	cout << "Enter the weight of the mouse in grams: " << endl;
        cin >> weightOfMouse;
        cout << "Enter the amount of artificial sweetener required to kill a mouse in grams: " << endl;
        cin >> amountOfSweetenerForMouse;
        cout << "Enter the weight at which the dieter will stop dieting in grams: " << endl;
        cin >> weightOfDieter;
        
        amountOfSweetenerForDieter = (weightOfDieter * amountOfSweetenerForMouse)/weightOfMouse;
        amountOfDietSodaForDieter = amountOfSweetenerForDieter/FRACTION_OF_SWEETENER;

        cout << "The amount of diet soda the dieter can drink is: ." << amountOfDietSodaForDieter << endl;
        return 0;
}

