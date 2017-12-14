#include <iostream>
#include <cmath>
using namespace std;

double stddev(double a[], int& size);

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    double result;
    double array[n];
    cout << "Enter the numbers to find the standard deviation: " << endl;
    for (int index = 0; index < n; index++)
    {
        cin >> array[index];
    }
    result = stddev(array, n);
    cout << "The standard deviation is: " << result << endl;
    return 0;
}

double stddev(double a[], int& size)
{
    double m, total = 0, S=0, answer, difference;
    for(int i = 0; i < size; i++)
    {
        total += a[i];
    }
    m = total/size;
    for(int j = 0; j < size; j++)
    {
        difference = a[j] - m;
        S += pow(difference, 2);
    }
    answer = sqrt(S/size);
    return answer;
}

