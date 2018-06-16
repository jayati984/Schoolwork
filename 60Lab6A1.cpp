#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
int count_exact (T1 a[], T2 size, T1 find)
{
    int count = 0;
    for(T2 i = 0; i < size; i++)
    {
        if(a[i] == find)
        {
            count++;
        }
    }
    return count;
}

template<typename T1, typename T2>
int count_range(T1 a[], T2 size, T1 low, T1 high)
{
    int count = 0;
    for(T2 i = 0; i < size; i++)
    {
        if((a[i] >= low) && (a[i] <= high))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[6] = {6, 2, 3, 2, 6, 2};
    int result = count_exact(arr, 6, 3);
    cout << "The result is:" << result << endl;
    string array[6] = {"aa", "bb", "cc", "dd", "ee", "ff"};
    string var = "cc";
    int result2 = count_exact(array, 6, var);
    cout << "The result is:" << result2 << endl;
    int result3 = count_range(arr, 6, 2, 4);
    cout << "The result is:" << result3 << endl;
    string var1 = "aa";
    string var2 = "ff";
    int result4 = count_range(array, 6, var1, var2);
    cout << "The result is:" << result4 << endl;
    return 0;
}
