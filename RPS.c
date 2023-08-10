#include "Functions.h"

int Identify_Winner(char user, char computer);
char Computer_Generated_Choice();
void Hands(char user, char computer);

void ROCK_PAPER_SCISSORS(){
    int c = 0;
    char user_choice, computer_choice;
    while(TRUE){
        screen_display();
        gotoxy(49, 4); printf("ROCK-PAPER-SCISSOR GAME\n");
        gotoxy(54, 6); printf("A - Rock");
        gotoxy(54, 7); printf("B - Paper");
        gotoxy(54, 8); printf("C - Scissors");
        gotoxy(51, 9); printf("Enter your choice: ");
        scanf("%c", &user_choice);
        user_choice = toupper(user_choice);
        computer_choice = Computer_Generated_Choice();
        for(short i = 5; i < 0; i--){
            gotoxy(60, 11); printf("%d", i);
            sleep(1);
        }
        Hands(user_choice, computer_choice);
        Identify_Winner(user_choice, computer_choice);
        c = getch();
        while((c = getchar()) != '\n' && c != EOF);
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
        if(computer == 'A') return 0;
        else if(computer == 'B') return 2;
        else return 1;
        break;
    case 'B':
        if(computer == 'A') return 1;
        else if(computer == 'B') return 0;
        else return 2;
        break;
    case 'C':
        if(computer == 'A') return 2;
        else if(computer == 'B') return 1;
        else return 0;
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
void Hands(char user, char computer){
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
            printf("%s\n", Hand_Rock[i]);
        }
        break;
    case 'B':
        for(short i = 0; i < 6; i++){
            printf("%s\n", Hand_Paper[i]);
        }
        break;
    case 'C':
        for(short i = 0; i < 6; i++){
            printf("%s\n", Hand_Scissor[i]);
        }
        break;
    }
    switch(computer){
    case 'A':
        for(short i = 0; i < 6; i++){
            printf("%s\n", Hand_Rock_Reverse[i]);
        }
        break;
    case 'B':
        for(short i = 0; i < 6; i++){
            printf("%s\n", Hand_Paper_Reverse[i]);
        }
        break;
    case 'C':
        for(short i = 0; i < 6; i++){
            printf("%s\n", Hand_Scissor_Reverse[i]);
        }
        break;
    }
}
/*
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)

    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)

    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
*/