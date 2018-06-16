#include <iostream>
using namespace std;

template <class T>
void search(const T a[], int first, int last, T key, bool& found, int& location)
{
    int mid;
    if (first > last)
    {
        found = false;
    }
    else
    {
        mid = (first + last)/2;
        if (key == a[mid])
        {
            found = true;
            location = mid;
        }
        else if (key < a[mid])
        {
            search(a, first, mid - 1, key, found, location);
        }
        else if (key > a[mid])
        {
            search(a, mid + 1, last, key, found, location);
        }
    }
}

int main()
{
    const int ARRAY_SIZE = 10;
    cout << "TESTING AN INTEGER ARRAY" << endl;
    int a[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int finalIndex = ARRAY_SIZE - 1;
    int key, location;
    bool found;
    cout << "The values of the integer array are:" << endl;
    for(int i = 0; i <= finalIndex; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Enter a number to be searched: " << endl;
    cin >> key;
    search(a, 0, finalIndex, key, found, location);
    if(found)
    {
        cout << key << " is in index location " << location << endl;
    }
    else
    {
        cout << key << " is not in the array." << endl;
    }
    double arr[ARRAY_SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    double key2;
    cout << endl;
    cout << "TESTING A DOUBLE ARRAY" << endl;
    cout << "The values of the double array are:" << endl;
    for (int i = 0; i <= finalIndex; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter a number to be searched: " << endl;
    cin >> key2;
    search(arr, 0, finalIndex, key2, found, location);
    if(found)
    {
        cout << key2 << " is in index location " << location << endl;
    }
    else
    {
        cout << key2 << " is not in the array." << endl;
    }
    return 0;
}