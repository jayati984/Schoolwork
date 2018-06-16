#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
class Point
{
    public:
        static const T1 CAPACITY = 10;
        Point() {}
        Point(T1 dim);
        Point(T1 dim, T2 arr[]);
        T2 getItem(T1 index);
        T1 getSize();
        Point<T1,T2> operator =(const Point<T1, T2> rtSide);
    private:
        T2 a[CAPACITY];
        T1 dimension;
};
template<typename T1, typename T2>
Point<T1, T2>::Point(T1 dim)
{
    dimension = dim;
    for(T1 i = 0; i < dimension; i++)
    {
        a[i] = 0;
    }
}
template<typename T1, typename T2>
Point<T1, T2>::Point(T1 dim, T2 arr[])
{
    dimension = dim;
    for(T1 i = 0; i < dimension; i++)
    {
        a[i] = arr[i];
    }
}
template<typename T1, typename T2>
T2 Point<T1, T2>::getItem(T1 index)
{
    return a[index];
}
template<typename T1, typename T2>
T1 Point<T1, T2>::getSize()
{
    return dimension;
}
template<typename T1, typename T2>
Point<T1, T2> Point<T1, T2>::operator =(const Point<T1, T2> rtSide)
{
    dimension = rtSide.dimension;
    for(T1 i = 0; i < dimension; i++)
    {
        a[i] = rtSide.a[i];
    }
}

template<typename T1, typename T2>
Point<T1, T2> operator +(Point<T1, T2> p4, Point<T1, T2> p5)
{
    Point<T1, T2> p3(10);
    for(T1 i = 0; i < p3.getSize(); i++)
    {
        p3.a = p4.getItem(i) + p5.getItem(i);
    }
    return p3;
}

template<typename T1, typename T2>
bool operator ==(Point<T1, T2> p4, Point<T1, T2> p5)
{
    bool answer = true;
    for(T1 i = 0; i < 10; i++)
    {
        if(p4.getItem(i) != p5.getItem(i))
        {
            answer = false;
        }
    }
    return answer;
}

int main()
{
    int array[3] = {1, 2, 3};
    Point<int, int> p1(3);
    Point<int, int> p2(3, array);
    int result = p1.getItem(2);
    cout << "Result is:" << result << endl;
    int result2 = p2.getItem(2);
    cout << "Result is:" << result2 << endl;
    p1 = p2;
    int result3 = p1.getItem(2);
    cout << "Result is:" << result3 << endl;
    Point<int, int> p3(10);
    p3 = p1 + p2;
    
     
    return 0;
}