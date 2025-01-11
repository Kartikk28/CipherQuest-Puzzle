#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Codebreaker: A simple number guessing game
// Written to practice basic concepts in C, such as loops, conditionals, and random numbers.

void playGame(int maxRange, int maxAttempts);

int main() {
    int difficulty;

    // Welcome the player to the game
    printf("Welcome to Codebreaker: A Number Guessing Game!\n");
    printf("Can you crack the secret code?\n\n");

    // Let the user pick a difficulty level
    printf("Select your difficulty:\n");
    printf("1. Easy (Numbers between 1 and 50)\n");
    printf("2. Medium (Numbers between 1 and 100)\n");
    printf("3. Hard (Numbers between 1 and 200)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &difficulty);

    // Determine the range of numbers based on difficulty
    int maxRange;
    switch (difficulty) {
        case 1:
            maxRange = 50;
            break;
        case 2:
            maxRange = 100;
            break;
        case 3:
            maxRange = 200;
            break;
        default:
            printf("Oops, that’s not a valid choice! I’ll set it to Medium for you.\n");
            maxRange = 100;
    }

    // Start the game
    playGame(maxRange, 10); // Player gets 10 attempts
    return 0;
}

void playGame(int maxRange, int maxAttempts) {
    // Initialize the random number generator
    srand(time(NULL));
    int secretNumber = rand() % maxRange + 1;

    // Give the player some instructions
    printf("\nThe secret number is hidden somewhere between 1 and %d.\n", maxRange);
    printf("You have %d attempts to find it. Good luck!\n\n", maxAttempts);

    int attempts = 0;
    int guess;
    int success = 0; // Flag to track if the player wins

    while (attempts < maxAttempts) {
        printf("Attempt %d/%d: Your guess? ", attempts + 1, maxAttempts);
        scanf("%d", &guess);

        attempts++;

        // Check if the guess is correct or give hints
        if (guess == secretNumber) {
            success = 1;
            break;
        } else if (abs(guess - secretNumber) <= 5) {
            printf("🔥 You're VERY close! 🔥\n");
        } else if (abs(guess - secretNumber) <= 15) {
            printf("🙂 You're close!\n");
        } else {
            printf("❄️ Too far off. Try again.\n");
        }
    }

    // End the game with a success or failure message
    if (success) {
        printf("\n🎉 CONGRATULATIONS! You cracked the code in %d attempts!\n", attempts);
    } else {
        printf("\n💀 GAME OVER. The secret number was %d. Better luck next time!\n", secretNumber);
    }

    // Thank the player for trying
    printf("\nThanks for playing Codebreaker. Keep practicing and you'll be unstoppable!\n");
}
