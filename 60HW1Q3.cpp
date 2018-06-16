#include <iostream>
#include <cstdlib>
using namespace std;

class GasPump
{
    public:
        void display();
        void fuelPrice();
        void reset();
        void StartStopDispensing();
        void setPrice(double pricePerLiter);
    private:
        double costPerLiter;
        double amountCharged;
        double litersUsed;
};

void GasPump::display()
{
    cout << endl;
    cout << "Amount Dispensed:" << litersUsed << " liters" << endl;
    cout << "Cost Per Liter: $" << costPerLiter << endl;
    cout << "Amount Charged: $" << amountCharged << endl;
    cout << "END!" << endl;
    cout << endl;
}
void GasPump::setPrice(double pricePerLiter)
{
    costPerLiter = pricePerLiter;
}
void GasPump::fuelPrice()
{
    amountCharged = costPerLiter * litersUsed;
}
void GasPump::reset()
{
    bool stop1 = true;
    amountCharged = 0.00;
    litersUsed = 0.00;
    costPerLiter = 0.32;
    cout << "Amount Dispensed:" << litersUsed << " liters" << endl;
    cout << "Cost Per Liter: $" << costPerLiter << endl;
    cout << "Amount Charged: $" << amountCharged << endl;
    cout << "BEGIN FUELLING!" << endl;
}
void GasPump::StartStopDispensing()
{
    char answer;
    bool stop = false;
    litersUsed++;
    cout << "Would you like to stop pumping gas? You have pumped 1 liter. (Please enter y/n)" << endl;
    cin >> answer;
    while(answer == 'n')
    {
        litersUsed++;
        cout << "Would you like to stop pumping gas? You have pumped " << litersUsed << " liters. (Please enter y/n)" << endl;
        cin >> answer;
    }
    stop = true;
    fuelPrice();
    display();
}

int main()
{
    GasPump fuel;
    fuel.reset();
    fuel.setPrice(0.32);
    fuel.StartStopDispensing();
    return 0;
}