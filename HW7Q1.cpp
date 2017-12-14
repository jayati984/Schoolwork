#include <iostream>
using namespace std;

struct studentRecord
{
    double quiz1;
    double quiz2;
    double midterm;
    double finalExam;
    double average_score;
};
int main()
{
    studentRecord grade;
    grade.average_score = 0;
    cout << "Enter the score of quiz 1 out of 10: " << endl;
    cin >> grade.quiz1;
    cout << "Enter the score of quiz 2 out of 10: " << endl;
    cin >> grade.quiz2;
    cout << "Enter the score of the midterm out of 100: " << endl;
    cin >> grade.midterm;
    cout << "Enter the score of the final out of 100: " << endl;
    cin >> grade.finalExam;
    grade.quiz1 = grade.quiz1/10 * 100;
    cout << "The quiz 1 grade is: " << grade.quiz1 << endl;
    grade.quiz2 = grade.quiz2/10 * 100;
    cout << "The quiz 2 grade is: " << grade.quiz2 << endl;
    grade.midterm = grade.midterm;
    cout << "The midterm grade is: " << grade.midterm << endl;
    grade.finalExam = grade.finalExam;
    cout << "The final exam grade is: " << grade.finalExam << endl;
    grade.quiz1 = grade.quiz1 * 0.125;
    grade.quiz2 = grade.quiz2 * 0.125;
    grade.midterm = grade.midterm * 0.25;
    grade.finalExam = grade.finalExam * 0.5;
    grade.average_score = grade.quiz1 + grade.quiz2 + grade.midterm + grade.finalExam;
    cout << "The average is: " << grade.average_score << endl;
    if (grade.average_score >= 90)
    {
        cout << "The grade is: A" << endl;
    }
    if ((grade.average_score >= 80) && (grade.average_score < 90))
    {
        cout << "The grade is: B" << endl;
    }
    if ((grade.average_score >= 70) && (grade.average_score < 80))
    {
        cout << "The grade is: C" << endl;
    }
    if ((grade.average_score >= 60) && (grade.average_score < 70))
    {
        cout << "The grade is: D" << endl;
    }
    else
    {
        cout << "The grade is: F" << endl;
    }
    return 0;
}