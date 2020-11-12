#include <math.h>
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
    // link to algorithm
    // http://www.math.com/school/subject1/lessons/S1U1L9DP.html

    int bottom_index = 0;
    int over = 0;

    while (over < num) {
        // return upper edge
        bottom_index++;
        over = bottom_index * bottom_index;
    };
    // -1 for lower edge (lower minimum root)
    bottom_index = bottom_index - 1;

    // for more accurate calculation make this step couple times
    float result = ((num / bottom_index) + bottom_index) / 2;
    result = ((num / result) + result) / 2;

    return result;
};

void get_sqrt() {
    float num;
    printf("\nenter a number : ");
    scanf("%f", &num);

    if (num < 0) {
        printf("*** used abs func \n");
        num = absolute_number_util(num);
    };

    printf("sqrt of %.2f is : %.2f\n", num, get_sqrt_util(num));
};