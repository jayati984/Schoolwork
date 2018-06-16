#include "WordSearch.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int rows = 1782;//1782
    int columns = 37;//37
    ifstream instream;
    instream.open("words.txt");//words.txt
    if(instream.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }
    
    unordered_set<string> table;
    unordered_set<string>:: iterator iter;
    string s;
    while(!instream.eof())
    {
        instream >> s;
        table.insert(s);
    }
    
    /*ofstream outstream;
    outstream.open("WordSearchResults.txt");
    if(outstream.fail())
    {
        cout << "Output file opening failed." << endl;
        exit(1);
    }*/
    
    bool end = false;
    Word* grid = new Word(rows, columns);
    grid->givePositions(end);
    string str2;
    for(iter = table.begin(); iter != table.end(); iter++)
    {
        str2 = *iter;
        grid->findWord(str2);
        /*if((!found) && (str2.length() >= 6))
        {
            outstream << *iter << endl;
        }*/
    }
    
    instream.close();
    //outstream.close();
    return 0;
}