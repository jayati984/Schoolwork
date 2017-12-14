#include <iostream>
#include <cmath>
using namespace std;

double gravitationalForce (double mass1Parameter, double mass2Parameter, double distanceParameter);

const double UNIVERSAL_GRAVITATIONAL = 6.673 * pow(10, -8); // in cm^3/(g . sec^2)

int main()
{
    char answer;
    double mass1, mass2, distance;
    
    do
    {
        cout << "The gravitational force is: " << gravitationalForce(mass1, mass2, distance) << "dynes" << endl; // is g . cm/sec^2
        cout << "Would you like repeat this calculation? (Please type in y(yes)or n(no))" << endl;
        cin >> answer;
    
    }while ((answer == 'y') || (answer == 'Y') );
    
    return 0;
}

double gravitationalForce (double mass1Parameter, double mass2Parameter, double distanceParameter)
{
    cout << "Enter the mass of object one in grams: " << endl;
    cin >> mass1Parameter;
    cout << "Enter the mass of object two in grams: " << endl;
    cin >> mass2Parameter;
    cout << "Enter the distance between the two objects in cm: " << endl;
    cin >> distanceParameter;
    
    return ((UNIVERSAL_GRAVITATIONAL * mass1Parameter * mass2Parameter)/(pow(distanceParameter, 2))); // is g . cm/sec^2
} 



    
    