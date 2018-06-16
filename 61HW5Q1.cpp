#include <iostream>
#include "bintree.h"
#include "bag6.h"
using namespace main_savitch_10;
using namespace std;

int main()
{
    bag<char> searchTree;
    searchTree.insert('S');
    searchTree.print(searchTree, 0);
    searchTree.insert('F');
    searchTree.print(searchTree, 0);
    searchTree.insert('E');
    searchTree.print(searchTree, 0);
    searchTree.insert('V');
    searchTree.print(searchTree, 0);
    searchTree.insert('D');
    searchTree.print(searchTree, 0);
    searchTree.insert('U');
    searchTree.print(searchTree, 0);
    searchTree.insert('J');
    searchTree.print(searchTree, 0);
    searchTree.insert('P');
    searchTree.print(searchTree, 0);
    searchTree.insert('O');
    searchTree.print(searchTree, 0);
    searchTree.insert('T');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('S');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('F');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('E');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('V');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('D');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('U');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('J');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('P');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('O');
    searchTree.print(searchTree, 0);
    searchTree.erase_one('T');
    searchTree.print(searchTree, 0);
    return 0;
}