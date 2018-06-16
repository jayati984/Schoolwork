#include "billing.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Billing()
{
    amountDue = 0.0;
}
Billing(Patient p1, Doctor d1, double pay)
{
    p = p1;
    d = d1;
    amountDue = pay;
}
Billing(const Billing& obj)
{
    p = obj.p;
    d = obj.d;
    amountDue = obj.amountDue;
}
Billing& operator =(const Billing& rtSide)
{
    p = rtSide.p;
    d = rtSide.d;
    amountDue = rtSide.amountDue;
    return *this;
}
Patient getP()
{
    return p;
}
Doctor getD()
{
    return d;
}
double getAmountDue()
{
    return amountDue;
}