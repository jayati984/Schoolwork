#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 50;

void fillArray(int a[], int size, int& numberUsed);
void sort(int a[], int numberUsed);
void swapValues (int& v1, int& v2);
int indexOfBiggest(const int a[], int startIndex, int numberUsed);
void deleteRepeats(int a[], int& numberUsed, int repeats[]);

int main()
{
    int size;
    int repeats[SIZE];
    int array[SIZE], numberUsed;
    std::fill_n(repeats, size, 1);
    fillArray(array, size, numberUsed);
    sort(array, numberUsed);
    deleteRepeats(array, numberUsed, repeats);
    
    cout << "N\t COUNT" << endl;
    for(int ind = 0; ind < numberUsed; ind++)
    {
        cout << array[ind] << "\t" << repeats[ind] << endl;
    }
    return 0;
}
void fillArray(int a[], int size, int& numberUsed)
{
    cout << "Enter the number of integers you would like to input: " << endl;
    cin >> size;
    cout << "Enter up to " << size << " integers.\n";
    int next, index;
    for (int index = 0; index < size; index++)
    {
        cin >> next;
        a[index] = next;
    }
    numberUsed = index;
}
void sort(int a[], int numberUsed)
{
    int indexofNextBiggest;
    for(int index = 0; index < numberUsed -1; index++)
    {
        indexofNextBiggest=indexOfBiggest(a, index, numberUsed);
        swapValues(a[index], a[indexofNextBiggest]);
    }
}
void swapValues(int& v1, int& v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 =temp;
}
int indexOfBiggest(const int a[], int startIndex, int numberUsed)
{
    int max = a[startIndex], indexOfMax = startIndex;
    for (int index = startIndex +1; index , numberUsed; index++)
    {
        if(a[index] < max)
        {
            max = a[index];
            indexOfMax = index;
        }
    }
    return indexOfMax;
}
void deleteRepeats(int a[], int& numberUsed, int repeats[])
{
    for(int i = 0; i < numberUsed; i++)
    {
        for(int j = i + 1; j < numberUsed; j++)
        {
            if(a[i] == a[j])
            {
                a[j] = a[j + 1];
            }
            j--;
            numberUsed--;
            repeats[i]++;
        }
    }
}