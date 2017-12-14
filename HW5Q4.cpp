#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array less than 50: " << endl;
    cin >> size;
    int array[size];
    
    for(int index = 0; index < size; index++)
    {
        cout << "Enter an integer:" << endl;
        cin >> array[index];
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;            
            }
        }
    }
    
    cout << "N\tCOUNT" << endl;
    int count = 1, previous = array[0];
    for (int k = 1; k < size; k++)
    {
        int current = array[k];
        if (current == previous)
        {
            count++;
        }
        else
        {
            cout << previous << "\t" << count;
            cout << endl;
            previous = current;
            count = 1;
        }
        if(k==size-1)
        {
            cout << previous << "\t" << count;
            cout << endl;
        }
        
    }
    
    return 0;
}
