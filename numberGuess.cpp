#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int num;
    int guess;
    int tries=0;

    srand(time(0));
    num = rand() % 100 + 1; // Random number between 1 and 100

    cout << "********* Number Guessing Game *********\n";
    do
    {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        tries++;
        if (guess < num)
        {
            cout << "Too low! Try again.\n";
        }
        else if (guess > num)
        {
            cout << "Too high! Try again.\n";
        }
        else
        {
            cout << "Congratulations! You've guessed the number " << num << " in " << tries << " tries.\n";
        }
    } while (guess != num);
    cout<< "*************** Game Over ***************\n";
    return 0;
    
    

}