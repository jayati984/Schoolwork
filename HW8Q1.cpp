#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void newFile(ifstream& input1, ifstream& input2, ofstream& output);

int main()
{
    ifstream inStream1;
    inStream1.open("infile1.txt");
    if(inStream1.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    ifstream inStream2;
    inStream2.open("infile2.txt");
    if(inStream2.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    
    ofstream outStream;
    outStream.open("outfile.txt");
    if(outStream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    newFile(inStream1, inStream2, outStream);
    
    return 0;
}

void newFile(ifstream& input1, ifstream& input2, ofstream& output)
{
    int number[100];
    int i = 0;
    while(input1 >> number[i])
    {
        i++;
    }
    while(input2 >> number[i])
    {
        i++;
    }
    input1.close();
    input2.close();
    
    for(int j = i-1; j > 0; j--)
    {
        for(int k = 0; k < j; k++)
        {
            if(number[k] > number[k+1])
            {
                int temp = number[k+1];
                number[k+1] = number[k];
                number[k] = temp;
            }
        }
    }
    for(int x = 0; x < i; x++)
    {
        output << number[x] << endl;
    }
    output.close();
}