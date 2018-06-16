#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cout << "Please enter a string less than 100 characters." << endl;
    cin.getline(str, 100);
    char* p1;
    char* p2;
    char temp;
    int index = 0;
    p1 = &str[0];
    p2 = &str[strlen(str)-1];
    
    while (p1 < p2)
    {
        temp = str[index];
        str[index] = *p2;
        *p2 = temp;
        p1++;
        p2--;
        index++;
    }
    
    cout << "The reversed string is:" << endl;
    cout << str << endl;
    return 0;
}