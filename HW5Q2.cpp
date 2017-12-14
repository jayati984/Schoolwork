#include <iostream>
using namespace std;

const int DECLARED_SIZE = 100;
void fillArray(char array[], int& sizeParameter);
void deleteRepeats(char array[], int& sizeParameter);

int main()
{
    int size;
    char a[DECLARED_SIZE];
    fillArray(a, size);
    deleteRepeats(a, size);
    return 0;
}

void fillArray(char array[], int& sizeParameter)
{
    cout << "How many letters would you like to input? " << endl;
    cin >> sizeParameter;
    cout << "Enter up to " << sizeParameter << " letters." << endl;
    int index =0;
    while (index < sizeParameter)
    {
    cin >> array[index];
    index++;
    }
}

void deleteRepeats(char array[], int& sizeParameter)
{
    for(int i = 0; i < sizeParameter; i++)
    {
        for(int j = i + 1; j < sizeParameter;)
        {
            if(array[i] == array[j])
            {
                array[j] = array[j + 1];
                sizeParameter--;
            }
            else
            {
                j++;
            }
        }
    }
    cout << "\n" << "The new array is: " << endl;
    for( int k = 0; k < sizeParameter; k++)
    {
    cout << array[k] << endl;
    }
    cout << "The new value of size is: " << sizeParameter << endl;
}


