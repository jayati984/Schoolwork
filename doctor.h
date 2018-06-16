#ifndef DOCTOR_H
#define DOCTOR_H
#include "salariedemployee.h"
#include <string>
using std::string;
namespace SavitchEmployees
{
class Doctor : public SalariedEmployee
{
    public:
        Doctor();
        Doctor(const string&  newName, const string&  newNumber, double newWeeklyPay, const string& newSpecialty, double newFee);
        //Doctor(const Doctor& theObject);
        //Doctor& operator =(const Doctor rtSide);
        string getSpecialty() const;
//         void setSpecialty(const string& theSpecialty);
        double getFee() const;
//         void setFee(double theFee);
    private:
        string specialty;
        double fee;
};
}
#endif