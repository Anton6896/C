#include <stdio.h>
// #include <stdbool.h>

int main() {
    int a = 3;
    int b = 5;
    // ternary opr
    int c = 3 < 5 ? 1 : 0;
    printf("is 3 < 5 : %d\n", c);


    int ex = 2;
    switch (ex) {
        case /* constant-expression */ 1:
            /* code */
            printf(" not true \n");
            break;
        case 2:
            printf("switch: yes \n");
            break;
        default:
            break;
    }

    return 0;
}