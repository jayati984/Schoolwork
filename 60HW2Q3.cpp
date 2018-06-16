#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
//Class for amounts of money in U.S. currency.
class Money
{
    public:
        Money( );
        Money(double amount);
        Money(int theDollars, int theCents);
        Money(int theDollars);
        double getAmount( ) const;
        int getDollars( ) const;
        int getCents( ) const;
        const Money percent(int percentFigure) const;
        friend const Money operator +(const Money& amount1, const Money& amount2);
        friend const Money operator -(const Money& amount1, const Money& amount2);
        friend bool operator ==(const Money& amount1, const Money& amount2);
        friend const Money operator -(const Money& amount);
        friend ostream& operator <<(ostream& outputStream, const Money& amount);
        friend istream& operator >>(istream& inputStream, Money& amount);
        friend bool operator < (const Money& amount1, const Money& amount2);
        friend bool operator > (const Money& amount1, const Money& amount2);
        friend bool operator <= (const Money& amount1, const Money& amount2);
        friend bool operator >= (const Money& amount1, const Money& amount2);
    private:
        //A negative amount is represented as negative dollars and negative cents. Negative $4.50 is represented as -4 and -50
        int dollars; 
        int cents; 
        int dollarsPart(double amount) const;
        int centsPart(double amount) const;
        int round(double number) const;
};
        
        int main( )
        {
            Money yourAmount, myAmount(10, 9);
            cout << "Enter an amount of money (include $ sign): ";
            cin >> yourAmount;
            cout << "Your amount is " << yourAmount << endl;
            cout << "My amount is " << myAmount << endl;
            if (yourAmount == myAmount)
                cout << "We have the same amounts.\n";
            else
                cout << "One of us is richer.\n";
            Money ourAmount = yourAmount + myAmount;
            cout << yourAmount << " + " << myAmount<< " equals " << ourAmount << endl;
            Money diffAmount = yourAmount - myAmount;
            cout << yourAmount << " - " << myAmount<< " equals " << diffAmount << endl;
            if (yourAmount > myAmount)
            {
                cout << "You are richer." << endl;
            }
            else if (yourAmount < myAmount)
            {
                cout << "I am richer." << endl;
            }
            else if ((yourAmount >= myAmount) && (myAmount <= yourAmount))
            {
                cout << "Either you are rich or both of us have the same amount." << endl;
            }
            else
            {
                cout << "Either I am rich or both of us have the same amount." << endl;
            }
            cout << "10% of my amount is: " << myAmount.percent(10) << endl;
            cout << "10% of your amount is: " << yourAmount.percent(10) << endl;
            return 0;
        }
        
        bool operator < (const Money& amount1, const Money& amount2)
        {
            return(amount1.dollars > amount2.dollars);
        }
        
        bool operator > (const Money& amount1, const Money& amount2)
        {
            return(amount1.dollars < amount2.dollars);
        }
        
        bool operator <= (const Money& amount1, const Money& amount2)
        {
            return((amount1.dollars <= amount2.dollars) && (amount1.cents <= amount2.cents));
        }
        
        bool operator >= (const Money& amount1, const Money& amount2)
        {
            return((amount1.dollars >= amount2.dollars) && (amount1.cents >= amount2.cents));
        }
        
        const Money Money::percent(int p) const
        {
            int d = dollars * p/100;
            int c = dollars * p%100 + cents * p/100;
            return Money(d,c);
        }
        
        ostream& operator <<(ostream& outputStream, const Money& amount)
        {
            int absDollars = abs(amount.dollars);
            int absCents = abs(amount.cents);
            if (amount.dollars < 0 || amount.cents < 0)
                //accounts for dollars == 0 or cents == 0
                outputStream << "$-";
            else
                outputStream << '$';
            outputStream << absDollars;
            if (absCents >= 10)outputStream << '.' << absCents;
            else
                outputStream << '.' << '0' << absCents;
            return outputStream;
        } 
        
        //Uses iostream and cstdlib:
        istream& operator >>(istream& inputStream, Money& amount)
        {
            char dollarSign;inputStream >> dollarSign; //hopefully
            if (dollarSign != '$')
            {
                cout << "No dollar sign in Money input.\n";
                exit(1);
            }
            double amountAsDouble;
            inputStream >> amountAsDouble;
            amount.dollars = amount.dollarsPart(amountAsDouble);
            amount.cents = amount.centsPart(amountAsDouble);
            return inputStream;
        }
        
        const Money operator +(const Money& amount1, const Money& amount2)
        {
            int allCents1 = amount1.cents + amount1.dollars*100;
            int allCents2 = amount2.cents + amount2.dollars*100;
            int sumAllCents = allCents1 + allCents2;int absAllCents = abs(sumAllCents); 
            //Money can be negative.
            int finalDollars = absAllCents/100;int finalCents = absAllCents%100;
            if (sumAllCents < 0)
            {
                finalDollars = -finalDollars;
                finalCents = -finalCents;
            }
            return Money(finalDollars, finalCents);
        }
        
        //Uses cstdlib:
        const Money operator -(const Money& amount1, const Money& amount2)
        {
            int allCents1 = amount1.cents + amount1.dollars*100;
            int allCents2 = amount2.cents + amount2.dollars*100;
            int diffAllCents = allCents1 - allCents2;
            int absAllCents = abs(diffAllCents);
            int finalDollars = absAllCents/100;
            int finalCents = absAllCents%100;
            if (diffAllCents < 0)
            {
                finalDollars = -finalDollars;finalCents = -finalCents;
            }
            return Money(finalDollars, finalCents);
        }
        
        bool operator ==(const Money& amount1, const Money& amount2)
        {
            return ((amount1.dollars == amount2.dollars)&& (amount1.cents == amount2.cents));
        }
        
        const Money operator -(const Money& amount)
        {
            return Money(-amount.dollars, -amount.cents);
        }
        
        Money::Money( ): dollars(0), cents(0)
        {/*Body intentionally empty.*/}
        
        Money::Money(double amount): dollars(dollarsPart(amount)), cents(centsPart(amount))
        {/*Body intentionally empty*/}
        
        Money::Money(int theDollars): dollars(theDollars), cents(0)
        {/*Body intentionally empty*/}
        
        //Uses cstdlib:
        Money::Money(int theDollars, int theCents)
        {
            if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0))
            {
                cout << "Inconsistent money data.\n";
                exit(1);
            }
            dollars = theDollars;
            cents = theCents;
        }
        
        double Money::getAmount( ) const
        {
            return (dollars + cents*0.01);
        }
        
        int Money::getDollars( ) const
        {
            return dollars;
        }
        
        int Money::getCents( ) const
        {
            return cents;
        }
        
        int Money::dollarsPart(double amount) const
        {
            return static_cast<int>(amount);
        }
        
        int Money::centsPart(double amount) const
        {
            double doubleCents = amount*100;
            int intCents = (round(fabs(doubleCents)))%100;
            //% can misbehave on negatives
            if (amount < 0)intCents = -intCents;
            return intCents;
        }
        
        int Money::round(double number) const
        {
            return static_cast<int>(floor(number + 0.5));
        }