#include <iostream>
using namespace std;

const int SIZE = 20;

int main()
{
    int array1[SIZE];
    int array2[SIZE];
    char temp1[SIZE];
    char temp2[SIZE];
    for (int w = 0; w < SIZE; w++)
    {
        temp1[w] = '0';
        temp2[w] = '0';
        array1[w] = 0;
        array2[w] = 0; 
    }
    int size1, size2;
    char answer;
    
    do
    {
    cout << "Enter the number of digits for the first integer:" << endl;
    cin >> size1;
    
    cout << "Enter an integer containing " << size1 << " digits: " << endl;
    for(int i = 0; i < size1; i++)
    {
        cin >> temp1[i];
    }
    
    cout << "Enter the number of digits for the second integer:" << endl;
    cin >> size2;
    cout << "Enter another integer containing " << size2 << " digits: " << endl;
    
    int index1 = 0, index2=0;
    for(int j = 0; j < size2; j++)
    {
        cin >> temp2[j];
    }
    
    for(int k = size1-1; k >=0; k--)
    {
        array1[k] = temp1[k] - '0';
        index1++;
    }
    
    for(int l = size2-1; l >=0; l--)
    {
        array2[l] = temp2[l] - '0';
        index2++;
    }
    
    int carry = 0, temp = 0;
    int sum[SIZE];
    for (int n = 0; n < SIZE; n++)
    {
        sum[n] = 0;
    }
    if (size1 > size2)
    {
        for(int b = size2; b < size1; b++ )
        {
            array2[b] = 0;
        }
    for (int x = 0; x < size1; x--)
    {
        temp = array1[x] + array2[x] + carry;
        if (temp >= 10)
        {
            sum[x] = temp % 10;
            carry = temp/10;
        }
        else
        {
            sum[x] = temp;
        }
    }
    }
    else
    {
        for(int c = size1; c < size2; c++ )
        {
            array1[c] = 0;
        }
    }
    for (int t = 0; t < size1; t--)
    {
        temp = array1[t] + array2[t] + carry;
        if (temp >= 10)
        {
            sum[t] = temp % 10;
            carry = temp/10;
        }
        else
        {
            sum[t] = temp;
        }
    }
    
    for (int a = 0; a = 0;)
    {
        if (sum[0] > 9)
        {
            cout << "Integer Overflow!" << endl;
        }
        
    }
    cout << "Sum is: " << endl;
    for (int y = 19; y > 0; y--)
    {
        cout << sum[y];
    }
    cout << endl;
    cout << "Would you like to do the addition again?(Type y(yes)or n(no)): " << endl;
    cin >> answer;
    }while((answer == 'y') || (answer == 'Y'));
    return 0;
}