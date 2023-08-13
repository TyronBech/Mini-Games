#include "Functions.h"
/// @brief gotoxy function will help the program
/// to print all the text on its designated x y coodinate
/// @param x x parameter will determine the posistion of
/// the text horizontally
/// @param y y parameter will determine the posistion of
/// the text vertically
void gotoxy(short x, short y){
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
/// @brief The function is used to print border
/// for top and bottom of the console
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