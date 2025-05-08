#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Class to handle Rock-Paper-Scissors game logic
class RockPaperScissors {
private:
    string playerName; // Variable to store player's name
    int rounds;        // Variable to store number of rounds

public:
    // Method to start the game
    void startGame() {
        int playerChoice, computerChoice;
        int currentRound = 1;
        char playAgain;

        // Accept the player's name
        cout << "Enter your name: ";
        getline(cin, playerName);

        // Accept number of rounds
        cout << "Enter number of rounds to play: ";
        cin >> rounds;

        // Seed random number generator
        srand(time(0));

        // Play the specified number of rounds
        while (currentRound <= rounds) {
            cout << "\n=== Round " << currentRound << " ===\n";

            // Display the menu
            displayMenu();

            // Accept player's choice
            cout << "Enter your choice (1- Rock, 2- Paper, 3- Scissors): ";
            cin >> playerChoice;

            // Validate player choice
            if (playerChoice < 1 || playerChoice > 3) {
                cout << "Invalid choice! Please enter a number between 1 and 3.\n";
                continue; // Restart this round
            }

            // Generate computer's choice
            computerChoice = (rand() % 3) + 1;

            // Display both choices
            cout << playerName << " chose: " << choiceToString(playerChoice) << endl;
            cout << "Computer chose: " << choiceToString(computerChoice) << endl;

            // Determine and display the result
            determineWinner(playerChoice, computerChoice);

            // Move to the next round
            currentRound++;
        }

        cout << "\n=== Game Over. Thanks for playing, " << playerName << "! ===\n";
    }

private:
    // Method to display the menu
    void displayMenu() {
        cout << "\nChoose:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
    }

    // Method to convert numeric choice to string
    string choiceToString(int choice) {
        if (choice == 1) return "Rock";
        else if (choice == 2) return "Paper";
        else return "Scissors";
    }

    // Method to determine the winner of a round
    void determineWinner(int player, int computer) {
        if (player == computer) {
            cout << "Result: It's a Tie!\n";
        }
        else if ((player == 1 && computer == 3) ||
                 (player == 2 && computer == 1) ||
                 (player == 3 && computer == 2)) {
            cout << "Result: " << playerName << " Wins!\n";
        }
        else {
            cout << "Result: Computer Wins!\n";
        }
    }
};

int main() {
    // Create object of the class
    RockPaperScissors game;

    // Invoke the method through object
    game.startGame();

    return 0;
}

