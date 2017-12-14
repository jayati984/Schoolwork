#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void grades(ifstream& inStream1, ofstream& outStream1);

int main()
{
    ifstream inStream;
    ofstream outStream;
    
    inStream.open("gradesQ2.txt");
    if(inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outStream.open("recordsQ2.txt");
    if(outStream.fail())
    {
        cout << "Output file opening failed.\n";
    }
    
    grades(inStream, outStream);
    
    inStream.close();
    outStream.close();
    return 0;
}

void grades(ifstream& inStream1, ofstream& outStream1)
{
    string firstname, lastname;
    int scores[10];
    while (!inStream1.eof())
    {
        double total = 0;
        inStream1 >> lastname;
        inStream1 >> firstname;
        for(int i = 0; i < 10; i++)
        {
            inStream1 >> scores[i];
            total += scores[i];
        }
    outStream1 << lastname << " " << firstname << " ";
    for (int j = 0; j < 10; j++)
    {
        outStream1 << scores[j] << " ";
    }
    outStream1 << total/10 << endl;
    }
}