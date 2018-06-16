#ifndef BILLING_H
#define BILLING_H
#include "patient.h"
#include <string>
using std::string;
using std::endl;

class Billing
{
    public:
        Billing();
        Billing(Patient p1, Doctor d1, double pay);
        Billing(const Billing& obj);
        Billing& operator =(const Billing& rtSide);
        Patient getP();
        Doctor getD();
        double getAmountDue();
    private:
        Patient p;
        Doctor d;
        double amountDue;
};
#endif