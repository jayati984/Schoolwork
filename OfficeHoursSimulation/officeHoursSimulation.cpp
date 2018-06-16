//main function file
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <queue>
#include <map>
#include <string>
#include "officeHoursSimulation.h"

string Name();
string Topic();
void simulate(unsigned int& overtime, unsigned int& averageWaitTime, unsigned int& averageQuestionTime, multimap<string, string>& record);
void sort(ifstream& inStream, string column, string direction, multimap<string, string>& record);
void searchByName(ifstream& inStream, multimap<string, string>& record);
void searchByTopic(ifstream& inStream, multimap<string, string>& record);

int main()
{
        //output file
        ofstream output;
        output.open("report.txt");
        ifstream in;
        in.open("report.txt");
        //checking if opening is success
        if(output.fail())
        {
            cout << "Error, file opening failed!" << endl;
            exit(1);
        }
        
        //totals
        unsigned int averageOvertime = 0;
        unsigned int averageWaitTime = 0;
        unsigned int averageQuestionTime = 0;
        
        //declaring multimap
        multimap<string, string> record;
        
        //seed rand()
        srand((unsigned)time(NULL));
        
        //calling simulate function 100 times
        for(unsigned int i = 0; i < 100; i++)
        {
            simulate(averageOvertime, averageWaitTime, averageQuestionTime, record);
        }
        
        //output
	cout << "Average time professor spends in office hours after hour mark: " << averageOvertime / 100 << " minutes" << endl; //time / 100
	cout << "Average time spent with professor per student: " << averageQuestionTime / 100 << " minutes" << endl; //time / number of students
	cout << "Average wait time per student: " << averageWaitTime / 100 << " minutes" << endl; //time / number of students
	
	//traversing through multimap and generating report
	multimap<string, string>::iterator iter;
        int count = 1;
        string studentName;
        for(iter = record.begin(); iter != record.end(); ++iter)
        {
            if(iter == record.begin())
            {
               studentName = iter->first;
               output << studentName << endl;
               output << "Topics: " << endl;
               output << iter->second << endl;
            }
            else
            {
                //checking to see if student has been to office hours before and if so output their topic and increase the number of times they have been to office hours
                if(iter->first == studentName)
                {
                    output << iter->second << endl;
                    count++;
                }
                else // new student
                {
                    output << "Number of times attended Office Hours: " << count << endl;
                    output << endl;
                    count = 1;
                    studentName = iter->first;
                    output << studentName << endl;
                    output << "Topics: " << endl;
                    output << iter->second << endl;
                }
            }
        }
        string direction, column;
        cout << "Would you like to sort the topics in ascending order? (Please enter yes)" << endl;
        getline(cin, direction);
        if(direction == "yes")
        {
            sort(in, column, direction, record);
        }
        
        searchByName(in, record);
        searchByTopic(in, record);
        
        //closing output stream
        output.close();
        in.close();
        
        return 0;
}
        
        void simulate(unsigned int& averageOvertime, unsigned int& averageWaitTime, unsigned int& averageQuestionTime, multimap<string, string>& record)
        {
            //variables that will be incremented for each loop 
            unsigned int waitTime = 0; //time till next student is served
            unsigned int numberOfStudents = 0;
            unsigned int overtime = 0;
            unsigned int time = 0;
            unsigned int sumOfWaitTime = 0;
            unsigned int priority = 0;
            unsigned int totalQuestion = 0;
            
            //declaring priority queue
            priority_queue<Student> line; //line of students waiting for office hours (prioritized)
            
            //during office hour
            for(unsigned int j = 1; j <= 60; j++)// 1 hour simulation
            {
                //setting priority for each student randomly
                unsigned int prior = rand() % 5;
                //setting random probability 
                double probability = rand() % 100;
                while(probability/60 > 0.3 || probability/60 < 0.05)
                {
                    probability = rand() % 100;
                }
                double arrival = probability/60.0;
                if(rand() < arrival * RAND_MAX)
                {
                    string na = Name();
                    string to = Topic();
                    unsigned int qu = rand() % 15 + 1; // length of question asked and spent is always less than 20 minutes
                    Student person(totalQuestion, priority, na, to); //new student is created with a random service time, priority, name, and topic
                    person.setWaitTime(j); //current time is equal to wait time for that student
                    person.setPriority(prior);
                    priority = person.getPriority();
                    //inserting name and topic of question asked into multimap
                    record.insert(pair<string,string>(person.getName(), person.getTopic()));
                    person.setQuestion(qu);
                    totalQuestion += person.getQuestion(); //time spent with professor asking a question
                    line.push(person); //add the student to the back of the line
                    numberOfStudents++; //increment total number of students
                        
                }
                    if(waitTime > 0) //if professor is busy
                    {
                        waitTime--; //decrease wait time by one
                        if(waitTime == 0) //if the wait time is zero remove the front student from the line to be served
                        {
                            line.pop();
                        }
                    }
                    else if(waitTime == 0 && !line.empty()) //if the professor is not busy
                    {
                        waitTime = line.top().getQuestion(); //set wait time for next student in line (time for prevoius person with professor)
                        sumOfWaitTime += time - (line.top().getWaitTime()); //current student's wait time
                    }
			
                    //time incrementation
                    time++;
		}
		
		//check if there are still students in line waiting after one hour mark
		if(!line.empty())
		{
                    while(!line.empty()) //continue serving students until the line is empty (no new students can enter the line)
                    {
                        if(waitTime > 0) //if professor is busy
                        {
                            waitTime--;
                            if(waitTime == 0)
                            {
                                line.pop();
                            }
                        }
				
                        if(waitTime == 0) //if the professor is not busy
                        {
                            waitTime = line.top().getQuestion();
                            sumOfWaitTime += time - (line.top().getWaitTime());
                        }
				
                        //time incrementation after an hour
                        overtime++;
                        time++;
                    }
		}
		//totals and averages
		unsigned int avOvertime = overtime;
		unsigned int avWaitTime = sumOfWaitTime / numberOfStudents;
		unsigned int avQuestionTime = totalQuestion / numberOfStudents;
                //values that will be used to calculate average times after running 100 times
                averageOvertime += avOvertime;
                averageWaitTime += avWaitTime;
                averageQuestionTime += avQuestionTime;
	}
       
        //multimap functions
	//randomly getting student name
	string Name()
        {
            int number = rand() % 20 + 10;
            string student = "Student" + to_string(number);
            return student;
        }
        
        //randomly getting topic asked
        string Topic()
        {
            string arr[5] = {"Stacks", "Queues", "BinaryTrees", "B-Trees", "Heaps"};
            int a = rand() % 5;
            return arr[a];
        }
        
        void sort(ifstream& inStream, string column, string direction, multimap<string, string>& record)
        {
            string array[20];
            //reading in students from file
            while(inStream >> column)
            {
                //putting in students in array
                if(column == "Student1" || column == "Student2" || column == "Student3" || column == "Student4" || column == "Student5" || column == "Student6" || column == "Student7" || column == "Student8" || column == "Student9" || column == "Student10" || column == "Student11" || column == "Student12" || column == "Student13" || column == "Student14" || column == "Student15" || column == "Student16" || column == "Student17" || column == "Student18" || column == "Student19" || column == "Student20")
                {
                    for(int i = 0; i < 20; i++)
                    {
                        array[i] = column;
                    }
                }
            }
            //sorting students in ascending order using insertion sort
            int i, j, k ,l;
            
            for(i = 1; i < 20; ++i)
            {
                int index = i;
                for(j = index - 1; j >= 0; j--)
                {
                    string s1 = array[j];
                    string s2 = array[i];
                    //if string length is 8 or 9 depending on last 2 digits
                    if(s1.length() == 8)
                    {
                        s1 = s1.substr(7,1);
                        k = stoi(s1, nullptr, 10);
                    }
                    else
                    {
                        s1 = s1.substr(7,2);
                        k = stoi(s1, nullptr, 10);
                    }
                    
                    if(s2.length() == 8)
                    {
                        s2 = s2.substr(7,1);
                        l = stoi(s2, nullptr, 10);
                    }
                    else
                    {
                        s2 = s2.substr(7,2);
                        l = stoi(s2, nullptr, 10);
                    }
                    //comparing indexes
                    if(k < l)
                    {
                        index = j;
                    }
                }
                //creating temp string
                string temp = array[i];
                for(int x = i; x > index; x++)
                {
                    array[x] = array[x-1];
                }
                array[index] = temp;
            }
            
            ofstream out;
            out.open("finalreport.txt");
            
            multimap<string, string>::iterator iter;
            int count = 1;
            string studentName;
            for(iter = record.begin(); iter != record.end(); ++iter)
            {
                if(iter == record.begin())
                {
                    studentName = iter->first;
                    out << studentName << endl;
                    out << "Topics: " << endl;
                    out << iter->second << endl;
                }
                else
                {
                    //checking to see if student has been to office hours before and if so output their topic and increase the number of times they have been to office hours
                    if(iter->first == studentName)
                    {
                        out << iter->second << endl;
                        count++;
                    }
                    else // new student
                    {
                        out << "Number of times attended Office Hours: " << count << endl;
                        out << endl;
                        count = 1;
                        studentName = iter->first;
                        out << studentName << endl;
                        out << "Topics: " << endl;
                        out << iter->second << endl;
                    }
                }
            }
            out.close();
        }
        
