#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int words = 1, count[26], index = 0;;
    string line;
    char letter[] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cout << "Enter a line of text: " << endl;
    getline(cin, line);
    for(int i = 0; i < line.length(); i++)
    {
        if(line[i] == ' ')
        {
            words++;
        }
    }
    
    for(int m = 0; m < line.length(); m++)
    {
            line[m] = tolower(line[m]);
    }
    
    
    for (int l = 0; l < 26; l++)
    {
        count[l] = 0;
    }
    
    for(int k = 0; k < line.length(); k++)
    {
            while(line.at(k) != letter[index])
            {
                index++;
            }
            count[index]++;
            index=0;
    }
    
    cout << words << " Words" << endl;
    for(int h = 0; h < 26; h++)
    {
        if (count[h] != 0)
        {
            cout << letter[h] << "\t" << count[h] << endl;
        }
    }
    return 0;
}