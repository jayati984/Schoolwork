#include <iostream>
using namespace std;

float choosing(int n, int r);
float factorial(int n);

int main()
{
    int answer1, answer2;
    float result;
    cout << "Enter a number for the size of the set: " << endl;
    cin >> answer1;
    cout << "Enter the number of different items to be chosen: " << endl;
    cin >> answer2;
    result = choosing(answer1, answer2);
    cout << "Therefore C(" << answer1 << ", " << answer2 << ") = " << result << endl;
    return 0;
}
float factorial(int n)
{
    if((n == 0) || (n == 1))
    {
        return 1;
    }
    else
    {
        return(n * factorial(n - 1));
    }
}
float choosing(int n, int r)
{
    if(n == r)
    {
        return 1;
    }
    else if(r == 0)
    {
        return 1;
    }
    else 
    {
        return((factorial(n)) / (factorial(r) * factorial(n-r)));
    }
}