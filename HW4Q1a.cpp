#include <iostream>
using namespace std;

int main()
{
    for (int i=1; i<=5; i++)
    {
        cout << "start ";
        for (int c=1; c<=8; c++)
        {
            if ((c<=i) && (c>0))
            {
                cout <<"o";
            }
            else 
            {
                cout <<"x";
            }
        }
        cout << " end" << endl;
    }
    return 0;
}
