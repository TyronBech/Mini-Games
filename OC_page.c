#include "Functions.h"
#include<pthread.h>
/// @brief The opening page will print the computer
/// with related text inside before continuing the program
void Opening_Page(){
   system("cls");
   gotoxy(22, 1); printf("             _______________________________________________");
   gotoxy(22, 2); printf("            /                                               \\");
   gotoxy(22, 3); printf("           |    _________________________________________    |");
   gotoxy(22, 4); printf("           |   |                                         |   |");
   gotoxy(22, 5); printf("           |   |                                         |   |");
   gotoxy(22, 6); printf("           |   |                                         |   |");
   gotoxy(22, 7); printf("           |   |                                         |   |");
   gotoxy(22, 8); printf("           |   |                                         |   |");
   gotoxy(22, 9); printf("           |   |                                         |   |");
   gotoxy(22, 10); printf("           |   |                                         |   |");
   gotoxy(22, 11); printf("           |   |                                         |   |");
   gotoxy(22, 12); printf("           |   |                                         |   |");
   gotoxy(22, 13); printf("           |   |                                         |   |");
   gotoxy(22, 14); printf("           |   |                                         |   |");
   gotoxy(22, 15); printf("           |   |                                         |   |");
   gotoxy(22, 16); printf("           |   |                                         |   |");
   gotoxy(22, 17); printf("           |   |_________________________________________|   |");
   gotoxy(22, 18); printf("           |                                                 |");
   gotoxy(22, 19); printf("            \\_______________________________________________/");
   gotoxy(22, 20); printf("                   \\___________________________________/");
   gotoxy(22, 21); printf("                ___________________________________________");
   gotoxy(22, 22); printf("             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_");
   gotoxy(22, 23); printf("          _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_");
   gotoxy(22, 24); printf("       _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_");
   gotoxy(22, 25); printf("    _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_");
   gotoxy(22, 26); printf(" _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_");
   gotoxy(22, 27); printf(":-------------------------------------------------------------------------:");
   gotoxy(22, 28); printf("`---._.-------------------------------------------------------------._.---'");
   char CMD[] = "C:\\> executing mini_games.exe";
   // printing and deprinting the underscore to look like
   // someone is typing
   gotoxy(41, 5); printf("%c%c%c%c%c", CMD[0], CMD[1], CMD[2], CMD[3], CMD[4]);
   for(int i = 0; i < 6; i++){
      if(i % 2 == 0){
         gotoxy(46, 5); printf("_");
      } else {
         gotoxy(46, 5); printf(" ");
      }
      usleep(500000);
   }
   for(short i = 5; i < sizeof(CMD)/sizeof(CMD[0]); i++){
      gotoxy(i + 41, 5); printf("%c_", CMD[i]);
      if(i % 4 == 0){
         usleep(700000);
      } else {
         usleep(200000);
      }
   }
   // printing and deprinting the underscore to look like
   // someone is typing
   gotoxy(70, 5); printf(" ");
   gotoxy(49, 8); printf("Welcome to the game_");
   gotoxy(68, 8); printf(" ");
   usleep(200000);
   gotoxy(68, 8); printf("_");
   gotoxy(68, 8); printf(" ");
   usleep(200000);
   gotoxy(68, 8); printf("_");
   usleep(200000);
   gotoxy(68, 8); printf(" ");
   gotoxy(51, 10); printf("Available games:_");
   usleep(200000);
   gotoxy(67, 10); printf(" ");
   usleep(100000);
   gotoxy(50, 11); printf("Rock Paper Scissor_");
   usleep(200000);
   gotoxy(68, 11); printf("  ");
   gotoxy(53, 12); printf("TIC TAC TOE");
   sleep(2);
}
// Threading for closing page
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int flag = 0;
/// @brief The function will print the thank you message
/// on the screen repeatedly while moving to the console
/// @param arg parameter to thread
/// @return return a NULL to the thread
void *TY_Message(void *arg){
   int drive1 = 1, drive2 = 1, i = 1, j = 1;
   while(!flag){
      system("cls");
      if(drive1 == 0) i--;
      else i++;
      if(drive2 == 0) j--;
      else j++;
      pthread_mutex_lock(&mutex);
      gotoxy(i, j); printf("Thank you for playing");
      pthread_mutex_unlock(&mutex);
      usleep(100000);
      if(i >= 98) drive1 = 0;
      if(j >= 27) drive2 = 0;
      if(i <= 1) drive1 = 1;
      if(j <= 1) drive2 = 1;
   }
   return NULL;
}
/// @brief The closing will call and execute the
/// TY_Message in a thread and runs until user
/// press any key
void Closing_Page(){
   pthread_t thank_you;
    pthread_create(&thank_you, NULL, TY_Message, NULL);
    gotoxy(49, 25); printf("Press any key to exit");
    while(!kbhit()){}
    getch();
    flag = 1;
    pthread_join(thank_you, NULL);
}