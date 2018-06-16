#include "doctor.h"
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::string;

namespace SavitchEmployees
{
int main()
{
    Doctor record1, record2("Jayati Patel", "512-333-7895", 20000.00, "Pediatrician", 20.00);
    cout << "The fee is: $" <<record1.getFee() << endl;
    cout << "The specialty is:" <<record1.getSpecialty() << endl;
    /*record2 = record1;
    cout << "The copy of the fee is: $" << record2.getFee() << endl;
    cout << "The copy of the specialty is:" << record2.getSpecialty() << endl;*/
    return 0;
}
}