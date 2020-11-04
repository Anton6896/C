#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // guess the number
    printf("guess the number only numbers the 0<num ! (-1 for exit)\n");
    int guess_me = rand();
    int my_guess;
    int count = 0;
    bool in_game = true;
    // srand((unsigned)time(&guess_me));

    do {
        printf("enter number or -1 : ");
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
            printf(" your guess is bigger \n");
        } else if (my_guess < guess_me) {
            printf(" your guess is lower \n");
        }
    } while (in_game);
    return 0;
}
