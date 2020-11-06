#include <stdbool.h>
#include <stdio.h>

#define count 3

void show_desk(char desk[3][3]);
bool winner(int a, int b, char desk[3][3]);
bool can_move(int a, int b, char desk[3][3]);
int make_move(char inner_circleer[50], char sine, char desk[3][3], bool out_circle, bool inner_circle);

int main()
{
    char p1_sine = 'x';
    char p2_sine = 'o';
    char p1_name[50];
    char p2_name[50];
    bool out_circle = true;   // bool game flag
    bool inner_circle = true; // start the game sequence ( -1 for exit )

    // main base desk
    char desk[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'},
    };

    while (out_circle)
    {
        // create and initiate empty board
        char board[3][3];
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                board[i][j] = desk[i][j];
            };
        };

        // get inner_circleer names
        printf("hello and wellcome to the game tic-toc please use 1-9 keys\n \
        as at right side of your key board , enjoy");
        printf("\nplease enter the inner_circleer 1 name he is using the 'X' sine : ");
        scanf("%s", p1_name);
        printf("\nplease enter the inner_circleer 2 name he is using the 'O' sine : ");
        scanf("%s", p2_name);

        while (inner_circle)
        {

            // show board
            show_desk(board);

            // inner_circleer 1 move
            make_move(p1_name, p1_sine, board, out_circle, inner_circle);
            // inner_circleer 2 move
            make_move(p2_name, p2_sine, board, out_circle, inner_circle);
        };
    };
    printf("\nTnx for game .\n");
    return 0;
};

void show_desk(char desk[3][3])
{
    printf("\n\n\n");
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            printf("%c ", desk[i][j]);
        };
        printf("\n");
    };
};

bool winner(int a, int b, char desk[3][3])
{
    return false;
};

bool can_move(int a, int b, char desk[3][3])
{
    if (desk[a][b] == '.')
    {
        return true;
    };
    return false;
};

int make_move(char inner_circleer[50], char sine, char desk[3][3], bool out_circle, bool inner_circle)
{
    int move = 0;
    bool now_moving = true;

    do
    {
        do // get inner_circleer move
        {

            printf("%s please enter your move : ", inner_circleer);
            scanf("%d", &move);


        } while ((move < 1 || move > 9) && move != -1);

        // convert move to desk and check if availble
        switch (move)
        {
        case -1:
            // exit from all loops and finish the game
            now_moving = false;
            out_circle = false;
            inner_circle = false;
            break;
            
        case 1:
            if (can_move(2, 0, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[2][0] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;
        case 2:
            if (can_move(2, 1, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[2][1] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;
        case 3:
            if (can_move(2, 2, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[2][2] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;

        case 4:
            if (can_move(1, 0, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[1][0] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;
        case 5:
            if (can_move(1, 1, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[1][1] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;
        case 6:
            if (can_move(1, 2, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[1][2] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;

        case 7:
            if (can_move(0, 0, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[0][0] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;
        case 8:
            if (can_move(0, 1, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[0][1] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;
        case 9:
            if (can_move(0, 2, desk))
            {
                now_moving = 0; // move is legal finish move
                desk[0][2] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again");
            };
            break;

        default:
            break;
        }

    } while (now_moving);

    return 0;
};
