#include "Functions.h"

int main(){
    int c = 0;
    char choice;
    do{
        screen_display();
        printf("Mini Games\n");
        printf("A - ROCK-PAPER-SCISSORS\n");
        printf("B - TIC-TAC-TOE\n");
        printf("C - Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        choice = toupper(choice);
        switch (choice)
        {
        case 'A':
            while((c = getchar()) != '\n' && c != EOF);
            ROCK_PAPER_SCISSORS();
            break;
        case 'B':
            while((c = getchar()) != '\n' && c != EOF);
            break;
        case 'C':
            break;
        default: printf("That is a invalid choice");
        }
        c = getch();
        while((c = getchar()) != '\n' && c != EOF);
    }while(choice != 'C');
    system("cls");
    printf("Thank you for playing");
    getch();
    return 0;
}