#include <iostream>
using namespace std;

int main()
{
    double score = 0;
    int numberOfScores = 0;
    double sum = 0;
    double average = 0;
    
    cout << "Enter score (When done entering scores, enter -1): " << endl;
    cin >> score;
    
    while (score != -1)
    {
        cout << "Enter score (When done entering scores, enter -1): " << endl;
        cin >> score;
        sum = sum + score;
        numberOfScores = numberOfScores + 1;
    }
    
    average = (sum)/(numberOfScores);
    cout << "The average score of the quiz is: " << average << endl;
    
    return 0;
}


        