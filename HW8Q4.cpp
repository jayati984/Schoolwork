#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cctype>
using namespace std;

void count(ifstream& inStream1);

int main()
{
    ifstream inStream;
    inStream.open("wordsQ4.txt");
    if(inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    count(inStream);
    
    inStream.close();
    
    return 0;
}

void count(ifstream& inStream1)
{
    string line;
    int numberOfCharacters = 0;
    int numberOfWords = 0;
    while(!inStream1.eof())
    {
        numberOfWords++;
        getline(inStream1, line);
        
        for(int i = 0; i < line.length(); i++)
        {
            if(!isspace(line[i]) || !ispunct(line[i]))
            {
                numberOfCharacters++;
            }
            if(isspace(line[i]))
            {
                numberOfWords++;
            }
        }
    }
    double average;
    average = numberOfCharacters/numberOfWords;
    cout << "The average number word length is: " << average << endl;
}