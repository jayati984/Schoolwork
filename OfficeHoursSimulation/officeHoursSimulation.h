//Student class header file

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student 
{
public:
	Student(int x, int y, string n, string t) 
	{	
            question = x;
            priority = y;
            name = n;
            topic = t;
	}
	int getQuestion() const {return question;}
	void setQuestion(int q) {question = q;}
        int getPriority() const {return priority;}
        void setPriority(int y) {priority = y;}
        int getWaitTime() const {return waitTime;}
	void setWaitTime(int x) {waitTime = x;}
	string getName() {return name;}
	string getTopic() {return topic;}
    
	friend bool operator <(Student &lhs, Student  &rhs); //overloading < operating to compare priorities such that highest priority is served first
private:
	int question;
	int waitTime;
	int priority;
        string name;
        string topic;
};

bool operator < (Student lhs, Student rhs) //needed for priority queue to order the Students with strict weak ordering
{
	return (lhs.getPriority() > rhs.getPriority());
}