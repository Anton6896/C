#include <stdio.h>

int main() {
    int grades[4];
    // (int)(sizeof(grades) / sizeof(grades[0]))  <- return sizeof array as int
    int count = (int)(sizeof(grades) / sizeof(grades[0]));
    long sum = 0;
    float average = 0.0f;

    for (int i = 0; i < count; i++) {
        printf("\n%2u>", i + 1);
        scanf("%d", &grades[i]);
        sum += grades[i];
    }
    printf("\navarage : %.2f \n", (float)(sum / count));

    return 0;
}