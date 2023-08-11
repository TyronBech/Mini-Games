#include "Functions.h"

int main(){
    int c = 0;
    char choice;
    do{
        screen_display();
        gotoxy(55, 4); printf("Mini Games");
        gotoxy(48, 6); printf("A - ROCK-PAPER-SCISSORS");
        gotoxy(48, 7); printf("B - TIC-TAC-TOE");
        gotoxy(48, 8); printf("C - Exit");
        gotoxy(48, 9); printf("Enter your choice: ");
        scanf("%c", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        choice = toupper(choice);
        switch (choice)
        {
        case 'A':
            ROCK_PAPER_SCISSORS();
            break;
        case 'B':
            break;
        case 'C':
            break;
        default: gotoxy(49, 11); printf("That is a invalid choice");
        }
        while((c = getchar()) != '\n' && c != EOF);
        c = getch();
    }while(choice != 'C');
    system("cls");
    printf("Thank you for playing");
    getch();
    return 0;
}