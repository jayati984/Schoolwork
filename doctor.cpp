#include "doctor.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
namespace SavitchEmployees
{
Doctor::Doctor() : SalariedEmployee()
{
    fee = 0.00;
    specialty = "No Specialty";
}
Doctor::Doctor(const string&  newName, const string&  newNumber, double newWeeklyPay, const string& newSpecialty, double newFee) : SalariedEmployee(newName, newNumber, newWeeklyPay)
{
    specialty = newSpecialty;
    fee = newFee;
}
/*Doctor::Doctor(const Doctor& theObject)
{
    SalariedEmployee(theObject);
    fee = theObject.fee;
    specialty = theObject.specialty;
}
Doctor& Doctor::operator =(const Doctor& rtSide)
{
    SalariedEmployee::operator =(rtSide);
    fee = rtSide.fee;
    specialty = rtSide.specialty;
    return *this;
}*/
string Doctor::getSpecialty() const
{
    return specialty;
}
// void Doctor::setSpecialty(const string& theSpecialty)
// {
//     specialty = theSpecialty;
// }
double Doctor::getFee() const
{
    return fee;
}
// void Doctor::setFee(double theFee)
// {
//     fee = theFee;
// }
}