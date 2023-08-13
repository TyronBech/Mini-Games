#include "Functions.h"

void show_board(char inputs[]);
int play();
int check_winner(char inputs[], char symbol);
/// @brief Tic Tac Toe game main function
/// where all the program needed for the came is
/// written
void TIC_TAC_TOE(){
    // Getting the time as sampling for who's going to play first
    srand(time(NULL));
    int play_again = 1, c;
    // Looping the program until user decided to quit
    while (play_again) {
        // Calling the screen_disply for border
        screen_display();
        gotoxy(51, 4); printf("TIC TAC TOE Game");
        // Sleep for 1 second before continuing
        sleep(1);
        // Calling the play function to execute the game
        int result = play();
        // checking who wins the game
        if (result == 1) {
            gotoxy(46, 23); printf("Congratulations! You Win!!!");
        } else if (result == 2) {
            gotoxy(52, 23); printf("Sorry! You lose");
        } else {
            gotoxy(54, 23); printf("No one wins");
        }
        // Sleep for 2 second before asking the user if he/she wants to play again
        sleep(2);
        gotoxy(28, 22); printf("You want to play again? Enter Y if yes or any other key if no: ");
        char choice;
        scanf(" %c", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        play_again = (choice == 'Y' || choice == 'y');
    }
}
/// @brief show_board function will print the board along with the inputs from user
/// and computer
/// @param inputs inputs as parameter is an array where the inputs of players are stored 
void show_board(char inputs[]){
    gotoxy(48, 6); printf("       |       |       ");
    gotoxy(48, 7); printf("       |       |       ");
    gotoxy(48, 8); printf("   %c   |   %c   |   %c   ", inputs[0], inputs[1], inputs[2]);
    gotoxy(48, 9); printf("       |       |       ");
    gotoxy(48, 10); printf("_______|_______|_______");
    gotoxy(48, 11); printf("       |       |       ");
    gotoxy(48, 12); printf("       |       |       ");
    gotoxy(48, 13); printf("   %c   |   %c   |   %c   ", inputs[3], inputs[4], inputs[5]);
    gotoxy(48, 14); printf("       |       |       ");
    gotoxy(48, 15); printf("_______|_______|_______");
    gotoxy(48, 16); printf("       |       |       ");
    gotoxy(48, 17); printf("       |       |       ");
    gotoxy(48, 18); printf("   %c   |   %c   |   %c   ", inputs[6], inputs[7], inputs[8]);
    gotoxy(48, 19); printf("       |       |       ");
    gotoxy(48, 20); printf("       |       |       ");
}
/// @brief play function is the actual game area where user and computer plat the game
/// @return it will return who wins the match 0 for tie, 1 if user wins else 2 if computer wins
int play(){
    // inputs is where the inputs of players are stored and checked
    char inputs[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    // symbols used for the game
    const char player_symbol = 'X';
    const char computer_symbol = 'O';
    // counter to check if the board still contains spaces
    int counter = 0;

    // Determine who goes first
    int is_player_turn = rand() % 2 == 0;
    // Looping the program until someone wins or if the board has no spaces anymore
    while (counter < 9) {
        system("clear");
        screen_display();
        show_board(inputs);
        gotoxy(51, 4); printf("TIC TAC TOE Game");
        if (is_player_turn) {
            // Player's turn
            int position;
            do {
                gotoxy(39, 22); printf("Enter the number of your choice (1 - 9): ");
                // Getting the user's input
                // input must be checked if valid, if not user will try to input again
                if (scanf("%d", &position) != 1) {
                    gotoxy(32, 23); printf("Invalid input. Please enter a number between 1 and 9.");
                    sleep(3);
                    while (getchar() != '\n'); // Clear input buffer
                    system("clear");
                    screen_display();
                    show_board(inputs);
                    gotoxy(51, 4); printf("TIC TAC TOE Game");
                    position = -1; // Set an invalid position to repeat the loop
                } else {
                    position--; // Convert to 0-based index
                    // if the input is not in the range, its not valid
                    if(position < 0 || position > 8){
                        gotoxy(47, 23); printf("That is a invalid choice"); 
                        sleep(3);
                        while (getchar() != '\n'); // Clear input buffer
                        system("clear");
                        screen_display();
                        show_board(inputs);
                        gotoxy(51, 4); printf("TIC TAC TOE Game");
                    }
                    // if the area is already been inputted, its not valid
                    else if(inputs[position] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        sleep(3);
                        while (getchar() != '\n'); // Clear input buffer
                        system("clear");
                        screen_display();
                        show_board(inputs);
                        gotoxy(51, 4); printf("TIC TAC TOE Game");
                    }
                }
            } while (position < 0 || position > 8 || inputs[position] != ' ');
            inputs[position] = player_symbol;
        } else {
            // Computer's turn
            int position;
            // Looping the input until the area of input is valid
            do {
                position = rand() % 9;
            } while (inputs[position] != ' ');
            inputs[position] = computer_symbol;
        }
        // Checking if there's already a winner of there
        // is the loop will terminate
        if (check_winner(inputs, player_symbol)) {
            show_board(inputs);
            return 1; // Player wins
        } else if (check_winner(inputs, computer_symbol)) {
            show_board(inputs);
            return 2; // Computer wins
        }
        // Incrementing the counter varible for each loop to
        // identify how many space are still available
        counter++;
        // Changing the turn from player to computer and vice versa
        is_player_turn = !is_player_turn;
    }
    // Reshowing the board
    show_board(inputs);
    // If the loop stop and still no winner, it means its a draw
    return 0; // Draw
}
/// @brief Checking if the symbol exist in an specific area where 3 symbols are aligned
/// either horizontally, vertically, or diagonally
/// @param inputs inputs parameter is where the inputs are stored and needed for checking
/// @param symbol symbol parameter will based on the player if user 'X' or computer 'O'
/// @return it will return 1 if the function encounters alignment else 0 if not
int check_winner(char inputs[], char symbol){
    if(inputs[0] == symbol && inputs[1] == symbol && inputs[2] == symbol) return 1;
    else if(inputs[3] == symbol && inputs[4] == symbol && inputs[5] == symbol) return 1;
    else if(inputs[6] == symbol && inputs[7] == symbol && inputs[8] == symbol) return 1;
    else if(inputs[0] == symbol && inputs[3] == symbol && inputs[6] == symbol) return 1;
    else if(inputs[1] == symbol && inputs[4] == symbol && inputs[7] == symbol) return 1;
    else if(inputs[2] == symbol && inputs[5] == symbol && inputs[8] == symbol) return 1;
    else if(inputs[0] == symbol && inputs[4] == symbol && inputs[8] == symbol) return 1;
    else if(inputs[2] == symbol && inputs[4] == symbol && inputs[6] == symbol) return 1;
    else return 0;
}