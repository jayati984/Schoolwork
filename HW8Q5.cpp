#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void correct(ifstream& inStream1, ofstream& outStream1);

int main()
{
    ifstream inStream;
    ofstream outStream;
    inStream.open("incorrectQ5.txt");
    if(inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outStream.open("correctQ5.txt");
    if(outStream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    correct(inStream, outStream);
    
    inStream.close();
    outStream.close();
    
    return 0;
}

void correct(ifstream& inStream1, ofstream& outStream1)
{
    string str;
    while(getline(inStream1, str))
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                if(str[i-1]=='n' && str[i-2]=='i' && str[i-3]=='c')
                {
                    str[i+1] = '>';
                    str[i+2] = '>';
                }
                else if(str[i-1]=='t' && str[i-2]=='u' && str[i-3]=='o' && str[i-4]=='c')
                {
                    str[i+1] = '<';
                    str[i+2] = '<';
                }
            }
            outStream1 << str[i];
        }
    }
}
