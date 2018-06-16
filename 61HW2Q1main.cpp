#include <iostream>
#include <cstdlib>
#include <queue>
#include "61HW2Q1.h"
using namespace std;

void officeHours_simulate(unsigned int timePerStudent, double arrival_prob, unsigned int total_time);

int main()
{
    officeHours_simulate(rand() % 9 + 1, 0.5, 60);
    return 0;
}

void officeHours_simulate(unsigned int timePerStudent, double arrival_prob, unsingned int total_time)
{
    queue<unsigned int> arrival_times; //timeStamps for students coming in
    unsigned int next; //value from queue
    bool_source arrival(arrival_prob);
    officeHours officeHour(timePerStudent);
    averager wait_times;
    unsigned int current_second;
    
    cout << "Minutes it takes for one student to complete office hours: " << timePerStudent << endl;
    cout << "Probability of student arrival during one minute: " << arrival_prob << endl;
    cout << "Total simulation minutes: " << total_time << endl;
    
    for(current_second = 1; current_second <= total_time; ++current_second) //actually minutes
    {
        //Simulate the passage of second(minute) of time
        //Check to see if new student had arrived
        if(arrival.query())
        {
            arrival_times.push(current_second);
        }
        //Check to see if professor can attend the next student
        if((!officeHour.is_busy()) && (!arrival_times.empty()))
        {
            next = arrival_times.front();
            arrival_times.pop();
            wait_times.next_number(current_second - next);
            officeHour.startOfficeHours();
        }
        //Simulate the passage of one second(minute)
        officeHour.one_timeStep();
    }
    
    //when there are still student remaining after an hour
    while(!arrival_times.empty())
    {
        next = arrival_times.front(); 
        arrival_times.pop();
        wait_times.next_number(current_second - next);
        officeHour.startOfficeHours();
    }
    
    cout << "Number of students who attended: " << wait_times.how_many_numbers() << endl;
    if(wait_times.how_many_numbers() > 0)
    {
        cout << "Average student spends waiting: " << wait_times.average() << " minutes " << endl;
    }
    //cout << "Average time student spends with professor: " << << endl;
    //cout << "Average time professor spends in office hour passed the hour mark: " << << endl;
}