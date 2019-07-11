#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int x1, x2;
int dieRoll();
int humanTurn(int);
int computerTurn(int);

int main()
{
    cout<<"what should value we use";
    cin >> x1;
    cout<<"Hold-at-N turn simulations";
    cin >> x2;

    int humanTotalScore = 0, computerTotalScore = 0;

    srand(time(NULL)); //set a different seed for rand() every time to get different game outputs

    //loop to keep playing until someone scores 100+
    do
    {
        humanTotalScore = humanTotalScore + humanTurn(humanTotalScore); //add the score from a new turn to the running total
        cout << "Your total score so far is " << humanTotalScore << "." << endl;
        if(humanTotalScore >= 100)
        {
            cout << "You win!";
            return 0;
        }
        computerTotalScore = computerTotalScore + computerTurn(computerTotalScore); //add the score from a new turn to the running total
        cout << "CPU total score so far is " << computerTotalScore << "." << endl;
        if(computerTotalScore >= 100)
        {
            cout << "Computer wins!";
            return 0;
        }
            }
            while(humanTotalScore < 100 && computerTotalScore < 100);
        }

        //simulate rolling of die
        int dieRoll()
        {
            return (rand() % 6) + 1; //call to rand() returns 0-5, + 1 to give range 1-6, best way to avoid impossible die roll of 0
        }

        int humanTurn(int humanTotalScore)
        {
            int thisTurnScore = 0, score = 0;
            char rollOrHold;

            //loop to keep going as long the player chooses Roll Again or a 1 is thrown
            do
            {
                score = dieRoll(); //roll the die

                if(score == 1)
                {
                    cout << "You rolled a 1.  End of turn." << endl;
                    return 0;
                }

                thisTurnScore = thisTurnScore + score; //running total for this turn only

                cout << "You rolled a " << score << ".  Score so far this turn is " << thisTurnScore << "." << endl;

                //loop to keep asking, if user inputs illegal character
                        do
                {
                    cout << "Roll again (r) or Hold (h)? ";
                    cin >> rollOrHold;
                }
                while(rollOrHold != 'r' && rollOrHold != 'R' && rollOrHold != 'h' && rollOrHold != 'H');
            }
            while(rollOrHold == 'r' || rollOrHold == 'R');

            if(rollOrHold == 'h' || rollOrHold == 'H') return thisTurnScore; //finsh turn and return total score if player chooses to Hold
        }

        int computerTurn(int computerTotalScore)
        {
            int thisTurnScore = 0, score = 0;

            //loop to keep going as long the CPU score for this turn is less than 20
            do
            {
                score = dieRoll(); //roll the dice

                if(score == 1)
                {
                            cout << "CPU rolled a 1.  End of turn." << endl;
                            return 0;
                        }

                        thisTurnScore = thisTurnScore + score; //running total for this turn only

                        cout << "CPU rolled a " << score << ".  Score so far this turn is " << thisTurnScore << "." << endl;
                    }
                    while(thisTurnScore < 20);

                    //finsh turn and return total score if the CPU scored 20+
                    if(thisTurnScore >= 20)
                    {
                        cout << "CPU holds." << endl;
                        return thisTurnScore;
                    }
                }
