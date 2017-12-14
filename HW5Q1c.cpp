#include <iostream>
using namespace std;

int main()
{
    const int DECLARED_SIZE = 100;
    double score[DECLARED_SIZE];
    int numberOfScores = 0;
    int index = 0;
    double sum = 0;
    double average = 0;
    double min = 30;
    double max = 0;
    
    cout << "Enter score (When done entering scores, enter -1): " << endl;
    cin >> score[index];
    
    while (score[index] != -1)
    {
        while ((score[index]>30) || (score[index]<-1))
        {
            cout << "This score entered is not valid " << endl;
            cout << "Please enter the score: " << endl;
            cin >> score[index];
        }
        
        if (score[index]<=min)
        {
            min = score[index];
        }
        if (score[index]>=max)
        {
            max = score[index];
        }
        sum = sum + score[index];
        numberOfScores++;
        index++;
        cout << "Enter score (When done entering scores, enter -1): " << endl;
        cin >> score[index];
    }
    
    average = ((sum)/(numberOfScores));
    cout << "The average score of the quiz is: " << average << endl;
    cout << "The lowest score is: " << min << endl;
    cout << "The highest score is: " << max << endl;
    
    return 0;
}