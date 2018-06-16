#include <iostream>
#include "set.h"
using namespace main_savitch_11;
using namespace std;

int main()
{
    set<int> btree;
    cout << "After insertion: " << endl;
    btree.insert(2);
    btree.insert(3);
    btree.insert(5);
    btree.insert(4);
    btree.insert(10);
    btree.print(3);
    cout << "Searching for forty-five (1 for is present, 0 for not present): " << btree.count(45) << endl;
    cout << "Searching for five (1 for is present, 0 for not present): " << btree.count(5) << endl;
    btree.erase(4);
    cout << "After erasing 4: " << endl;
    btree.print(3);
    cout << "Inserting 10" << endl;
    if(btree.insert(10))
    {
        btree.print(3);
    }
    else
    {
        cout << "The value is already present!" << endl;
    }
    cout << "Inserting 100" << endl;
    btree.insert(100);
    btree.print(3);
    cout << "Removing 3" << endl;
    if(btree.erase(3))
    {
        btree.print(3);
    }
    else
    {
        cout << "The value is not in the set!" << endl;
    }
    return 0;
}
}