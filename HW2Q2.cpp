//Question 2

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c; //the double here had an uppercase D instead of a lowercase d
    b=2; //b was assigned to 2 instead of 2 being assigned to b
    cout<<"Enter length of hypotenuse"<<endl;
    cin>>c; // there was a >> endl which should not have been there
    cout<<"Enter length of a side"<<endl; //the angle brackets are facing the wrong //way as cout is for output
    cin>>a;
    double intermediate = pow(c, 2)-pow(a, 2);
    b = sqrt(intermediate);
    cout<<"Length of other side is:" <<b<<endl; //there was no second pair of << before the b to output the length of the other side and the endline should be written as endl instead of endline
    return 0;
 }
