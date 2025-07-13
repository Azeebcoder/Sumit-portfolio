#include <iostream>
#include <cstdlib>  // For system, rand
#include <ctime>    // For time
#include <string>

using namespace std;

// Global variables
int you_win = 0;
int computer_win = 0;
int game_played = 0;
int total_games = 0;
int games_left = 0;
bool cheating_mod = false;

// Function to clear the screen
void clear_screen() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// Function to convert user choice to game value
int change_val(char your_choice) {
    switch (your_choice) {
        case 'R': case 'r': return -1; // Rock
        case 'P': case 'p': return 0;  // Paper
        case 'S': case 's': return 1;  // Scissors
        default: return -2; // Invalid choice
    }
}

// Function to convert user choice to computer choice for cheating mode
int change_val_cheat(char your_choice) {
    switch (your_choice) {
        case 'R': case 'r': return 1;  // Rock
        case 'P': case 'p': return -1; // Paper
        case 'S': case 's': return 0;  // Scissors
        default: return -2; // Invalid choice
    }
}

// Function to decide the winner based on choices
void decide_winner(int computer_choice, int your_choice) {
    if (computer_choice == your_choice) {
        cout << "It's a Tie!" << endl;
    } else if ((computer_choice - your_choice == -1) || (computer_choice - your_choice == 2)) {
        cout << "You Win!" << endl;
        you_win++;
    } else {
        cout << "You Lose!" << endl;
        computer_win++;
    }
    game_played++;
    games_left--;
}

// Function to display choices and results
void display_results(int computer_choice, int your_choice) {
    static const string values[] = {"Rock", "Paper", "Scissors"};
    
    cout << "\n\n";
    cout << "Computer chose: " << values[computer_choice + 1] << endl;
    cout << "You chose: " << values[your_choice + 1] << endl;
    decide_winner(computer_choice, your_choice);
    cout << "\n";
    cout << "You have won " << you_win << " times." << endl;
    cout << "Computer has won " << computer_win << " times." << endl;
    cout << "Games left: " << games_left << endl;
    cout << "Games played: " << game_played << "\n\n";
}

// Function to get a valid user choice
char get_user_choice() {
    char choice;
    while (true) {
        cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
        cin >> choice;
        if (change_val(choice) != -2) break;
        cout << "Invalid choice. Please try again." << endl;
    }
    return choice;
}

// Main function
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    cout << "Welcome to Rock-Paper-Scissors Game!" << endl;
    cout << "Press \nR for Rock\nP for Paper\nS for Scissors\n\n";
    
    cout << "How many games do you want to play? ";
    cin >> total_games;
    games_left = total_games;

    int cheat_input;
    cout << "Press \n1 for Cheating Mode\n0 for Fair Game\n";
    cin >> cheat_input;
    cheating_mod = cheat_input == 1;

    while (games_left > 0) {
        int computer_choice = rand() % 3 - 1; // Random number between -1 and 1
        char your_choice = get_user_choice();

        if (cheating_mod) {
            computer_choice = change_val_cheat(your_choice);
        }

        clear_screen(); // Clear screen
        int your_choice_val = change_val(your_choice);
        display_results(computer_choice, your_choice_val);
    }

    if (computer_win > you_win) {
        cout << "\n\nYOU LOSE! BY " << computer_win - you_win << " POINTS" << endl;
    } else if (computer_win < you_win) {
        cout << "\n\nYOU WIN! BY " << you_win - computer_win << " POINTS" << endl;
    } else {
        cout << "TIE" << endl;
    }

    return 0;
}
