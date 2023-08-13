#include "Functions.h"

void show_board(char inputs[]);
int play();
int check_winner(char inputs[], char symbol);
int Winner_MSG(int result);

void TIC_TAC_TOE(){
    srand(time(NULL));
    int play_again = 1, c;
    while (play_again) {
        screen_display();
        gotoxy(51, 4); printf("TIC TAC TOE Game");
        sleep(1);
        int result = play();
        if (result == 1) {
            gotoxy(46, 23); printf("Congratulations! You Win!!!");
        } else if (result == 2) {
            gotoxy(52, 23); printf("Sorry! You lose");
        } else {
            gotoxy(54, 23); printf("No one wins");
        }
        sleep(2);
        gotoxy(28, 22); printf("You want to play again? Enter Y if yes or any other key if no: ");
        char choice;
        scanf(" %c", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        play_again = (choice == 'Y' || choice == 'y');
    }
}
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
int play(){
    char inputs[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    const char player_symbol = 'X';
    const char computer_symbol = 'O';
    int counter = 0;

    // Determine who goes first
    int is_player_turn = rand() % 2 == 0;

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
                if (scanf("%d", &position) != 1) {
                    gotoxy(32, 23); printf("Invalid input. Please enter a number between 1 and 9.");
                    while (getchar() != '\n'); // Clear input buffer
                    system("clear");
                    screen_display();
                    show_board(inputs);
                    gotoxy(51, 4); printf("TIC TAC TOE Game");
                    sleep(3);
                    position = -1; // Set an invalid position to repeat the loop
                } else {
                    position--; // Convert to 0-based index
                    if(inputs[position] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                    } else if(position < 0 || position > 8){
                        gotoxy(47, 23); printf("That is a invalid choice"); 
                        getch();
                    }
                }
            } while (position < 0 || position > 8 || inputs[position] != ' ');
            inputs[position] = player_symbol;
        } else {
            // Computer's turn
            int position;
            do {
                position = rand() % 9;
            } while (inputs[position] != ' ');
            inputs[position] = computer_symbol;
        }  
        if (check_winner(inputs, player_symbol)) {
            show_board(inputs);
            return 1; // Player wins
        } else if (check_winner(inputs, computer_symbol)) {
            show_board(inputs);
            return 2; // Computer wins
        }
        counter++;
        is_player_turn = !is_player_turn;
    }
    show_board(inputs);
    return 0; // Draw
}
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
int Winner_MSG(int result){
    char again;
    if(result == 1){
        gotoxy(46, 23); printf("Congratulations! You Win!!!");
    } else if(result == 2){
        gotoxy(52, 23); printf("Sorry! You lose");
    } else {
        gotoxy(54, 23); printf("No one wins");
    }
    sleep(3);
    gotoxy(28, 22); printf("You want to play again? Enter Y if yes or any other key if no: ");
    scanf("%c", &again);
    again = toupper(again);
    return (again == 'Y') ? 1 : 0;
}