#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void readWords(char a[][4], vector<string> vec, int index, int vectorIndex);
void getWords(char a[][4], vector<string> vec, string word, int i, int j, int index, string str, int vectorIndex);

int main()
{
    int index;
    int vectorIndex = 0;
    char array[4][4];
    srand((unsigned) time(0));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            array[i][j] = (rand() % 24) + 'a';
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    string word;
    ifstream inStream;
    inStream.open("words.txt");
    if (inStream.fail()) 
    {
        cout << "Opening of file failed." << endl;
        exit(1);
    }
    vector<string> vec;
    inStream >> word;
    while(!inStream.eof()) 
    {
        vec.push_back(word);
        inStream >> word;
    }
    cout << endl;
    cout << "The words that are the same are:" << endl;
    readWords(array, vec, index, vectorIndex);
    inStream.close();
    return 0;
}

void readWords(char a[][4], vector<string> vec, int index, int vectorIndex)
{
    string str = " ";
    index = 0;
    //vectorIndex;
    string s = vec[vectorIndex];
    while ((index < s.length()) && (vectorIndex < vec.size()))
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(s[index] == a[i][j])
                {
                    str += s[index];
                    index++;
                    getWords(a, vec, s, i, j, index, str, vectorIndex);
                }
                else
                {
                    vectorIndex++;
                }
                if(vectorIndex == vec.size())
                {
                    cout << "NO WORDS LEFT TO MATCH" << endl;
                    exit(1);
                }
            }
        }
    }
}

void getWords(char a[][4], vector<string> vec, string s, int i, int j, int index, string str, int vectorIndex)
{
    if(index == vec.size()-1)
    {
        cout << "END OF FILE!" << endl;
        exit(1);
    }
    else
    {   
        if((index < s.length()) && (i <= 3) && (i >= 0) && (j <= 3) && (j >= 0))
        {
            if(s[index] == (a[i][j-1]) && (j != 0))
            {
                i = i;
                j = j-1;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i-1][j]) && (i != 0))
            {
                i = i-1;
                j = j;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i-1][j+1]) && (i != 0) && (j != 3))
            {
                i = i-1;  
                j = j+1;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i-1][j-1]) && (i != 0) && (j != 0))
            {
                i = i-1;
                j = j-1;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i+1][j]) && (i != 3))
            {
                i = i+1;
                j = j;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i][j+1]) && (j != 3))
            {
                i = i;
                j = j+1;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i+1][j+1])  && (i != 3) && (j != 3))
            {
                i = i+1;
                j = j+1;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
            else if((s[index] == a[i+1][j-1]) && (i != 3) && (j != 0))
            {
                i = i+1;
                j = j-1;
                str += s[index];
                index++;
                if(index < s.length())
                getWords(a, vec, s, i, j, index, str, vectorIndex);
            }
        }
            if(vec[vectorIndex] == str)
            {
                cout << str << endl;
                readWords(a, vec, index, vectorIndex);
            }
            else
            {
                vectorIndex++;
                readWords(a, vec, index, vectorIndex);
            }
        }
    }

