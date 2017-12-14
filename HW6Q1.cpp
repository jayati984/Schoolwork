#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAXCHARACTERS = 100;
int main()
{
    int last;
    string line;
    cout << "Enter a line of input containing 100 characters:\n ";
    if (line.length() > MAXCHARACTERS)
    {
        cout << "Input too long!" << endl;
    }
    else
    {
        getline(cin, line);
        line[0] = toupper(line[0]);
        last = line.length();
        line[last-1] = '.';
        for (int x = 1; x < last; x++)
        {
            line[x] = tolower(line[x]);
        }
        for (int k = 0; k < last-1; k++)
        {
            if((isspace(line[k])) && (isspace(line[k+1])))
                {
                    line.erase(k, 1);
                }
        }
        cout << line << endl;
    }
    
    return 0;
}

