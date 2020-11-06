#include <stdio.h>

void use_gcd();
void absolute_number();

int main() {
    // use_gcd();
    absolute_number();
    return 0;
};

// inner function
int greatest_common_deviser(int a, int b) {
    // Euclidean Algorithm
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    };

    // a = main + reminder
    int reminder = a % b;
    int main = b;
    return greatest_common_deviser(main, reminder);
};

void use_gcd() {
    int a, b;
    printf("enter two numbers the bigger then 0 to get GCD , in order (a b): ");
    scanf("%d %d", &a, &b);

    if (a > 0 && b > 0) {
        printf("\nGCD : %d\n", greatest_common_deviser(a, b));
    } else {
        printf("invalid data !\n");
    };
};

float absolute_number_util(float num) {
    // calc abs number
    float tmp = num;
    if (num < 0) {
        return tmp + ((float)(sqrt(num * num) * 2));
    } else {
        return num;
    };
};

void absolute_number() {
    // return absolute number from float
    float num;
    printf("\nenter a number : ");
    scanf("%f", &num);
    printf("\nabs of number is : %.2f\n", absolute_number_util(num));
};
