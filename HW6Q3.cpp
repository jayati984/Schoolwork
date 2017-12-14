#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;
void bubblesort(string array[], int index);

int main()
{
    ifstream inStream;
    inStream.open("CD.txt");
    string str;
    string a[100];
    int index = 0, x = 0;
    while(getline(inStream, str))
    {
    int count = 0, number = 0;
    
    for(int i = 0; i < str.length(); i++)
    {
        if((ispunct(str[i])) || (isdigit(str[i])) || (isspace(str[i])))
        {
            str.erase(i, 1);
            i--;
        }
        else if(isalpha(str[i]))
        {
            break;
        }
    }
    for(int j = 0; j < str.length()-1; j++)
    {
        if((isspace(str[j])) && (isspace(str[j+1])))
        {
            str.erase(j+1, 1);
        }
    }
    for(int k = 0; k < str.length(); k++)
    {
        if (str.at(k) == '-')
        {
            count++;
        }
    }
    for(int l = 0; l < str.length(); l++)
    {
        if (number < count - 1)
        {
            if(str.at(l) == '-')
            {
                str.erase(l, 1);
                str.insert(l, " ");
                number++;
            }
        }
    }
    for(int m = str.length() - 1; m >= 0; m--)
    {
        if (str.at(m) == '-' && str.at(m-1) != ' ')
        {
            str.insert(m, " ");
            break;
        }
    }
    string words;
    if(str.substr(0, 3) == "The")
    {
        words = "The";
        str.erase(0, 4);
    }
    else if(str.substr(0, 2) == "An")
    {
        words = "An";
        str.erase(0, 3);
    }
    else if(str.substr(0, 1) == "A")
    {
        words = "A";
        str.erase(0, 2);
    }
    int dashIndex = -1;
    for(int z = 0; z < str.length(); z++)
    {
        if(str.at(z) == '-')
        {
            dashIndex = z;
            break;
        }
    }
    str = str.substr(0, dashIndex) + words + str.substr(dashIndex, str.length() - dashIndex);
    int composerIndex = -1;
    dashIndex = -1;
    for(int p = str.length()-1; p >= 0; p--)
    {   
        if (str.at(p) == '-')
        {
            dashIndex = p;
            if(str.at(p+1) == ' ')
            {
                composerIndex = p + 2;
            }
            else
            {
                composerIndex = p + 1;
            }
            break;
        }
    }
    string temp = (str.substr(composerIndex, str.length() - composerIndex));
    str.erase(dashIndex, str.length() - dashIndex);
    str = temp + " - " + str;

    string name = temp;
    if (name != "no author listed")
    {
        int lastNameIndex = -1;
        for(int q = name.length() - 1; q >= 0; q--)
        {
            if(isspace(str[q]))
            {
                lastNameIndex = q +1;
                break;
            }
        }
        string lastName = name.substr(lastNameIndex, name.length() - lastNameIndex);
        name.erase(lastNameIndex, name.length() - lastNameIndex);
        for(int r = 0; r < str.length(); r++)
        {
            if (str.at(r) == '-')
            {
                dashIndex = r;
                break;
            }
        }
        str.erase(0, dashIndex);
        str = lastName + ", " + name + str;
    }
    
    a[x] = str;
    x++;
    index++;
    }
    bubblesort(a,index);
    
    for(int k = 0; k < index; k++)
    {
        cout << a[k] << endl;
    }
    inStream.close();
    return 0;
}

void bubblesort(string array[], int index)
{
    for(int i = index-1; i>0; i--)
    {
        for(int j = 0; j<i; j++)
        {
            if(array[j]>array[j+1])
            {
                string temp = array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }
}