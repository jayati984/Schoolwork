#include <iostream>
#include <ctime>
using namespace std;

int fibonacci(int N);

int main()
{
    clock_t start;
    clock_t end;
    int answer;
    int result;
    cout << "Enter an integer to find the nth Fibonacci number: " << endl;
    cin >> answer;
    start = clock();
    result = fibonacci(answer);
    end = clock();
    cout << "The " << answer << "th Fibonacci number is: " << result << endl;
    double dif1 = double(end - start)/ CLOCKS_PER_SEC*1000;
    cout << "Time: " << dif1 << " seconds" << endl;
    return 0;
}

int fibonacci(int N)
{
    int array[N];
    int index = N + 1;
    if((N == 0) || (N == 1))
    {
        return 1;
    }
    else
    {
        index--;
        array[index] = fibonacci(N - 1) + fibonacci(N - 2);
        return(array[index]);
    }
}

// PART B