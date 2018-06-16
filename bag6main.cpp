#include <iostream>
#include <cassert>
#include "bintree.h"
#include "bag6.h"
using namespace main_savitch_10;
using namespace std;

int main()
{
    binary_tree_node<int>* root_ptr = new binary_tree_node<int>(5, NULL, NULL);
    binary_tree_node<int>* current_ptr = new binary_tree_node<int>(2, NULL, NULL);
    current_ptr->set_left(new binary_tree_node<int>(2, NULL, NULL));
    current_ptr->set_right(new binary_tree_node<int>(4, NULL, NULL));
    root_ptr->set_left(current_ptr);
    current_ptr = new binary_tree_node<int>(7, NULL, NULL);
    root_ptr->set_right(current_ptr);
    /*root_ptr->insert(8);
    root_ptr->insert(3);
    cout << root_ptr->erase(4) << endl;
    cout << root_ptr->erase_one(2) << endl;
    cout << root_ptr->size() << endl;
    cout << root_ptr->count(2) << endl;*/
    bag<int> tree1;
    tree1.insert(1);
    tree1.insert(2);
    bag<int> tree2;
    tree2.insert(3);
    tree2.insert(3);
    bag<int> tree3;
    tree3.insert(4);
    tree3.insert(5);
    cout << tree1.erase(1) << endl;
    cout << tree1.erase_one(2) << endl;
    cout << tree3.size() << endl;
    cout << tree1.count(2) << endl;
    return 0;
}