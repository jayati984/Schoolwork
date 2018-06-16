#ifndef 61HW2Q1_H
#define 61HW2Q1_H
#include <iostream>
#include <cstdlib>

class bool_source
{
    public:
        bool_source(double p = 0.5);
        bool query() const;
    private:
        double probability; //Probabilty of query returning true
};

class averager
{
    public:
        averager();
        void next_number(double value);
        std::size_t how_many_numbers() const;
        double average() const;
    private:
        std::size_t count; //Number of people given
        double sum; //Sum of all the numbers
};

class officeHours
{
    public:
        officeHours(unisgned int t = rand() % 9 + 1); //random number for the amount of time one student takes in office hours
        void one_timeStep();
        void startOfficeHours();
        bool is_busy() const;
    private:
        unsigned int time_per_person; //Seconds(minute) for one person to complete office officeHours
        unsigned int officeHours_time_left; //Seconds(minutes) until the professor is no longer busy = Service Rate
};
#endif