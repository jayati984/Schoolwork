#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
class DynamicStringArray
{
    public:
        DynamicStringArray();
        DynamicStringArray(const DynamicStringArray& obj);
        ~DynamicStringArray();
        DynamicStringArray& operator =(const DynamicStringArray& rtSide);
        void addEntry(T str);
        bool deleteEntry(T str2);
        T getEntry(int index);
        int getSize();
    private:
        T *dynamicArray;
        int size;
};
template <class T>
DynamicStringArray<T>::DynamicStringArray()
{
    dynamicArray = NULL;
    size = 0;
}
template <class T>
DynamicStringArray<T>::DynamicStringArray(const DynamicStringArray<T>& obj)
{
    dynamicArray = new T[size];
    for(int i = 0; i < size; i++)
    {
        dynamicArray[i] = obj.dynamicArray[i];
    }
}
template <class T>
DynamicStringArray<T>::~DynamicStringArray()
{
    delete[] dynamicArray;
}
template <class T>
DynamicStringArray<T>& DynamicStringArray<T>::operator =(const DynamicStringArray<T>& rtSide)
{
    if(this==&rtSide)
    {
        return *this;
    }
    else
    {
        size = rtSide.size;
        delete[] dynamicArray;
        dynamicArray = new T[size];
        for(int i = 0; i < size; i++)
        {
            dynamicArray[i] = rtSide.dynamicArray[i];
        }
        return *this;
    }
}
template <class T>
void DynamicStringArray<T>::addEntry(T str)
{
    T *newDynamicArray;
    newDynamicArray = new T[size + 1];
    for(int i = 0; i < size; i++)
    {
        newDynamicArray[i] = dynamicArray[i];
    }
    newDynamicArray[size] = str;
    size++;
    delete[] dynamicArray;
    dynamicArray = newDynamicArray;
}
template <class T>
bool DynamicStringArray<T>::deleteEntry(T str2)
{
    bool found = false;
    int i;
    int x;
    for(i = 0; i < size; i++)
    {
        if(str2 == dynamicArray[i])
        {
            found = true;
            x = i;
            break;
        }
    }
    if(found == true)
    {
        T* anotherDynamicArray;
        anotherDynamicArray = new T[size - 1];
        for(int x = 0; x < i; x++)
        {
            anotherDynamicArray[x] = dynamicArray[x];
        }
        for(int x = i + 1; x < size; x++)
        {
            anotherDynamicArray[x-1] = dynamicArray[x];
        }
        delete[] dynamicArray;
        dynamicArray = anotherDynamicArray;
        size--;
    }
    return found;
}
template <class T>
T DynamicStringArray<T>::getEntry(int index)
{
    if(index >= size)
    {
        return NULL;
    }
    else
    {
        return (dynamicArray[index]);
    }
}
template <class T>
int DynamicStringArray<T>::getSize()
{
    return size;
}

int main()
{
    DynamicStringArray<string> d1;
    DynamicStringArray<int> d2;
    DynamicStringArray<char> d3;
    string str1, str2, str3, str4, str5;
    int int1, int2, int3, int4;
    char char1, char2, char3, char4, char5;
    bool answer, answer2;
    cout << "TESTING USING STRINGS" << endl;
    d1.addEntry("Home");
    d1.addEntry("heart");
    d1.addEntry("Zimbabwe");
    cout << "The size is:" << d1.getSize() << endl;
    cout << "The items are:" << endl;
    str1 = d1.getEntry(0);
    str2 = d1.getEntry(1);
    str3 = d1.getEntry(2);
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    answer = d1.deleteEntry("Jayati");
    str4 = d1.getEntry(0);
    str5 = d1.getEntry(1);
    cout << "After deletion the size is:" << d1.getSize() << endl;
    cout << "After deletion the items are:" << endl;
    cout << str4 << endl;
    cout << str5 << endl;
    cout << endl;
    cout << "TESTING USING INTEGERS" << endl;
    d2.addEntry(10);
    d2.addEntry(20);
    d2.addEntry(30);
    cout << "The size is:" << d2.getSize() << endl;
    cout << "The items are:" << endl;
    int1 = d2.getEntry(0);
    int2 = d2.getEntry(1);
    int3 = d2.getEntry(2);
    cout << int1 << endl;
    cout << int2 << endl;
    cout << int3 << endl;
    answer = d2.deleteEntry(10);
    answer2 = d2.deleteEntry(20);
    int4 = d2.getEntry(0);
    cout << "After deletion the size is:" << d2.getSize() << endl;
    cout << "After deletion the items are:" << endl;
    cout << int4 << endl;
    cout << "TESTING USING CHARACTERS" << endl;
    d3.addEntry('C');
    d3.addEntry('v');
    d3.addEntry('X');
    cout << "The size is:" << d3.getSize() << endl;
    cout << "The items are:" << endl;
    char1 = d3.getEntry(0);
    char2 = d3.getEntry(1);
    char3 = d3.getEntry(2);
    cout << char1 << endl;
    cout << char2 << endl;
    cout << char3 << endl;
    answer = d3.deleteEntry('V');
    char4 = d3.getEntry(0);
    char5 = d3.getEntry(1);
    cout << "After deletion the size is:" << d3.getSize() << endl;
    cout << "After deletion the items are:" << endl;
    cout << char4 << endl;
    cout << char5 << endl;
}