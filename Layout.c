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
enum TEXT_COLOR {
	MAGENTA = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY,
	YELLOW = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
	BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	RESET_COLOR = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};
void Color(short colorCode){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (colorCode) {
    case 1: SetConsoleTextAttribute(handle, MAGENTA);
        break;
    case 2: SetConsoleTextAttribute(handle, YELLOW);
        break;
    case 3: SetConsoleTextAttribute(handle, CYAN);
        break;
    case 4: SetConsoleTextAttribute(handle, RED);
        break;
    case 5: SetConsoleTextAttribute(handle, BLUE);
        break;
    case 6: SetConsoleTextAttribute(handle, GREEN);
        break;
    case 7: SetConsoleTextAttribute(handle, RESET_COLOR);
    }
}