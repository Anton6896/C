#include <stdio.h>
// find all prime num from 1 to 100

int main() {
    int count = 100;
    int position = 2;
    int arr[30] = {2, 3};

    // skip all even num
    for (int i = 5; i < count; i += 2) {
        // check if prime
        int k = 1;
        for (int j = i - 1; j > 1; j--) {
            k = i % j;
            if (k == 0) {  // found not a prime
                break;
            };
        };

        // add prime to arr ( k = 0 = false)
        if (k) {
            arr[position] = i;
            position++;
        };
    };

    for (int i = 0; i < 30; i++) {
        printf("%d,", arr[i]);
    }
    printf("\n");

    return 0;
}