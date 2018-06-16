#include <iostream>
using namespace std;

void disks(int n, char Start, char End, char Spare);

int main()
{
    int answer;
    cout << "Enter the number of disks to be moved: " << endl;
    cin >> answer;
    disks(answer, 'A', 'B', 'C');
    return 0;
}

void disks(int n, char Start, char End, char Spare)
{
    if(n == 1)
    {
        cout << "You can move disk " << n << " from post " << Start << " to post " << End << endl;
    }
    else
    {
        disks(n - 1, Start, Spare, End);
        cout << "You can move disk " << n << " from post " << Start << " to post " << End << endl;
        disks(n - 1, Spare, End, Start);
        //cout << "You can move disk " << n << " from post " << Start << " to post " << End << endl; 
    }
}
