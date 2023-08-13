#include "Functions.h"

int Identify_Winner(char user, char computer);
char Computer_Generated_Choice();
void Hands(char user, char computer);
/// @brief RPS main function, all the needed program are
/// done in this function by the help of other necessary
/// functions of RPS.c
void ROCK_PAPER_SCISSORS(){
    int c = 0;
    char user_choice, computer_choice, again;
    // Looping the game until user decided to quit
    while(TRUE){
        screen_display();
        gotoxy(49, 4); printf("ROCK-PAPER-SCISSOR GAME\n");
        gotoxy(54, 6); printf("A - Rock");
        gotoxy(54, 7); printf("B - Paper");
        gotoxy(54, 8); printf("C - Scissors");
        gotoxy(51, 9); printf("Enter your choice: ");
        // Getting user's input
        scanf("%c", &user_choice);
        user_choice = toupper(user_choice);
        if(user_choice != 'A' && user_choice != 'B' && user_choice != 'C') {
            gotoxy(51, 10); printf("That is a invalid choice");
            while((c = getchar()) != '\n' && c != EOF);
            getch();
            continue;
        }
        // Generate computers choice
        computer_choice = Computer_Generated_Choice();
        // sleeping for 1 second before showing the choices
        for(int i = 5; i > 0; i--){
            gotoxy(60, 11); printf("%d", i);
            sleep(1);
        }
        gotoxy(60, 11); printf(" ");
        gotoxy(55, 14); printf("__   _____");
        gotoxy(55, 15); printf("\\ \\ / / __|");
        gotoxy(56, 16); printf("\\ V /\\__ \\");
        gotoxy(57, 17); printf("\\_/ |___/");
        // Calling the Hands function to print the hands
        // based on user's & computer's choice
        Hands(user_choice, computer_choice);
        // Calling the Identify_Winner to know who wins
        int result = Identify_Winner(user_choice, computer_choice);
        // Checking the result of the function by switch
        switch(result){
        case 0:
            gotoxy(56, 21); printf("It is a tie");
            break;
        case 1:
            gotoxy(48, 21); printf("Congratulations! You win!!!");
            break;
        case 2:
            gotoxy(54, 21); printf("Sorry! You lose");
            break;
        }
        // Sleep for 4 seconds before asking the user is he/she wants to play again
        sleep(4);
        while((c = getchar()) != '\n' && c != EOF);
        gotoxy(29, 21); printf("You want to play again? Enter Y if yes or any other keys if no: ");
        // Getting user's input
        scanf("%c", &again);
        again = toupper(again);
        // Checking the input
        if(again == 'Y')
            while((c = getchar()) != '\n' && c != EOF);
        else {
            while((c = getchar()) != '\n' && c != EOF);
            break;
        }
    }
}
/// @brief The function will define who's the winner
/// @param user passing the user's choice
/// @param computer passing the computer's choice
/// @return return 0 if it is tie, 1 if user wins, else 2
/// if computer wins
int Identify_Winner(char user, char computer){
    // return 0 means Tie
    // return 1 means user win
    // return 2 means computer win
    switch (user)
    {
    case 'A':
        if(computer == 'A') {
            gotoxy(36, 19); printf("Player: ");
            printf("Rock");
            gotoxy(74, 19); printf("Computer: ");
            printf("Rock");
            return 0;
        }
        else if(computer == 'B') {
            gotoxy(36, 19); printf("Player: ");
            printf("Rock");
            gotoxy(76, 19); printf("Computer: ");
            printf("Paper");
            return 2;
        }
        else {
            gotoxy(36, 19); printf("Player: ");
            printf("Rock");
            gotoxy(76, 19); printf("Computer: ");
            printf("Scissors");
            return 1;
        }
        break;
    case 'B':
        if(computer == 'A') {
            gotoxy(35, 19); printf("Player: ");
            printf("Paper");
            gotoxy(74, 19); printf("Computer: ");
            printf("Rock");
            return 1;
        }
        else if(computer == 'B') {
            gotoxy(35, 19); printf("Player: ");
            printf("Paper");
            gotoxy(76, 19); printf("Computer: ");
            printf("Paper");
            return 0;
        }
        else {
            gotoxy(35, 19); printf("Player: ");
            printf("Paper");
            gotoxy(76, 19); printf("Computer: ");
            printf("Scissors");
            return 2;
        }
        break;
    case 'C':
        if(computer == 'A') {
            gotoxy(34, 19); printf("Player: ");
            printf("Scissors");
            gotoxy(74, 19); printf("Computer: ");
            printf("Rock");
            return 2;
        }
        else if(computer == 'B') {
            gotoxy(34, 19); printf("Player: ");
            printf("Scissors");
            gotoxy(76, 19); printf("Computer: ");
            printf("Paper");
            return 1;
        }
        else {
            gotoxy(34, 19); printf("Player: ");
            printf("Scissors");
            gotoxy(76, 19); printf("Computer: ");
            printf("Scissors");
            return 0;
        }
        break;
    }
    return 0;
}
/// @brief Generates a random choice for computer using rand()
/// @return It will return the generated choice for the computer
char Computer_Generated_Choice(){
    srand(time(0));
    int result = rand() % 3;
    switch(result){
        case 0: return 'A';
        case 1: return 'B';
        case 2: return 'C';
    }
    return 'A';
}
/// @brief The Hands functio will print an ASCII hand based on
/// user and computer choice
/// @param user parameter for user's choice
/// @param computer parameter for computer's choice
void Hands(char user, char computer){
    // Hand gestures using ASCII characters
    /// @author Veronica Karlsson
    /// @link https://www.asciiart.eu/people/body-parts/hand-gestures
    char Hand_Rock[][20] = {
        "    _______\0",
        "---'   ____)\0",
        "      (_____)\0",
        "      (_____)\0",
        "      (____)\0",
        "---.__(___)\0"
    };
    char Hand_Paper[][20] = {
        "    _______\0",
        "---'   ____)____\0",
        "          ______)\0",
        "          _______)\0",
        "         _______)\0",
        "---.__________)\0"
    };
    char Hand_Scissor[][20] = {
        "    _______\0",
        "---'   ____)____\0",
        "          ______)\0",
        "       __________)\0",
        "      (____)\0",
        "---.__(___)\0"
    };
    char Hand_Rock_Reverse[][20] = {
        "  _______\0",
        " (____   '---\0",
        "(_____)      \0",
        "(_____)      \0",
        " (____)      \0",
        "  (___)__.---\0"
    };
    char Hand_Paper_Reverse[][20] = {
        "       _______\0",
        "  ____(____   '---\0",
        " (______          \0",
        "(_______          \0",
        " (_______         \0",
        "   (__________.---\0"
    };
    char Hand_Scissor_Reverse[][20] = {
        "       _______    \0",
        "  ____(____   '---\0",
        " (______          \0",
        "(__________       \0",
        "      (____)      \0",
        "       (___)__.---\0",
    };
    switch(user){
    case 'A':
        for(short i = 0; i < 6; i++){
            gotoxy(35, i + 12); printf("%s\n", Hand_Rock[i]);
        }
        break;
    case 'B':
        for(short i = 0; i < 6; i++){
            gotoxy(33, i + 12); printf("%s\n", Hand_Paper[i]);
        }
        break;
    case 'C':
        for(short i = 0; i < 6; i++){
            gotoxy(33, i + 12); printf("%s\n", Hand_Scissor[i]);
        }
        break;
    }
    switch(computer){
    case 'A':
        for(short i = 0; i < 6; i++){
            gotoxy(73, i + 12); printf("%s\n", Hand_Rock_Reverse[i]);
        }
        break;
    case 'B':
        for(short i = 0; i < 6; i++){
            gotoxy(73, i + 12); printf("%s\n", Hand_Paper_Reverse[i]);
        }
        break;
    case 'C':
        for(short i = 0; i < 6; i++){
            gotoxy(73, i + 12); printf("%s\n", Hand_Scissor_Reverse[i]);
        }
        break;
    }
}