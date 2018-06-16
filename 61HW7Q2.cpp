#include <iostream>
#include <cstdlib>
using namespace std;

void insertion_sort(int data[], size_t n);

int main()
{
    const size_t ARRAY_SIZE = 10;
    int data[ARRAY_SIZE];
    int user_input;
    size_t number;
    size_t i;
    
    //Providing instructions
    cout << "Please enter up to " << ARRAY_SIZE << " positive integers." << endl;
    cout << "Indicate the list end with a zero." << endl;
    
    //Read the input numbers
    number = 0;
    cin >> user_input;
    while((user_input != 0) && (number < ARRAY_SIZE))
    {
        data[number] = user_input;
        ++number;
        cin >> user_input;
    }
    
    //Sorting the integers, and then printing the results
    insertion_sort(data, number);
    cout << "In sorted order, the integers are:" << endl;
    for(i = 0; i < number; ++i)
    {
        cout << data[i] << " " << " ";
    }
    cout << endl;
    
    return 0;
}

void insertion_sort(int data[], size_t n)
{
    size_t i;
    size_t j;
    size_t temp;
    
    for(i = 1; i < n; ++i)
    {
        temp = data[i];
        j = i;
        while((j > 0) && (temp < data[j - 1]))
        {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = temp;
    }
}