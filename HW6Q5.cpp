#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void ConvertStringToInteger(string& lineParameter);

int main()
{
    string line;
    int result;
    cout << "Enter a string:" << endl;
    getline(cin, line);
    ConvertStringToInteger(line);
    
    return 0;
}

void ConvertStringToInteger(string& lineParameter)
{
    int number;
    cout << "The integer is:" << endl;
    for(int i = 0; i < lineParameter.length(); i++)
    {
        number = ((static_cast<int>(lineParameter[i])) - '0');
        cout << number;
    }
    cout << endl;
}