void searchByName(ifstream& inStream, multimap<string, string>& record)
{
    string name;
    cout << "Please enter a student name to search (eg: Student10): " << endl;
    cin >> name;
    
    string s;
    string str = name;;
    multimap<string, string>::iterator iter;
    for(iter = record.begin(); iter != record.end();)
    {
        s = iter->first;
        inStream >> str;
        if(s == str)
        {
            cout << "Student Name: " << iter->first << endl;
            cout << "Topic: " << iter->second << endl;
            cout << name << " attended office hours number " << (rand() % 100) + 1 << endl;
            break;
        }
        else
        {
            if(iter == record.end())
            {
                cout << name << " did not attend office hours. " << endl;
                break;
            }
            iter++;
        }
    }
}
void searchByTopic(ifstream& inStream, multimap<string, string>& record)
{
    cout << endl;
    string topic;
    cout << "Please enter a subject to search: " << endl;
    cin >> topic;
    
    string s2;
    string str2 = topic;
    multimap<string, string>::iterator iter;
    for(iter = record.begin(); iter != record.end();)
    {
        s2 = iter->second;
        inStream >> str2;
        if(s2 == str2)
        {
            cout << "Topic: " << iter->second << endl;
            cout << "Student Name: " << iter->first << endl;
            cout << iter->first << " attended office hours number " << (rand() % 100) + 1 << endl;
            iter++;
        }
        else
        {
            if(iter == record.end())
            {
                cout << topic << " was not asked about in office hours." << endl;
                break;
            }
            iter++;
        }
    }
}