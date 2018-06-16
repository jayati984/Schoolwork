#include "table2.h"
#include <iostream>
#include <cstdlib>

using namespace main_savitch_12B;

struct RecordType
{
    int key;
};

int main()
{
    table<RecordType> hash;
    RecordType r1;
    r1.key = 811;
    RecordType r2;
    r2.key = 1622;
    RecordType r3;
    r3.key = 811;
    RecordType r4;
    r4.key = 800;
    RecordType r5;
    r5.key = 711;
    RecordType r6;
    r6.key = 400;
    hash.insert(r1);
    hash.insert(r2);
    hash.insert(r3);
    hash.insert(r4);
    hash.insert(r5);
    hash.insert(r6);
    hash.print();
    hash.remove(400);
    //hash.print();
    return 0;
}