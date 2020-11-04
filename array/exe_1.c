#include <stdio.h>
// find all prime num from 1 to 100

int main() {
    int count = 100;
    int position = 0;
    int arr[100];

    for (int i = 3; i < count; i++) {

        

        if (i > 2 ) {
            arr[position] = i;
            position++;
        };
    };

    return 0;
}