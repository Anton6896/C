#include <stdbool.h>
#include <stdio.h>

#define count 3

void show_desk(char desk[3][3]);

int winner(char desk[3][3]);

bool can_move(int a, int b, char desk[3][3]);

int make_move(char inner_circleer[50], char sine, char desk[3][3]);

// global var for circles
bool inner = true;
bool outher = true;


int game_on() {

    char p1_sine = 'x';
    char p2_sine = 'o';
    char p1_name[50];
    char p2_name[50];
    char ch;

    // main base desk
    char desk[3][3] = {
            {'.', '.', '.'},
            {'.', '.', '.'},
            {'.', '.', '.'},
    };

    // get inner_circleer names
    printf("\nhello and wellcome to the game tic-toc please use 1-9 keys as at right side of your key board , enjoy\n\n");
    printf("\nplease enter the 1 name he is using the 'X' sine : ");
    scanf("%s", p1_name);
    printf("\nplease enter the 2 name he is using the 'O' sine : ");
    scanf("%s", p2_name);

    while (outher) {
        // create and initiate empty board
        char board[3][3];
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                board[i][j] = desk[i][j];
            };
        };
        // show board
        show_desk(board);

        while (inner) {
            // in ant iteration -1 to exit
            int pl1 = make_move(p1_name, p1_sine, board);
            if (pl1 == -1) {
                // exit game
                break;
            } else if (pl1 == 1) {
                printf("player %s is winner !!!!\n", p1_name);
                printf("would you like to play again ? enter y/n : ");
                scanf("%c", &ch);
                /* ? cant get the player choice here !!!!! */
                getchar();
                (ch == 'y') ? (inner = true, outher = true) : (inner = false, outher = false);
                break;
            };

            int pl2 = make_move(p2_name, p2_sine, board);
            if (pl2 == -1) {
                // exit game
                break;
            } else if (pl2 == 1) {
                printf("player %s is winner !!!!\n", p2_name);
                printf("would you like to play again ? enter y/n");
                scanf("%c", &ch);
                ch == 'y' ? (inner = true, outher = true) : (inner = false, outher = false);
                break;
            };
        };
    };

    printf("\nTnx for game .\n");
    return 0;
};

void show_desk(char desk[3][3]) {
    printf("\n\n\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%c ", desk[i][j]);
        };
        printf("\n");
    };
};

int winner(char desk[3][3]) {

    // this is the trick for debugging the values
    int returnValue = 0;

    if (
            (desk[0][0] == desk[0][1] && desk[0][1] == desk[0][2]) && (desk[0][2] != '.') ||
            (desk[1][0] == desk[1][1] && desk[1][1] == desk[1][2]) && (desk[1][2] != '.') ||
            (desk[2][0] == desk[2][1] && desk[2][1] == desk[2][2]) && (desk[2][2] != '.') ||

            (desk[0][0] == desk[1][0] && desk[1][0] == desk[2][0]) && (desk[2][0] != '.') ||
            (desk[0][1] == desk[1][1] && desk[1][1] == desk[2][1]) && (desk[2][1] != '.') ||
            (desk[0][2] == desk[1][2] && desk[1][2] == desk[2][2]) && (desk[2][2] != '.') ||

            (desk[0][2] == desk[1][1] && desk[1][1] == desk[2][0]) && (desk[2][0] != '.') ||
            (desk[0][0] == desk[1][1] && desk[1][1] == desk[2][2]) && (desk[2][2] != '.')
            ) {
        returnValue = 1;
    };
    return returnValue;
};

bool can_move(int a, int b, char desk[3][3]) {
    if (desk[a][b] == '.') {
        return true;
    };
    return false;
};

int make_move(char inner_circleer[50], char sine, char desk[3][3]) {
    int move = 0;
    bool turn_loop = true;

    do {
        do // get inner_circleer move
        {
            if (move == -1) {
                // out all
                outher = false;
                inner = false;
                return -1;
            };

            printf("%s please enter your move : ", inner_circleer);
            scanf("%d", &move);

        } while (move < 1 || move > 9);

        // convert move to desk and check if availble
        switch (move) {
            case 1:
                if (can_move(2, 0, desk)) {
                    turn_loop = false;
                    desk[2][0] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again\n");
                };
                break;
            case 2:
                if (can_move(2, 1, desk)) {
                    turn_loop = false;
                    desk[2][1] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again\n");
                };
                break;
            case 3:
                if (can_move(2, 2, desk)) {
                    turn_loop = false;
                    desk[2][2] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;

            case 4:
                if (can_move(1, 0, desk)) {
                    turn_loop = false;
                    desk[1][0] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;
            case 5:
                if (can_move(1, 1, desk)) {
                    turn_loop = false;
                    desk[1][1] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;
            case 6:
                if (can_move(1, 2, desk)) {
                    turn_loop = false;
                    desk[1][2] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;

            case 7:
                if (can_move(0, 0, desk)) {
                    turn_loop = false;
                    desk[0][0] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;
            case 8:
                if (can_move(0, 1, desk)) {
                    turn_loop = false;
                    desk[0][1] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;
            case 9:
                if (can_move(0, 2, desk)) {
                    turn_loop = false;
                    desk[0][2] = sine;
                    show_desk(desk);
                } else {
                    printf("you cant go ther sorry ! try again");
                };
                break;

            default:
                break;
        }

    } while (turn_loop);

    // check the winner and ask player to play again if true
    return winner(desk);
};
