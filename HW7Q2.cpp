#include <iostream>
using namespace std;

struct Fraction
{
    double numerator;
    double denominator;
};

void printFunction(Fraction f);
Fraction mult(Fraction f1, Fraction f2);
Fraction add(Fraction f1, Fraction f2);

int main()
{
    Fraction fraction;
    Fraction fraction1;
    Fraction fraction2;
    Fraction multiply;
    Fraction addition;
    
    cout << "Enter a fraction: " << endl;
    cout << "Enter the numerator: " << endl;
    cin >> fraction.numerator; 
    cout << "Enter the denominator: " << endl;
    cin >> fraction.denominator;
    cout << "Enter a fraction: " << endl;
    cout << "Enter the numerator: " << endl;
    cin >> fraction1.numerator;
    cout << "Enter the denominator: " << endl;
    cin >> fraction1.denominator;
    cout << "Enter a fraction: " << endl;
    cout << "Enter the numerator: " << endl;
    cin >> fraction2.numerator; 
    cout << "Enter the denominator: " << endl;
    cin >> fraction2.denominator;
    
    printFunction(fraction);
    multiply = mult(fraction1, fraction2);
    addition = add(fraction1, fraction2);
    
    cout << "The multiplication of the fractions is: " << endl;
    cout << multiply.numerator << "/" << multiply.denominator << endl;
    cout << "The addition of the fractions is: " << endl;
    cout << addition.numerator << "/" << addition.denominator << endl;
    
    return 0;
}

void printFunction(Fraction f)
{
    cout << "The printed out fraction is: " << endl;
    cout << f.numerator << "/" << f.denominator << endl;
}

Fraction mult(Fraction f1, Fraction f2)
{
    Fraction multiply;
    multiply.numerator=((f1.numerator)*(f2.numerator));
    multiply.denominator=((f1.denominator)*(f2.denominator));
    return multiply;
}

Fraction add(Fraction f1, Fraction f2)
{
    Fraction addition;
    addition.numerator=((f1.numerator*f2.denominator)+(f2.numerator*f1.denominator));
    addition.denominator=((f1.denominator*f2.denominator)+(f2.denominator*f1.denominator));
    return addition;
}