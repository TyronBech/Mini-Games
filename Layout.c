#include "Functions.h"

void gotoxy(short x, short y){
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void screen_display(){
    system("cls");
    for(short i = 5; i <= 115; i++){
        gotoxy(i, 1); printf("-");
        gotoxy(i, 28); printf("-");
    }
    for(short i = 15; i <= 105; i++){
        gotoxy(i, 2); printf("-");
        gotoxy(i, 27); printf("-");
    }
}