#include <iostream>
#include <cstdlib>
using namespace std;

class Month
{
    public:
        Month();
        Month(char letter1, char letter2, char letter3);
        Month(int number);
        void inputAsInteger();
        void inputAsLetters(char c1, char c2, char c3);
        void outputAsInteger();
        void outputAsLetters();
        Month nextMonth();
        int getMonth();
    private:
        int month;
};

Month::Month()
{
    month = 1;
    cout << "The first month as an integer is: " << month << endl;
}
Month::Month(char letter1, char letter2, char letter3)
{
    if(letter1 == 'J'||'j' && letter2 == 'a' && letter3 == 'n')
    {
        month = 1;
    } 
    else if(letter1 == 'F'||'f' && letter2 == 'e' && letter3 == 'b')
    {
        month = 2;
    }   
    else if(letter1 == 'M'||'m' && letter2 == 'a' && letter3 == 'r')
    {
        month = 3;
    }   
    else if(letter1 == 'A'||'a' && letter2 == 'p' && letter3 == 'r')
    {
        month = 4;
    }   
    else if(letter1 == 'M'||'m' && letter2 == 'a' && letter3 == 'y')
    {
        month = 5;
    }   
    else if(letter1 == 'J'||'j' && letter2 == 'u' && letter3 == 'n')
    {
        month = 6;
    }   
    else if(letter1 == 'J'||'j' && letter2 == 'u' && letter3 == 'l')
    {
        month = 7;
    }   
    else if(letter1 == 'A'||'a' && letter2 == 'u' && letter3 == 'g')
    {
        month = 8;
    }   
    else if(letter1 == 'S'||'s' && letter2 == 'e' && letter3 == 'p')
    {
        month = 9;
    }   
    else if(letter1 == 'O'||'o' && letter2 == 'c' && letter3 == 't')
    {
        month = 10;
    }    
    else if(letter1 == 'N'||'n' && letter2 == 'o' && letter3 == 'v')
    {
        month = 11;
    }    
    else if(letter1 == 'D'||'d' && letter2 == 'e' && letter3 == 'c')
    {
        month = 12;
    }    
    else
    {
        exit(1);
    }                                                    
}
Month::Month(int number)
{
    if(number < 1 || number > 12)
    {
        exit(1);
    }
    else
    {
        month = number;
    }
}
void Month::inputAsInteger()
{
    cout << "Enter the month as an integer:" << endl;
    cin >> month;
}
void Month::inputAsLetters(char c1, char c2, char c3)
{
    cout << "Enter the month as the first three letters." << endl;
    cout << "Enter the first letter: " << endl;
    cin >> c1;
    cout << "Enter the second letter: " << endl;
    cin >> c2; 
    cout << "Enter the third letter: " << endl;
    cin >> c3;
    if(c1 == 'J'||'j' && c2 == 'a' && c3 == 'n')
    {
        month = 1;
    } 
    else if(c1 == 'F'||'f' && c2 == 'e' && c3 == 'b')
    {
        month = 2;
    }   
    else if(c1 == 'M'||'m' && c2 == 'a' && c3 == 'r')
    {
        month = 3;
    }   
    else if(c1 == 'A'||'a' && c2 == 'p' && c3 == 'r')
    {
        month = 4;
    }   
    else if(c1 == 'M'||'m' && c2 == 'a' && c3 == 'y')
    {
        month = 5;
    }   
    else if(c1 == 'J'||'j' && c2 == 'u' && c3 == 'n')
    {
        month = 6;
    }   
    else if(c1 == 'J'||'j' && c2 == 'u' && c3 == 'l')
    {
        month = 7;
    }   
    else if(c1 == 'A'||'a' && c2 == 'u' && c3 == 'g')
    {
        month = 8;
    }   
    else if(c1 == 'S'||'s' && c2 == 'e' && c3 == 'p')
    {
        month = 9;
    }   
    else if(c1 == 'O'||'o' && c2 == 'c' && c3 == 't')
    {
        month = 10;
    }    
    else if(c1 == 'N'||'n' && c2 == 'o' && c3 == 'v')
    {
        month = 11;
    }    
    else if(c1 == 'D'||'d' && c2 == 'e' && c3 == 'c')
    {
        month = 12;
    }   
}
void Month::outputAsInteger()
{
    cout << "The month as an integer is:" << month << endl;
}
void Month::outputAsLetters()
{
    switch(month)
    {
        case 1:
        {
            cout << "The month as the first 3 letters: Jan" << endl;
            break;
        }
        case 2:
        {
            cout << "The month as the first 3 letters: Feb" << endl;
            break;
        } 
        case 3:
        {
            cout << "The month as the first 3 letters: Mar" << endl;
            break;
        }
        case 4:
        {
            cout << "The month as the first 3 letters: Apr" << endl;
            break;
        }
        case 5:
        {
            cout << "The month as the first 3 letters: May" << endl;
            break;
        }
        case 6:
        {
            cout << "The month as the first 3 letters: Jun" << endl;
            break;
        }
        case 7:
        {
            cout << "The month as the first 3 letters: Jul" << endl;
            break;
        }
        case 8:
        {
            cout << "The month as the first 3 letters: Aug" << endl;
            break;
        }
        case 9:
        {
            cout << "The month as the first 3 letters: Sep" << endl;
            break;
        }
        case 10:
        {
            cout << "The month as the first 3 letters: Oct" << endl;
            break;
        }
        case 11:
        {
            cout << "The month as the first 3 letters: Nov" << endl;
            break;
        }
        case 12:
            {
            cout << "The month as the first 3 letters: Dec" << endl;
            break;
        }
    }
}
int Month::getMonth()
{
    return month;
}
Month Month::nextMonth()
{
    int num = getMonth();
    if(num==12)
    {
        num = 1;
        return Month(num);
    }
    else
    {
        num = num + 1;
        return Month(num);
    }
}

int main()
{
    Month one;
    one.outputAsLetters();
    Month monthOfYear(10);
    char answer, l1, l2, l3;
    cout << "Would you like to enter the month as an integer(i) or as the first three letters(l)? Please enter i/l?" << endl;
    cin >> answer;
    if(answer=='i')
    {
        monthOfYear.inputAsInteger();
        monthOfYear.outputAsLetters();
    }
    if(answer=='l')
    {
        monthOfYear.inputAsLetters(l1, l2, l3);
        monthOfYear.outputAsInteger();
    }
    Month year = monthOfYear.nextMonth();
    cout << "Next Month- ";
    year.outputAsInteger();
    return 0;
}
