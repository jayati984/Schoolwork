#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int z;
    cout << "How many suitors are there for Princess Eve?" << endl;
    cin >> z;
    vector<int> v(z);
    cout << "Initial list of suitors:" << endl;
    for (unsigned int index = 0; index < v.size(); index++)
    {
        v[index] = index + 1;
        cout << v[index] << " ";
    }
    cout << endl;

    cout << "The elimination process:" << endl;
    int number = 1;
    int x = 2;
    while (v.size() > 1)
    {
        v.erase(v.begin() + x);
        cout << "Number of suitors eliminated:" << number << endl;
        number++;
        for (int j = 0; j < v.size(); j++)
        {
            if (v.size() == 1)
            {
                cout << "The lucky winner is:" << v[0] << endl;
            }
            else 
            {
                cout << v[j] << " ";
            }
        }
        cout << endl;
        x = x + 2;
        if (x > v.size()-1)
        {
            v.begin();
            x = x - v.size();
        }
    }
    
    return 0;
}