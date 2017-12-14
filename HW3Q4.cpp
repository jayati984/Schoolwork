#include <iostream>
#include <cmath>
using namespace std;

double windChillIndex (double windSpeedParameter, double temperatureParameter);

int main()
{
    double speed;        // in m/sec
    double temperature;  // in degrees Celsius
    
    cout << "The wind chill index is: " << windChillIndex(speed,temperature) << "degrees Celsius" << endl;
    
    return 0;
}

double windChillIndex (double windSpeedParameter, double temperatureParameter)
{
    cout << "Enter the wind speed in m/s: " << endl;
    cin >> windSpeedParameter;
    cout << "Enter the temperature in degrees Celsius: " << endl;
    cin >> temperatureParameter;
    
    if (temperatureParameter>10)
    {
        cout << "Error! Please enter a temperature less than or equal to 10 degrees Celsius: " << endl;
        cin >> temperatureParameter;
    }
    
    return (33 - ((((10 * sqrt(windSpeedParameter)) - windSpeedParameter + 10.5) * (33 - temperatureParameter))/ (23.1)));
}
