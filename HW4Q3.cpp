#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void area(double val1, double val2, double val3, double& areaParameter, double& perimeterParameter);

int main()
{
    double value1, value2, value3, Area, Perimeter;
    area(value1, value2, value3, Area, Perimeter);
    return 0;
}

void area(double val1, double val2, double val3, double& areaParameter, double& perimeterParameter)
{
    cout << "Enter three positive values for the sides of a triangle: " << endl;
    cin >> val1 >> val2 >> val3;
    if ((val1 + val2) > val3) && ((val2 + val3) > val1) && ((val1 + val3) > val2)
    {
        perimeterParameter = (val1 + val2 + val3);
        areaParameter = sqrt((perimeterParameter/2) * ((perimeterParameter/2) - val1) * ((perimeterParameter/2) - val2) * ((perimeterParameter/2) - val3));
        cout << "The area of the triangle is: " << areaParameter << endl;
    }
    else
    {
        cout << "Values entered are invalid! (Cannot form a triangle)" << endl;
    }
}
