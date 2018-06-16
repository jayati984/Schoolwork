#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include "bintree.h"
using namespace std;
using namespace main_savitch_10;

void prefix(binary_tree_node<char> *root_ptr, string str);

int main()
{
    binary_tree_node<char> *root_ptr = NULL;
    string expression;
    cout << "Please enter a prefix expression:" << endl;
    getline(cin, expression);
    //the root node of the binary tree
    if((expression[0] == '*') || (expression[0] == '/') || (expression[0] == '+') || (expression[0] == '-'))
    {
        root_ptr = new binary_tree_node<char> (expression[0]);
    }
    prefix(root_ptr, expression);
    //print function until depth 3
    print(root_ptr, 3);
    
    return 0;
}

void prefix(binary_tree_node<char> *root_ptr, string str)
{
    //pointers in the binary tree
    binary_tree_node<char> *child_ptr = NULL;
    binary_tree_node<char> *another_ptr = NULL;
    binary_tree_node<char> *current_ptr = NULL;
    int i = 1;
    char next = str[i];
    //when the expression is simple such as +23
    if(str.length() <= 3)
    {
        //when there is a character, a new node is created and set to the left hand child, until the numbers seen which are set as children of the last operator seen
    if((next != '*') || (next != '/') || (next != '+') || (next != '-'))
    {
        root_ptr->set_left(new binary_tree_node<char> (next, NULL, NULL));
        i++;
        next = str[i];
        //setting the left subtree as the left child of the root node
        root_ptr->set_right(new binary_tree_node<char> (next, NULL, NULL));
    } 
    }
    //when the expression is more complex such as +-23/42
    else
    { //when there is a character, a new node is created and set to the left hand child, until the numbers seen which are set as children of the last operator seen
        while(((next == '*') || (next == '/') || (next == '+') || (next == '-')) && (next != '\n'))
        {
            child_ptr = new binary_tree_node<char> (next);
            another_ptr = child_ptr;
            i++;
            next = str[i];
        }
        
        another_ptr->set_left(new binary_tree_node<char> (next, NULL, NULL));
        i++;
        next = str[i];
        another_ptr->set_right(new binary_tree_node<char> (next, NULL, NULL));
        i++;
        next = str[i];
        root_ptr->set_left(child_ptr);
        
        //for the right subtree as the right child of the root node = right and left subtree will be combined with the root node operator 
            if((next == '*') || (next == '/') || (next == '+') || (next == '-'))
            {
                child_ptr = new binary_tree_node<char> (next);
                another_ptr = child_ptr;
                i++;
                next = str[i];
                
                another_ptr->set_left(new binary_tree_node<char> (next, NULL, NULL));
                i++;
                next = str[i];
                another_ptr->set_right(new binary_tree_node<char> (next, NULL, NULL));
                i++;
                next = str[i];
            }
            root_ptr->set_right(child_ptr);
    }
}