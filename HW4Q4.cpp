#include <iostream>
#include <string>
using namespace std;

void Length();
void inputLength(double& lengthFeet, double& lengthInches, double& lengthMeters, double& Centimeters, int& userInput);
void calculationFeetInches_MetersCentimeters(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput);
void calculationMetersCentimeters_FeetInches(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput);
void outputLength(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput);
void Weight();
void inputWeight(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput);
void calculationsPoundsOunces_KilogramsGrams(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput);
void calculationsKilogramsGrams_PoundsOunces(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput);
void outputWeight(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput);

int main()
{
    int userInput;
    char answer;
    do
    {
        cout << "If you would like to convert lengths enter 1, and if you would like to convert weights enter 2: " << endl;
        cin >> userInput;
        if (userInput == 1)
        {
            Length();
        }
        else
        {
            Weight();
        }
        cout << "Would you like to repeat this calculation? (y(yes)/n(no))" << endl;
        cin >> answer;
    }while ((answer == 'y') || (answer == 'Y'));
    return 0;
}

void Length()
{
    double feet, inches, meters, centimeters;
    int userInput;
    inputLength(feet, inches, meters, centimeters, userInput);
    if (userInput == 1)
    {
       calculationFeetInches_MetersCentimeters(feet, inches, meters, centimeters, userInput); 
    }
    else
    {
        calculationMetersCentimeters_FeetInches(feet, inches, meters, centimeters, userInput);
    }
    outputLength(feet, inches, meters, centimeters, userInput);
}

void inputLength(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput)
{
    cout << "If you would like to convert feet and inches to meters and centimeters enter 1 and if you would like to convert meters and centimeters to feet and inches " << "enter 2: " << endl;
    cin >> userInput;
    if (userInput == 1)
    {
        cout << "Enter a length in feet: " << endl;
        cin >> lengthFeet;
        cout << "Enter a length in inches: " << endl;
        cin >> lengthInches;
    }
    else
    {
        cout << "Enter a length in meters: " << endl;
        cin >> lengthMeters;
        cout << "Enter a length in centimeters: " << endl;
        cin >> lengthCentimeters;
    }
    
}
void calculationFeetInches_MetersCentimeters(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput)
{
    lengthMeters = (lengthFeet * 0.3048);
    lengthCentimeters = (lengthInches * (0.3048/12) * 100);
}
void calculationMetersCentimeters_FeetInches(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput)
{
    lengthFeet = (lengthMeters/0.3048);
    lengthInches = ((lengthCentimeters * 12)/(0.3048 * 100));
}

void outputLength(double& lengthFeet, double& lengthInches, double& lengthMeters, double& lengthCentimeters, int& userInput)
{
    if (userInput == 1)
    {
        cout << "The length in meters is: " << lengthMeters << endl;
        cout << "The length in centimeters is: " << lengthCentimeters << endl;
    }
    else
    {
        cout << "The length in feet is : " << lengthFeet << endl;
        cout << "The length in inches is: " << lengthInches << endl;
    }
}

void Weight()
{
    double pounds, ounces, kilograms, grams;
    int userInput;
    inputWeight(pounds, ounces, kilograms, grams, userInput);
    if (userInput == 1)
    {
        calculationsPoundsOunces_KilogramsGrams(pounds, ounces, kilograms, grams, userInput);
    }
    else
    {
        calculationsKilogramsGrams_PoundsOunces(pounds, ounces, kilograms, grams, userInput);
    }
    outputWeight(pounds, ounces, kilograms, grams, userInput);
}
void inputWeight(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput)
{
    cout << "If you would like to convert pounds and ounces to kilograms and grams enter 1 and if you would like to convert kilograms and grams to pounds and ounces "
    << "enter 2: " << endl;
    cin >> userInput;
    if (userInput == 1)
    {
        cout << "Enter a weight in pounds: " << endl;
        cin >> weightPounds;
        cout << "Enter a weight in ounces: " << endl;
        cin >> weightOunces;
    }
    else
    {
        cout << "Enter a weight in kilograms: " << endl;
        cin >> weightKilograms;
        cout << "Enter a weight in grams: " << endl;
        cin >> weightGrams;
    }
}
void calculationsPoundsOunces_KilogramsGrams(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput)
{
    weightKilograms = (weightPounds/2.2046);
    weightGrams = ((weightOunces * 1000)/(16 * 2.2046));
}
void calculationsKilogramsGrams_PoundsOunces(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput)
{
    weightPounds = (weightKilograms * 2.2046);
    weightOunces = ((weightGrams * 2.2046 * 16)/(1000));
}
void outputWeight(double& weightPounds, double& weightOunces, double& weightKilograms, double& weightGrams, int& userInput)
{
    if (userInput == 1)
    {
        cout << "The weight in kilograms is: " << weightKilograms << endl;
        cout << "The weight in grams is: " << weightGrams << endl;
    }
    else
    {
        cout << "The weight in pounds is: " << weightPounds << endl;
        cout << "The weight in ounces is: " << weightOunces << endl;
    }
}