//Program that reads in the degree of difficulty for a dive and the scores
//from seven judges. It then prints out the overall score for the diver.
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void input(double scores[], double& degreeOfDifficulty, int arraySize, int& numbersUsed);
//Precondition: degreeOfDifficulty >= 1.2 && <= 3.8. arraySize >= 1.
//Postcondition: Fills in the array scores. The value of degreeOfDifficulty 
//has been set.

void computeOverallScore(double scores[], double degreeOfDifficulty, int& numberUsed,  double& overallScore);
//Precondition: Array scores has been filled. degreeOfDifficulty >= 1.2 && <= 3.8. arraySize >= 1.
//Postcondition: Computes the overall score of the diver.

void deleteHighestScore(double scores[], int& numberUsed);
//Precondition: Array scores has been filled. numberUsed >= 1.
//Postcondition: Deletes the highest score from the array scores.

void deleteLowestScore(double scores[], int& numberUsed);
//Precondition: Array scores has been filled. numberUsed >= 1.
//Postcondition: Deletes the lowest score from the array scores.

void pushElementsForward(double scores[], int& numberUsed, int startIndex);
//Precondition: Array scores has been filled. numberUsed >= 1. startIndex
//>= 0 && <= numberUsed.
//Postcondition: Shifts all values of the elements of array score to the next
//successive element.

void output(double scores[], double overallScore);
//Precondition: scores has been filled. arraySize >= 1. 
//overallScore >= 1.
//Postcondition: Outputs the divers overall score.

const int ARRAY_SIZE = 7;

int main()
{
    int used;
    double s[ARRAY_SIZE], diversScore, degreeOfDifficulty;

    input(s, degreeOfDifficulty, ARRAY_SIZE, used);
    computeOverallScore(s, degreeOfDifficulty, used, diversScore);
    output(s, diversScore);

    return 0;
}

void input(double scores[], double& degreeOfDifficulty, int arraySize, int& numberUsed)
{
    cout<<"Enter degree of difficulty: ";
    cin>>degreeOfDifficulty;

    cout<<"Enter in 7 scores: ";

    for (int i = 0; i < arraySize; i++)
        cin>>scores[i];

    numberUsed = arraySize;
}

void computeOverallScore(double scores[], double degreeOfDifficulty, int& numberUsed, double& overallScore)
{
    deleteHighestScore(scores, numberUsed);
    deleteLowestScore(scores, numberUsed);

    double total = 0;

    for (int i = 0; i < numberUsed; i++)
        total+=scores[i];

    overallScore = (total*degreeOfDifficulty)*0.6;
}

void deleteHighestScore(double scores[], int& numberUsed)
{
    double highestScore = scores[0];
    int indexOfHighestScore = 0;

    for (int i = 1; i < numberUsed; i++)
    {
        if(scores[i] > highestScore)
        {
            highestScore = scores[i];
            indexOfHighestScore = i;
        }
    }

    pushElementsForward(scores, numberUsed, indexOfHighestScore);
}


void deleteLowestScore(double scores[], int& numberUsed)
{
    double lowestScore = scores[0];
    int indexOfLowestScore = 0;

    for (int i = 1; i < numberUsed; i++)
    {
        if(scores[i] < lowestScore)
        {
            lowestScore = scores[i];
            indexOfLowestScore = i;
        }
    }

    pushElementsForward(scores, numberUsed, indexOfLowestScore);
}

void pushElementsForward(double scores[], int& numberUsed, int startIndex)
{
    for (int i = startIndex; i < numberUsed; i++)
        scores[i] = scores[i + 1];

    numberUsed--;
}

void output(double s[], double overallScore)
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(1);
    cout<<"The divers score is "<<overallScore<<"\n\n";
}
