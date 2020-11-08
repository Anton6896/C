#include <stdbool.h>
#include <stdio.h>

#define count 3

void show_desk(char desk[3][3]);
bool winner(int a, int b, char desk[3][3]);
bool can_move(int a, int b, char desk[3][3]);
int make_move(char inner_circleer[50], char sine, char desk[3][3], bool a, bool b);
void exit_game(bool a, bool b);

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
        printf("\nhello and wellcome to the game tic-toc please use 1-9 keys as at right side of your key board , enjoy\n\n");

        printf("\nplease enter the 1 name he is using the 'X' sine : ");
        scanf("%s", p1_name);

        printf("\nplease enter the 2 name he is using the 'O' sine : ");
        scanf("%s", p2_name);

        // show board
        show_desk(board);

        while (inner_circle)
        {
            make_move(p1_name, p1_sine, board, out_circle, inner_circle);
            make_move(p2_name, p2_sine, board, out_circle, inner_circle);
        };
    };
    printf("\nTnx for game .\n");
    return 0;
};

void exit_game(bool a, bool b)
{
    a = false;
    b = false;
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
    // todo winner check
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

int make_move(char inner_circleer[50], char sine, char desk[3][3], bool a, bool b)
{
    int move = 0;
    bool turn_loop = true;

    do
    {
        do // get inner_circleer move
        {
            if (move == -1)
            {
                a = false;
                b = false;
                turn_loop = false;
                printf(" a b set to false ! ");
                break;
            };
            printf("%s please enter your move : ", inner_circleer);
            scanf("%d", &move);

        } while (move < 1 || move > 9);

        // convert move to desk and check if availble
        switch (move)
        {
        case 1:
            if (can_move(2, 0, desk))
            {
                turn_loop = false;
                desk[2][0] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again\n");
            };
            break;
        case 2:
            if (can_move(2, 1, desk))
            {
                turn_loop = false;
                desk[2][1] = sine;
                show_desk(desk);
                // check for win
            }
            else
            {
                printf("you cant go ther sorry ! try again\n");
            };
            break;
        case 3:
            if (can_move(2, 2, desk))
            {
                turn_loop = false;
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
                turn_loop = false;
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
                turn_loop = false;
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
                turn_loop = false;
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
                turn_loop = false;
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
                turn_loop = false;
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
                turn_loop = false;
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

    } while (turn_loop);

    return 0;
};
