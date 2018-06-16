#include <iostream>
using namespace std;

int fibonacci(int n);

int main()
{
    int answer;
    int result;
    cout << "Enter an integer to find the nth Fibonacci number: " << endl;
    cin >> answer;
    result = fibonacci(answer);
    cout << "The " << answer << "th Fibonacci number is: " << result << endl;
    return 0;
}

int fibonacci(int n)
{
    if((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        return(fibonacci(n - 1) + fibonacci(n - 2));
    }
}