#include<iostream>
#include<ctime>
using namespace std;

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char userChoice, char computerChoice);

int main()
{
    srand(time(0)); // ✅ Seed random generator only once
    int n;
    do {
        cout << "\nEnter 1 to start the game or 0 to exit: ";
        cin >> n;
        if(n == 0){
            cout << "Thanks for playing! Goodbye 👋\n";
            break;
        }

        char player, computer;
        player = getUserChoice();
        cout << "You chose: ";
        showChoice(player);

        computer = getComputerChoice();
        cout << "Computer chose: ";
        showChoice(computer);

        chooseWinner(player, computer);

    } while(n != 0);

    return 0;
}

char getUserChoice(){
    cout <<"*********************************************************\n";
    cout<< "************** Rock, Paper, Scissors Game ***************\n";
    char player;
    do{
         cout <<"Choose one of the following:\n";
         cout<< "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
         cin >> player;
         player = toupper(player); // ✅ allow lowercase input too
    }while(player != 'R' && player != 'P' && player != 'S');

    return player;
}

char getComputerChoice(){
    int num = rand() % 3 + 1;
    switch(num)
    {
        case 1: return 'R';
        case 2: return 'P';
        case 3: return 'S';
    }
    return 0;
}

void showChoice(char choice){
    switch(choice)
    {
        case 'R': cout<< "Rock\n"; break;
        case 'S': cout<< "Scissors\n"; break;
        case 'P': cout<< "Paper\n"; break;
    }
}

void chooseWinner(char userChoice, char computerChoice){
    if(userChoice == computerChoice) {
        cout<< "It's a tie!\n";
    }
    else if((userChoice == 'R' && computerChoice == 'S') ||
            (userChoice == 'S' && computerChoice == 'P') ||
            (userChoice == 'P' && computerChoice == 'R')) {
        cout<< "You win!\n";
    }
    else {
        cout<< "Computer wins!\n";
    }
}
