#include <iostream>
using namespace std;

class node
{
    public:
    node() {}
    node(int theData, node* theLink) : data(theData), link(theLink) {}
    void reverse(node*& head);
    void insert(node*& head, int theData); 
    void display(node*& head);
    private:
    int data;
    node *link;
};

int main()
{
    node* head;
    node n;
    n.insert(head,3);
    n.insert(head,5);
    n.insert(head,7);
    n.insert(head,9);
    n.insert(head,11);
    cout << "BEFORE:" << endl;
    n.display(head);
    n.reverse(head);
    cout << "AFTER:" << endl;
    n.display(head);
    return 0;
}

void node::reverse(node*& head)
{
    node* previous = NULL;
    node* current = head;
    node* next;
    while(current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void node::insert(node*& head, int theData)
{
    head = new node(theData, head);
}

void node::display(node*& head)
{
    for(node *p = head; p != NULL; p = p->link)
    {
        cout << p->data << " ";
    }
    cout << endl;
}