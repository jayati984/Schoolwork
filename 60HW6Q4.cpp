#include <iostream>
#include <ctime>
using namespace std;

int fibonacciIterative(int n);
int fibonacciRecursive(int n);

int main()
{
    clock_t start1;
    clock_t start2;
    clock_t end1;
    clock_t end2;
    
    int number, result, result2;
    cout << "Enter a number to find the nth Fibonacci number: " << endl;
    cin >> number;
    
    cout << "ITERATIVE" << endl;
    start1 = clock();
    result = fibonacciIterative(number);
    end1 = clock();
    cout << "The Fibonacci number of " << number << " is " << result << endl;
    double dif1 = double(end1 - start1)/CLOCKS_PER_SEC*1000;
    cout << "Time: " << dif1 << " seconds" << endl;
    
    cout << "RECURSIVE" << endl;
    start2 = clock();
    result2 = fibonacciRecursive(number);
    end2 = clock();
    cout << "The Fibonacci number of " << number << " is " << result << endl;
    double dif2 = double(end2 - start2)/CLOCKS_PER_SEC*1000;
    cout << "Time: " << dif2 << " seconds" << endl;
    return 0;
}

int fibonacciIterative(int n)
{
    if ((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        int current;
        int previous2 = 1;
        int previous1 = 1;
        for(int index = 2; index <= n; index++)
        {
            current = previous1 + previous2;
            previous2 = previous1;
            previous1 = current;
        }
        return current;
    }
}

int fibonacciRecursive(int n)
{
    if((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        return(fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2));
    }
}