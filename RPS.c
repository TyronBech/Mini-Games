#include "Functions.h"

int Identify_Winner(char user, char computer);
char Computer_Generated_Choice();
void Hands(char user, char computer);
void Player_Status_MSG(int result);

void ROCK_PAPER_SCISSORS(){
    int c = 0;
    char user_choice, computer_choice, again;
    while(TRUE){
        screen_display();
        gotoxy(49, 4); printf("ROCK-PAPER-SCISSOR GAME\n");
        gotoxy(54, 6); printf("A - Rock");
        gotoxy(54, 7); printf("B - Paper");
        gotoxy(54, 8); printf("C - Scissors");
        gotoxy(51, 9); printf("Enter your choice: ");
        scanf("%c", &user_choice);
        user_choice = toupper(user_choice);
        if(user_choice != 'A' && user_choice != 'B' && user_choice != 'C') {
            gotoxy(51, 10); printf("That is a invalid choice");
            while((c = getchar()) != '\n' && c != EOF);
            getch();
            continue;
        }
        computer_choice = Computer_Generated_Choice();
        for(int i = 5; i > 0; i--){
            gotoxy(60, 11); printf("%d", i);
            sleep(1);
        }
        gotoxy(60, 11); printf(" ");
        gotoxy(55, 14); printf("__   _____");
        gotoxy(55, 15); printf("\\ \\ / / __|");
        gotoxy(56, 16); printf("\\ V /\\__ \\");
        gotoxy(57, 17); printf("\\_/ |___/");
        Hands(user_choice, computer_choice);
        int result = Identify_Winner(user_choice, computer_choice);
        Player_Status_MSG(result);
        sleep(4);
        while((c = getchar()) != '\n' && c != EOF);
        gotoxy(27, 25); printf("You want to play again? Enter Y if yes or any other keys if no: ");
        scanf("%c", &again);
        again = toupper(again);
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
void Player_Status_MSG(int result){
    /// @link http://www.patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
    sleep(5);
    if(result == 0){
        gotoxy(19, 12); printf("          .-') _        .-')            ('-.           .-') _             ('-.   ");
        gotoxy(19, 13); printf("         (  OO) ) ,--. ( OO ).         ( OO ).-.      (  OO) )          _(  OO)  ");
        gotoxy(19, 14); printf("  ,-.-') /     '._\\  |(_)---\\_)        / . --. /      /     '._ ,-.-') (,------. ");
        gotoxy(19, 15); printf("  |  |OO)|'--...__)`-'/    _ |         | \\-.  \\       |'--...__)|  |OO) |  .---' ");
        gotoxy(19, 16); printf("  |  |  \\'--.  .--'   \\  :` `.       .-'-'  |  |      '--.  .--'|  |  \\ |  |     ");
        gotoxy(19, 17); printf("  |  |(_/   |  |       '..`''.)       \\| |_.'  |         |  |   |  |(_/(|  '--.  ");
        gotoxy(19, 18); printf(" ,|  |_.'   |  |      .-._)   \\        |  .-.  |         |  |  ,|  |_.' |  .--'  ");
        gotoxy(19, 19); printf("(_|  |      |  |      \\       /        |  | |  |         |  | (_|  |    |  `---. ");
        gotoxy(19, 20); printf("  `--'      `--'       `-----'         `--' `--'         `--'   `--'    `------' ");
    } else if(result == 1){
        gotoxy(21, 12); printf("                                              (`\\ .-') /`            .-') _  ");
        gotoxy(21, 13); printf("                                               `.( OO ),'           ( OO ) ) ");
        gotoxy(21, 14); printf("  ,--.   ,--..-'),-----.  ,--. ,--.         ,--./  .--.  ,-.-') ,--./ ,--,'  ");
        gotoxy(21, 15); printf("   \\  `.'  /( OO'  .-.  ' |  | |  |         |      |  |  |  |OO)|   \\ |  |\\  ");
        gotoxy(21, 16); printf(" .-')     / /   |  | |  | |  | | .-')       |  |   |  |, |  |  \\|    \\|  | ) ");
        gotoxy(21, 17); printf("(OO  \\   /  \\_) |  |\\|  | |  |_|( OO )      |  |.'.|  |_)|  |(_/|  .     |/  ");
        gotoxy(21, 18); printf(" |   /  /\\_   \\ |  | |  | |  | | `-' /      |         | ,|  |_.'|  |\\    |   ");
        gotoxy(21, 19); printf(" `-./  /.__)   `'  '-'  '('  '-'(_.-'       |   ,'.   |(_|  |   |  | \\   |   ");
        gotoxy(21, 20); printf("   `--'          `-----'   `-----'          '--'   '--'  `--'   `--'  `--'   ");
    } else {
        gotoxy(17, 12); printf("                                                                     .-')      ('-.   ");
        gotoxy(17, 13); printf("                                                                    ( OO ).  _(  OO)  ");
        gotoxy(17, 14); printf("  ,--.   ,--..-'),-----.  ,--. ,--.          ,--.      .-'),-----. (_)---\\_)(,------. ");
        gotoxy(17, 15); printf("   \\  `.'  /( OO'  .-.  ' |  | |  |          |  |.-') ( OO'  .-.  '/    _ |  |  .---' ");
        gotoxy(17, 16); printf(" .-')     / /   |  | |  | |  | | .-')        |  | OO )/   |  | |  |\\  :` `.  |  |     ");
        gotoxy(17, 17); printf("(OO  \\   /  \\_) |  |\\|  | |  |_|( OO )       |  |`-' |\\_) |  |\\|  | '..`''.)(|  '--.  ");
        gotoxy(17, 18); printf(" |   /  /\\_   \\ |  | |  | |  | | `-' /      (|  '---.'  \\ |  | |  |.-._)   \\ |  .--'  ");
        gotoxy(17, 19); printf(" `-./  /.__)   `'  '-'  '('  '-'(_.-'        |      |    `'  '-'  '\\       / |  `---. ");
        gotoxy(17, 20); printf("   `--'          `-----'   `-----'           `------'      `-----'  `-----'  `------' ");
    }
}