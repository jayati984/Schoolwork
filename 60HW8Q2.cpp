#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class LinkedList
{
    public:
        LinkedList() {}
        LinkedList(int theData, node* theLink);
        node* mergeLists(node*& head1, node*& head2);
        void insert(node*& newNode, const int& aData);
        void display(node*& pointer);
    private:
        node* head;
};

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3;
    node *temp1, *temp2, *temp3;
    LinkedList n1;
    LinkedList n2;
    LinkedList n3;
    cout << "BEFORE:" << endl;
    cout << "List 1:" << endl;
    n1.insert(head1,11);
    n1.insert(head1,9);
    n1.insert(head1,7);
    n1.insert(head1,5);
    n1.insert(head1,3);
    n1.display(head1);
    cout << endl;
    cout << "List 2:" << endl;
    n2.insert(head2,10);
    n2.insert(head2,8);
    n2.insert(head2,6);
    n2.insert(head2,4);
    n2.insert(head2,2);
    n2.display(head2);
    cout << endl;
    cout << "AFTER:" << endl;
    head3 = n1.mergeLists(head1, head2);
    n1.display(head3);
    return 0;
}

LinkedList::LinkedList(int theData, node* theLink)
{
    head->data = theData;
    head->link = theLink;
}

void LinkedList::insert(node*& newNode, const int& aData)
{
    node *temp = new node;
    temp->data = aData;
    temp->link = newNode;
    newNode = temp;
}

node* LinkedList::mergeLists(node*& head1, node*& head2)
{
    node* temp;
    node* newList = NULL;
    if(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            temp = head1;
            head1 = temp->link;
        }
        else
        {
            temp = head2;
            head2 = temp->link;
        }
        newList = temp;
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            temp->link = head1;
            temp = head1;
            head1 = temp->link;
        }
        else
        {
            temp->link = head2;
            temp = head2;
            head2 = temp->link;
        }
    }
    if(head1 == NULL)
    {
        temp->link = head1;
    }
    if(head2 == NULL)
    {
        temp->link = head2;
    }
    return newList;
}

void LinkedList::display(node*& pointer)
{
    for(node *p = pointer; p != NULL; p = p->link)
    {
        cout << p->data << " ";
    }
    cout << endl;
}