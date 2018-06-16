#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
class Set
{
    public:
        Set();
        Set(int aCapacity);
        void addItem(T item);
        ~Set();
        int getNumber() const {return number;}
        void output();
    private:
        int number;
        int capacity;
        T *a;
};

template <class T>
Set<T>::Set()
{
    capacity = 50;
    number = 0;
    a = new T[capacity];
}

template <class T>
Set<T>::Set(int aCapacity)
{
    capacity = aCapacity;
    number = 0;
    a = new T[capacity];
}

template <class T>
Set<T>::~Set()
{
    delete[] a;
}

template <class T>
void Set<T>::addItem(T item)
{
    if(number >= capacity)
    {
        cout << "Exceeding capacity!" << endl;
        exit(1);
    }
    else
    {
        a[number] = item;
        number++;
    }
}

template <class T>
void Set<T>::output()
{
    cout << "The items are:" << endl;
    for(int i = 0; i < number; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "A SET OF INTEGERS:" << endl;
    Set<int> s1(10);
    s1.addItem(1);
    s1.addItem(1);
    s1.addItem(10);
    cout << "The number of items in the set is: "  << s1.getNumber() << endl;
    s1.output();
    cout << endl;
    cout << "A SET OF DOUBLES:" << endl;
    Set<double> s2(20);
    s2.addItem(9.9);
    s2.addItem(1.1);
    s2.addItem(1.2);
    s2.addItem(3.1);
    s2.addItem(8.6);
    cout << "The number of items in the set is: " << s2.getNumber() << endl;
    s2.output();
    cout << endl;
    cout << "A SET OF CHARACTERS:" << endl;
    Set<char> s3(30);
    s3.addItem('a');
    s3.addItem('b');
    s3.addItem('x');
    s3.addItem('z');
    cout << "The number of items in the set is: " << s3.getNumber() << endl;
    s3.output();
    cout << endl;
    cout << "A SET OF STRINGS:" << endl; 
    Set<string> s4(100);
    s4.addItem("Jinal");
    s4.addItem("twin");
    s4.addItem("home");
    s4.addItem("family");
    s4.addItem("school");
    s4.addItem("sister");
    cout << "The number of items in the set is: " << s4.getNumber() << endl;
    s4.output();
    return 0;
}