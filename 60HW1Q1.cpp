#include <iostream>
using namespace std;

class CounterType
{
    public:
        CounterType();
        CounterType(int newCount);
        void setCount(int newCount);//mutator
        int getCount();//accessor
        void increaseCount();
        void decreaseCount();
        void output();
        void current();
    private:
        int count;
};
CounterType::CounterType()
{
    count = 0;
}
CounterType::CounterType(int newCount)
{
    count = newCount;
}
void CounterType::setCount(int newCount)
{
    cout << "Enter an integer to be the starting number of the count:" << endl;
    cin >> newCount;
    count = newCount;
}
int CounterType::getCount()
{
    if (count >= 0)
    {
        return count;
    }
}
void CounterType::increaseCount()
{
    if(count >= 0)
    {
        count++;
    }
}
void CounterType::decreaseCount()
{
    if(count > 0)
    {
        count--;
    }
    else
    {
        count = 0;
    }
}
void CounterType::output()
{
    cout << "The final count is:" << count << endl;
}
void CounterType::current()
{
   cout << "The current count is:" << count << endl; 
}
int main()
{
    CounterType counter;
    int nCount;
    char answer, ans;
    counter.getCount();
    counter.setCount(nCount);
    do
    {
        cout << "Would you like to increase or decrease the count? Please enter i/d" << endl;
        cin >> answer;
        if(answer=='i')
        {
            counter.increaseCount();
        }
        if(answer=='d')
        {
            counter.decreaseCount();
        }
        counter.current();
        cout << "Would you like to continue counting? Please enter y/n" << endl;
        cin >> ans;
    }while(ans=='y');
    counter.output();
    
    return 0;
}