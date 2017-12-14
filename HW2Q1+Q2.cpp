//Question 1

//a. Why was the invention of the Jacquard loom relevant to the history of CS?
//It was relevant in that it developed a way to record, analyze and store data through the use of punch cards.

//b. Why do we say computers express everything in zeros and ones?
//This is because they use the binary number system as they understand everything as true (1) and false (0).


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
