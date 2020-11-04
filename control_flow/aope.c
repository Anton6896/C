#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// guess the number game
int main() {
    printf("guess the number only numbers the 0<num ! (-1 for exit)\n");

    int guess_me;
    int my_guess;
    int count = 0;
    bool in_game = true;

    // get random num between 0 - 20
    time_t t;
    srand((unsigned)time(&t));
    guess_me = rand() % 21;
    // printf("num to guess : %d\n", guess_me);

    do {
        printf("\nenter number or -1 : ");
        scanf("%d", &my_guess);
        printf("\n");
        count++;

        if (my_guess == guess_me) {
            printf("great job your guess it , num is %i , you try %i rimes. \n", guess_me, count);
            in_game = false;
        } else if (my_guess == -1) {
            printf(" tnx for the game .\n ");
            in_game = false;
        } else if (my_guess > guess_me) {
            printf(" your guess is bigger");
        } else if (my_guess < guess_me) {
            printf(" your guess is lower");
        }
    } while (in_game);
    return 0;
}
