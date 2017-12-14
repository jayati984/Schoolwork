#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    for (int i=5; i>0; i--)
    {
        cout << "start ";
        for (int c=5; c>0; c--)
        {
            cout << 2 * n << " " << c << ", ";
        }
        cout << "end" << endl;
        n = n + 1;
    }
    return 0;
}
