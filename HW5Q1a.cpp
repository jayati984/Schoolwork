#include <iostream>
using namespace std;

int main()
{
    const int DECLARED_SIZE = 100;
    double score[DECLARED_SIZE];
    int numberOfScores = 0;
    double sum = 0;
    double average = 0;
    int index = 0;
    
    cout << "Enter score (When done entering scores, enter -1): " << endl;
    cin >> score[index];
    
    while (score[index] != -1)
    {
        sum = sum + score[index];
        numberOfScores++;
        index++;
        cout << "Enter score (When done entering scores, enter -1): " << endl;
        cin >> score[index];
    }
    
    average = ((sum)/(numberOfScores));
    cout << "The average score of the quiz is: " << average << endl;
    
    return 0;
}


        