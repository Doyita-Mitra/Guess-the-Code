#include <iostream>
#include <ctime>

using namespace std;

void PrintIntro(int Difficulty) 
{
    
    //Print welcome messages to the terminal
    cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room." << endl;
    cout << "You need to enter the correct codes to continue..." << endl;
}

bool RandCode(int Difficulty) 
{
    PrintIntro(Difficulty);

    //Declare 3 number codes
    const int CodeA = rand() % Difficulty + Difficulty; 
    const int CodeB = rand() % Difficulty + Difficulty; 
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum to the screen
    cout << "\nThere are 3 number codes" << endl;
    cout << "The codes sum upto: "<< CodeSum << endl;
    cout << "The codes multipliy to give: " << CodeProduct << endl;

    //Enter player guesses
    int GuessA {}; int GuessB {}; int GuessC {};
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = (GuessA + GuessB + GuessC);
    int GuessProduct = GuessA * GuessB * GuessC;
    cout << "Code entered: " << GuessSum << endl;

    //Check if the code matches 
    if (CodeSum == GuessSum && CodeProduct == GuessProduct) 
    {
        cout << "\nCongrats! You won this level!\n";
        return true;

    } else 
    {
        cout << "You guess is wrong! Try again!\n";
        return false;
    }
}

int main() 
{
    srand(time(NULL));   //create new random sequence based on the time of day
    int LevelDifficulty {1};
    const int MaxDifficulty {5}; //till difficulty level 5

    while (LevelDifficulty <= MaxDifficulty) //loop game until all levels are completed
    {

        bool bLevelComplete = RandCode(LevelDifficulty);
        cin.clear();   //clear any errors
        cin.ignore();  //discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            cout << endl;
        }
    
    }
    cout << "****Congrats!! You completed the Game!****\n";
    return 0;
}