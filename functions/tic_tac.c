#include <stdbool.h>
#include <stdio.h>

void show_desk(char desk[3][3]);
bool winner(char desk[3][3]);

int main() {
    char desk[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'},
    };
    int game_on = 1;

    while (game_on) {
        // initiate new board
        char board[3][3] = desk;
        int play = 1;
        char player_1_sine = 'x';
        char player_1_name[30], player_2_name[30];
        char player_2_sine = 'o';

        // get player names
        printf("please enter the player 1 name he is using the X sine : ");
        scanf("%[^\n]%*c", player_1_name);
        printf("\n player %s win ", player_1_name);
        // assign the play marker for player
        // start the game sequence (while one of the players push -1)

        while (play) {
            break;
        };
        break;
    };
    printf("\nTnx for game .\n");
    return 0;
};

void show_desk(char desk[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", desk[i][j]);
        };
        printf("\n");
    };
};

bool winner(char desk[3][3]) {
    return false;
};
