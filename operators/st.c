#include <stdio.h>
#include <stdbool.h>

int main()
{
    // display byte size of int
    int b_int = sizeof(1);
    int b_char = sizeof('r');
    int b_long = sizeof((long)4);
    int b_double = sizeof((double)4);
    int b_long_long = sizeof((long long)4);
    int b_long_double = sizeof((long double)4);

    printf("bite size of int : %d\n", b_int);
    printf("bite size of b_char : %d\n", b_char);
    printf("bite size of b_long : %d\n", b_long);
    printf("bite size of b_double : %d\n", b_double);
    printf("bite size of b_long_long : %d\n", b_long_long);
    printf("bite size of b_long_double : %d\n", b_long_double);

    return 0;
}