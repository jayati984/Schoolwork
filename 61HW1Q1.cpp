#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stack>
#include <cctype>
using namespace std;

void InfixToPrefix();
void PrefixToInfix();

int main()
{
    InfixToPrefix();
    cout << endl;
    PrefixToInfix();
    return 0;
}

void InfixToPrefix()
{
    // infix: ( ( ( A + 7 ) * ( B / C ) ) - ( 2 * D ) )
    // prefix: - * + A 7 / B C * 2 D
    const char LEFT_PARENTHESIS = '(';
    const char RIGHT_PARENTHESIS = ')';
    stack<char> operations;
    char next;
    string str2 = "";
    string str1;
    cout << "Enter an infix expression:" << endl;
    getline(cin, str1);
    int i = str1.length() - 1; //index to string;
    do
    {
        next = str1[i];
        if(next == RIGHT_PARENTHESIS)
        {
           operations.push(next);
           i--;
        }
        else if(isdigit(next) || isalpha(next))
        {
            if((isdigit(next)) && (isdigit(str1[i-1])) && (i>0))
            {
                str2 = str2 + " " + next + str1[i-1] + " ";
                i--;
                i--;
            }
            else
            {
                str2 = str2 + " " + next + " ";
                i--;
            }
        }
        else if(isspace(next))
        {
            i--;
        }
        else if((next == '+') || (next == '-') || (next == '*') || (next == '/'))
        {
            operations.push(next);
            i--;
        }
        else // left parenthesis
        {
            str2 =  str2 + " " + operations.top() + " ";
            operations.pop();
            if (operations.top() == RIGHT_PARENTHESIS)
            {
                operations.pop(); //right parenthesis
            }
            else
            {
                cout << "The input did not have balanced parenthesis." << endl;
            }
            i--;
        }
    }while(i >= 0);
    if (!(operations.empty()))
    {
        cout << "Expression was not fully parenthesized." << endl;
    }
    cout << "The prefix version:" << endl;
    for (int j = str2.length()-1; j >= 0; j--)
    {
        cout << str2[j];
    }
    cout << endl;
    
    /*cout << "Evaluation of prefix notation:" << endl;
    double operand1, operand2;
    stack<double> numbers;
    int k = str2.length() - 1;
    do
    {
        next = str2[k];
        if(isdigit(next))
        {
            numbers.push(next);
        }
        else if((next == '+') || (next == '-') || (next == '*') || (next == '/'))
        {
            operand1 = numbers.top();
            numbers.pop();
            operand2 = numbers.top();
            numbers.pop();
            switch(next)
            {
                case '+': numbers.push(operand1 + operand2);
                    break;
                case '-': numbers.push(operand1 - operand2);
                    break;
                case '*': numbers.push(operand1 * operand2);
                    break;
                case '/': numbers.push(operand1 / operand2);
                    break;
            }
        }
        k--;
    }while(k >= 0);
    cout << numbers.top() << endl;
    numbers.pop();
    if (!(operations.empty()))
    {
        cout << "Expression was not fully parenthesized." << endl;
    }*/
}
void PrefixToInfix()
{
    char next;
    stack<string> s;
    string str2, str3, str4;
    string str1, temp;
    cout << "Enter a prefix expression:" << endl;
    getline(cin, str1);
    int i = str1.length() - 1; //index to string;
    do
    {
        next = str1[i];
        if(isdigit(next) || isalpha(next))
        {
            if((isdigit(next)) && (isdigit(str1[i-1])) && (i>0))
            {
                temp = str1.substr(i-1, 1) + str1.substr(i, 1) ;
                s.push(temp);
                i--;
                i--;
            }
            else
            {
                temp = str1.substr(i, 1);
                s.push(temp);
                i--;
            }
        }
        else if((next == '+') || (next == '-') || (next == '*') || (next == '/'))
        {
            str2 = s.top();
            s.pop();
            str3 = s.top();
            s.pop();
            str4 = ("(" + str2 + next + str3 + ")");
            s.push(str4);
            i--;
        }
        else if(isspace(next))
        {
            i--;
        }
    }while(i >= 0);
    cout << "The infix version:" << endl;
    cout << s.top() << endl;
    s.pop();
}