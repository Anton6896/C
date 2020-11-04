#include <stdio.h>
// find all prime num from 1 to 100

int main() {
    int count = 100;
    int position = 3;
    int arr[100] = {1, 2, 3};

    for (int i = 5; i < count; i++) {
        int k = -1;
        for (int j = i; j > 0; j--) {
            k = i % j;
            if (k == 0) {
                break;
            };
        };

        if (k != 0) {
            arr[position] = i;
            position++;
        };
    };

    for (int i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}