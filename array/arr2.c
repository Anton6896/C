#include <stdio.h>

int main() {
    int martix[4][5] = {
        // all other will be 0
        {1, 2, 5},
        {1, 2, 3, 4},
        {2, 4, 5}};

    printf("print matrix :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d", martix[i][j]);
        };
        printf("\n");
    };

    return 0;
}