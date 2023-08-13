#include "Functions.h"

/// @brief Main function of the program where the execution
/// of codes is started
/// @return return 0 if the program run successfully else 1
int main(){
    int c = 0;
    char choice;
    // Calling the opening page to create a decent introduction
    Opening_Page();
    // The program loops until the user decided to exit the program
    do{
        screen_display();
        gotoxy(55, 4); printf("Mini Games");
        gotoxy(48, 6); printf("A - ROCK-PAPER-SCISSORS");
        gotoxy(48, 7); printf("B - TIC-TAC-TOE");
        gotoxy(48, 8); printf("C - Exit");
        gotoxy(48, 9); printf("Enter your choice: ");
        // Getting user's input
        scanf("%c", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        choice = toupper(choice);
        switch (choice)
        {
        case 'A': // Choice A for Rock Paper Scissor game
            ROCK_PAPER_SCISSORS();
            break;
        case 'B': // Choice B for Tic Tac Toe game
            TIC_TAC_TOE();
            break;
        case 'C': // Exit case
            break;
        default: gotoxy(49, 11); printf("That is a invalid choice");
            while((c = getchar()) != '\n' && c != EOF);
        }
    }while(choice != 'C');
    // Calling the closing page to end the program
    Closing_Page();
    return 0;
}