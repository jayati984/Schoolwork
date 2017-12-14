#include <iostream>
using namespace std;

int main()
{
    double score = 0;
    int numberOfScores = 0;
    double sum = 0;
    double average = 0;
    double min = 30;
    double max = 0;
    
    cout << "Enter score (When done entering scores, enter -1): " << endl;
    cin >> score;
    
    while (score != -1)
    {
        if ((score>30) || (score<-1))
        {
            cout << "This score entered is not valid " << endl;
            cout << "Please enter the score: " << endl;
            cin >> score;
        }
        sum = sum + score;
        numberOfScores++;
        
        if (score<=min)
        {
            min = score;
        }
        if (score>=max)
        {
            max = score;
        }
        
        cout << "Enter score (When done entering scores, enter -1): " << endl;
        cin >> score;
    }
    
    average = ((sum)/(numberOfScores));
    cout << "The average score of the quiz is: " << average << endl;
    cout << "The lowest score is: " << min << endl;
    cout << "The highest score is: " << max << endl;
    
    return 0;
}
