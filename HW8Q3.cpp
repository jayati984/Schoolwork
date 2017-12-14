#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

void grades(ifstream& inStream1, ofstream& outStream1);
void copy(ifstream& inStream2, ofstream& outStream2);

int main()
{
    ifstream inStream;
    ofstream outStream;
    
    inStream.open("gradesQ3.txt");
    if(inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outStream.open("recordsQ3.txt");
    if(outStream.fail())
    {
        cout << "Output file opening failed.\n";
    }
    
    grades(inStream, outStream);
    
    inStream.close();
    outStream.close();
    
    ifstream inStream2;
    ofstream outStream2;
    
    inStream2.open("recordsQ3.txt");
    if(inStream2.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    outStream2.open("gradesQ3.txt");
    if(outStream2.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    
    copy(inStream2, outStream2);
    
    inStream2.close();
    outStream2.close();
    
    return 0;
}

void grades(ifstream& inStream1, ofstream& outStream1)
{
    outStream1 << "This program will compute the average of each student's quiz scores out of 10." << endl;
    string firstname, lastname;
    int scores;
    char next;
    while (!inStream1.eof())
    {
        double total = 0;
        inStream1 >> lastname;
        outStream1 << setw(12) << lastname;
        inStream1 >> firstname;
        outStream1 << setw(16) << firstname;
        do
        {
            inStream1 >> scores;
            outStream1 << setw(8) << scores;
            total += scores;
            inStream1.get(next);
        }while((next != '\n') && (!inStream1.eof()));
        
        double average = 0;
        average = total/10;
        
        outStream1 << setw(16) << " Average:" << average << endl;
    }
}

void copy(ifstream& inStream2, ofstream& outStream2)
{
    char next;
    while(!inStream2.eof())
    {
        inStream2.get(next);
        outStream2 << next;
    }
}
