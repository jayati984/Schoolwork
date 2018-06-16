#include "61HW2Q1.h"
#include <cassert>
#include <cstdlib>
using namespace std;

bool_source::bool_source(double p)
{
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}
bool bool_source::query() const
{
    return (rand() < probability * RAND_MAX);
}
averager::averager()
{
    count = 0;
    sum = 0;
}
void averager::next_number(double value)
{
    ++count;
    sum += value;
}
std::size_t averager::how_many_numbers() const
{
    return count;
}
double averager::average() const
{
     assert(how_many_numbers() > 0); 
     return (sum/count);
}
officeHours::officeHours(unisgned int t)
{
    time_per_person = t;
    officeHours_time_left = 0;
}
void officeHours::one_timeStep()
{
    if(is_busy())
    {
        --officeHours_time_left;
    }
}
void officeHours::startOfficeHours()
{
    assert(!is_busy());
    officeHours_time_left = one_timeStep;
}
bool officeHours::is_busy() const
{
    return(officeHours_time_left > 0);
}