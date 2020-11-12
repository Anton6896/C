#include <stdio.h>
// declare and use functions in C

// global var
#define PI 3.14159265359

// declare my func
void add();
float my_data();
float my_calc(float num);
void my_arr_func(float arr[]);

int main() {
    float my_list[4] = {1.0, 2.0, 3.0, 4.0};
    printf("declaring and using functions:\n");

    // use my func
    add();
    printf("this is the declared PI num : %.2f\n", my_data());
    printf("calculated PI * num : %.2f\n", my_calc(3));

    my_arr_func(my_list);
    for (int i = 0; i < 4; i++) {
        printf("multiply %d * %.2f = %.2f \n", i + 1, PI, my_list[i]);
    };
    
    return 0;
}

// implament my func
void add() {
    printf("using my func ... \n");
};

float my_data() {
    return PI;
};

float my_calc(float num) {
    return num * my_data();
}

void my_arr_func(float arr[]) {
    // multiply all values in this arr on PI
    int count = 4;
    for (int i = 0; i < count; i++) {
        arr[i] = my_calc(i);
    };
};
