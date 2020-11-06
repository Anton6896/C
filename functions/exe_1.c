#include <stdio.h>
#include <stdlib.h>

void use_gcd();
void absolute_number();
void get_sqrt();

int main() {
    // use_gcd();
    // absolute_number();
    get_sqrt();
    return 0;
};

// inner function
int gcd_util(int a, int b) {
    // Euclidean Algorithm
    if (a == 0) {
        return b;
    } else if (b == 0) {
        return a;
    };

    // a = main + reminder
    int reminder = a % b;
    int main = b;
    return gcd_util(main, reminder);
};

void use_gcd() {
    int a, b;
    printf("enter two numbers the bigger then 0 to get GCD , in order (a b): ");
    scanf("%d %d", &a, &b);

    if (a > 0 && b > 0) {
        printf("\nGCD : %d\n", gcd_util(a, b));
    } else {
        printf("invalid data !\n");
    };
};

float absolute_number_util(float num) {
    // calc abs number
    if (num < 0) {
        return num + ((float)(sqrt(num * num) * 2));
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

float get_sqrt_util(float num) {
    // jet two closest sqrt from the target number
    float close_from_top = num - 1;
    float close_from_button = num + 1;

    for (float i = 2, j = num; i < num; i++, j--) {
        while (close_from_top < num) {
            close_from_top = i * i;
        };
        while (close_from_button > num) {
            close_from_button = j * j;
        };
    };
    printf("bottom %f , top %f", close_from_button, close_from_top);

    return 0.0f;
};

void get_sqrt() {
    float num;
    printf("\nenter a number : ");
    scanf("%f", &num);
    
    printf("\nsqrt of %.2f is : %.2f", num, get_sqrt_util(num));
};