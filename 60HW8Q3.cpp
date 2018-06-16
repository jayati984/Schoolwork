#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Polynomial
{
    private:
        struct Node
        {
            int coefficient;
            int power;
            Node* link;
        };
        Node* head;
    public:
       Polynomial() {}
       Polynomial(int constant);
       Polynomial(int theCoefficient, int thePower);
       Polynomial(const Polynomial& object);
       //~Polynomial();
       int evaluation(int value);
       void input();
       void output();
       const Polynomial operator + (const Polynomial& p2) const;
       const Polynomial operator - (const Polynomial& p2) const;
       const Polynomial operator * (const Polynomial& p2) const;
};

Polynomial::Polynomial(int constant)
{
    head = new Node;
    head->coefficient = constant;
    head->power = 0;
    head->link = NULL;
}
Polynomial::Polynomial(int theCoefficient, int thePower)
{
    head = new Node;
    head->coefficient = theCoefficient;
    head->power = thePower;
    head->link = NULL;
}
Polynomial::Polynomial(const Polynomial& object)
{
    Node* temp;
    while(head != NULL)
    {
        temp = head->link;
        delete head;
        head = temp;
    }
}
/*Polynomial::~Polynomial()
{
    Node* temp;
    Node* another = head;
    while(another != NULL)
    {
       temp = another;
       another = another->link;
       delete temp;
    }
}*/
int Polynomial::evaluation(int value)
{
    return(head->coefficient * pow(value, head->power));
}
void Polynomial::input()
{
    Node *temp;
    int size;
    int n = 1;
    cout << "How many terms are in the polynomial?" << endl;
    cin >> size;
    while(n <= size)
    {
        if(n==1)
        {
            head = new Node;
            head->link = NULL;
            cout << "Enter the coefficient of x: " << endl;
            cin >> head->coefficient;
            cout << "Enter the power of x: " << endl;
            cin >> head->power;
            temp = head;
        }
        else
        {
            temp = new Node;
            temp->link = head;
            cout << "Enter the coefficient of x: " << endl;
            cin >> temp->coefficient;
            cout << "Enter the power of x: " << endl;
            cin >> temp->power;
            head = temp;
        }
        n++;
    }
    cout << endl;
}
void Polynomial::output()
{
    for(Node* temp = head; temp != NULL; temp = temp->link)
    {
        if(temp->coefficient != 0)
        {
        if(temp->coefficient > 0)
        {
            cout << " + ";
        }
        if(temp->coefficient < 0)
        {
            cout << " - ";
            temp->coefficient = (-1 * temp->coefficient);
        }
        if(temp->power == 0)
        {
            cout << temp->coefficient;
        }
        else if(temp->power == 1)
        {
            cout << temp->coefficient << "x";
        }
        else
        {
            cout << temp->coefficient << "x^" << temp->power;
        }
        }
    }
}
const Polynomial Polynomial::operator + (const Polynomial& p2) const
{
    Node *temp1, *temp2;
    temp1 = head;
    temp2 = p2.head;
    int c, p;
    while (temp1 != NULL && temp2 != NULL)
    {
    if(temp1->power > temp2->power)
    {
        c = temp1->coefficient;
        p = temp1->power;
        temp1 = temp1->link;
    }
    if(temp2->power > temp1->power)
    {
        c = temp2->coefficient;
        p = temp2->power;
        temp2 = temp2->link;
    }
    if(temp1->power == temp2->power)
    {
        c = temp1->coefficient + temp2->coefficient;
        p = temp1->power;
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    return Polynomial(c,p);
    }
}
const Polynomial Polynomial::operator - (const Polynomial& p2) const
{
    Node *temp1, *temp2;
    temp1 = head;
    temp2 = p2.head;
    int c, p;
    while (temp1 != NULL && temp2 != NULL)
    {
    if(temp1->power > temp2->power)
    {
        c = temp1->coefficient;
        p = temp1->power;
        temp1 = temp1->link;
    }
    else if(temp2->power > temp1->power)
    {
        c = temp2->coefficient;
        p = temp2->power;
        temp2 = temp2->link;
    }
    else //when the powers are equal
    {
        c = temp1->coefficient - temp2->coefficient;
        p = temp1->power;
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    return Polynomial(c,p);
    }
}
const Polynomial Polynomial::operator * (const Polynomial& p2) const
{
    Node *temp1, *temp2;
    temp1 = head;
    temp2 = p2.head;
    int c, p;
    while (temp1 != NULL && temp2 != NULL)
    {
    if(temp1->power > temp2->power)
    {
        c = temp1->coefficient;
        p = temp1->power;
        temp1 = temp1->link;
    }
    else if(temp2->power > temp1->power)
    {
        c = temp2->coefficient;
        p = temp2->power;
        temp2 = temp2->link;
    }
    else //when the powers are equal
    {
        c = temp1->coefficient * temp2->coefficient;
        p = temp1->power + temp2->power;
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    return Polynomial(c,p);
    }
}

int main()
{
    Polynomial p1;
    Polynomial p2;
    Polynomial p3;
    p1.input();
    p2.input();
    cout << "The polynomials are:" << endl;
    p1.output();
    p2.output();
    cout << endl;
    cout << "Addition" << endl;
    p3 = p1 + p2;
    cout << p3.evaluation(2) << endl;
    //p3.output();
    cout << endl;
    cout << "Subtraction" << endl;
    p3 = p2 - p1;
    cout << p3.evaluation(2) << endl;
    //p3.output();
    cout << endl;
    cout << "Multiplication" << endl;
    p3 = p2 * p1;
    cout << p3.evaluation(2) << endl;
    //p3.output();
    cout << endl;
    return 0;
}