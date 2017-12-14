#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removevowels(string s);

int main()
{
    string line;
    string newString;
    cout << "Enter a line of text:" << endl;
    getline(cin, line);
    newString = removevowels(line);
    cout << newString << endl;
    return 0;
    
}

string removevowels(string s)
{
    string s2;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] != 'a')&&(s[i] != 'e')&&(s[i] != 'i')&&(s[i] != 'o')&&(s[i] != 'u')&&(s[i] != 'A')&&(s[i] != 'E')&&(s[i] != 'I')&&(s[i] != 'O')&&(s[i] != 'U'))
        {
            s2 += s[i];
        }
    }
    return s2;
}
