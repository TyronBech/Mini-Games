#include "Functions.h"

void show_board(char inputs[]);
int play();
int input_check(char inputs[]);
int Winner_MSG(int result);
void loading();

void TIC_TAC_TOE(){
    int c;
    while(TRUE){
        screen_display();
        gotoxy(51, 4); printf("TIC TAC TOE Game");
        loading();
        int again = Winner_MSG(play());
        if(again == 1){
            while((c = getchar()) != '\n' && c != EOF);
            continue;
        } else break;
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
    char inputs[9] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };
    show_board(inputs);
    char user_choice;
    int computer_choice = 0, c, counter = 1;
    srand(time(0));
    int flag = rand() % 2;
    if(flag == 0){
        // Player first
        gotoxy(53, 22); printf("Player first");
    } else {
        // Computer first
        gotoxy(52, 22); printf("Computer first");
    }
    sleep(3);
    while(TRUE){
        system("cls");
        screen_display();
        gotoxy(51, 4); printf("TIC TAC TOE Game");
        show_board(inputs);
        if(flag == 0){
            gotoxy(39, 22); printf("Enter the number of your choice(1 - 9): ");
            scanf("%c", &user_choice);
            if(!isdigit(user_choice)){
                gotoxy(42, 23); printf("You input a non-integral character");
                gotoxy(43, 24); printf("Please input numbers from (1 - 9)");
                getch();
                flag = 0;
            } else {
                switch (user_choice){
                case '1': if(inputs[0] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[0] = 'X';
                        flag = 1;
                    }
                    break;
                case '2': if(inputs[1] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[1] = 'X';
                        flag = 1;
                    }
                    break;
                case '3': if(inputs[2] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[2] = 'X';
                        flag = 1;
                    }
                    break;
                case '4': if(inputs[3] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[3] = 'X';
                        flag = 1;
                    }
                    break;
                case '5': if(inputs[4] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[4] = 'X';
                        flag = 1;
                    }
                    break;
                case '6': if(inputs[5] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[5] = 'X';
                        flag = 1;
                    }
                    break;
                case '7': if(inputs[6] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[6] = 'X';
                        flag = 1;
                    }
                    break;
                case '8': if(inputs[7] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[7] = 'X';
                        flag = 1;
                    }
                    break;
                case '9': if(inputs[8] != ' '){
                        gotoxy(42, 23); printf("The block was already been inputted");
                        gotoxy(47, 24); printf("Please try another block");
                        getch();
                        flag = 0;
                    } else {
                        inputs[8] = 'X';
                        flag = 1;
                    }
                    break;
                default: gotoxy(47, 23); printf("That is a invalid choice");
                }
                while((c = getchar()) != '\n' && c != EOF);
            }
        } else {
            while(TRUE){
                computer_choice = rand() % 9;
                if(inputs[computer_choice] != ' ') {
                    flag = 1;
                    break;
                }
                else {
                    inputs[computer_choice] = 'O';
                    flag = 0;
                    break;
                }
            }
        }
        show_board(inputs);
        int result = input_check(inputs);
        if(result == 1) return 1;
        else if(result == 2) return 2;
        else {
            counter++;
            continue;
        }
        if(counter >= 9){
            while((c = getchar()) != '\n' && c != EOF);
            break;
        }
    }
    return 0;
}
int input_check(char inputs[]){
    if(inputs[0] == 'X' && inputs[1] == 'X' && inputs[2] == 'X') return 1;
    else if(inputs[3] == 'X' && inputs[4] == 'X' && inputs[5] == 'X') return 1;
    else if(inputs[6] == 'X' && inputs[7] == 'X' && inputs[8] == 'X') return 1;
    else if(inputs[0] == 'X' && inputs[3] == 'X' && inputs[6] == 'X') return 1;
    else if(inputs[1] == 'X' && inputs[4] == 'X' && inputs[7] == 'X') return 1;
    else if(inputs[2] == 'X' && inputs[5] == 'X' && inputs[8] == 'X') return 1;
    else if(inputs[0] == 'X' && inputs[4] == 'X' && inputs[8] == 'X') return 1;
    else if(inputs[2] == 'X' && inputs[4] == 'X' && inputs[6] == 'X') return 1;

    else if(inputs[0] == 'O' && inputs[1] == 'O' && inputs[2] == 'O') return 2;
    else if(inputs[3] == 'O' && inputs[4] == 'O' && inputs[5] == 'O') return 2;
    else if(inputs[6] == 'O' && inputs[7] == 'O' && inputs[8] == 'O') return 2;
    else if(inputs[0] == 'O' && inputs[3] == 'O' && inputs[6] == 'O') return 2;
    else if(inputs[2] == 'O' && inputs[4] == 'O' && inputs[7] == 'O') return 2;
    else if(inputs[2] == 'O' && inputs[5] == 'O' && inputs[8] == 'O') return 2;
    else if(inputs[0] == 'O' && inputs[4] == 'O' && inputs[8] == 'O') return 2;
    else if(inputs[2] == 'O' && inputs[4] == 'O' && inputs[6] == 'O') return 2;
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
void loading(){
    char symbols[] = {'|', '/', '-', '\\'};
    srand(time(0));
    short result = rand() % 4 + 1;
    for(short i = 0; i < result; i++){
        for(short j = 0; j < 4; j++){
            gotoxy(55, 22); printf("Loading %c", symbols[j]);
            usleep(200000);
        }
    }
}
