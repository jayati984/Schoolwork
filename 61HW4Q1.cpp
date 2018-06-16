#include <iostream>
#include "bintree.h"
using namespace std;
using namespace main_savitch_10;
//heapifying to form a max-heap
void preorder(binary_tree_node<int>* root_ptr);
void heapify(binary_tree_node<int>* root_ptr, binary_tree_node<int>* child_ptr);

int main()
{
    binary_tree_node<int>* pointer = NULL;
    binary_tree_node<int>* another = NULL;
    //creating root node
    pointer = new binary_tree_node<int>(1);
    //creating left subtree
    another = new binary_tree_node<int>(2);
    another->set_left(new binary_tree_node<int>(8));
    another->set_right(new binary_tree_node<int>(10));
    //setting left subtree to left chiild of root node
    pointer->set_left(another);
    //creating right subtree
    another = new binary_tree_node<int>(14);
    another->set_left(new binary_tree_node<int>(5));
    another->set_right(new binary_tree_node<int>(6));
    //setting right subtree to right chiild of root node
    pointer->set_right(another);
    cout << "Before: " << endl;
    print(pointer, 3);
    preorder(pointer);
    cout << endl;
    cout << "After: " << endl;
    print(pointer, 3);
    return 0;
}
//traverses through the binary tree in preorder - root,left, right - and recursively calls heapify to continually go through the tree and swap the nodes depending on their value
void preorder(binary_tree_node<int>* root_ptr)
{
    if(root_ptr == NULL)
    {
        return;
    }
    else
    {
        heapify(root_ptr, NULL);
        preorder(root_ptr->left());
        preorder(root_ptr->right());
    }
}
//traverses through the tree in preorder and recursively calls swap function to actually swap the data values to form a max heap
void heapify(binary_tree_node<int>* root_ptr, binary_tree_node<int>* above_ptr)
{
    if(root_ptr == NULL)
    {
        return;
    }
    else
    {
        heapify(root_ptr->left(), root_ptr);
        heapify(root_ptr->right(), root_ptr);
        //if the data of the child is bigger, the parent and child value is swapped so that the bigger value is associated with the parent
        if((above_ptr != NULL) && (root_ptr->data() > above_ptr->data()))
        {
            //swaps the parent's and child's data values
            int temp = root_ptr->data();
            root_ptr->data() = above_ptr->data();
            above_ptr->data() = temp;
        }
    }
}
