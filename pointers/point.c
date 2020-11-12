#include <stdio.h>
#include <stdlib.h>


int my_pointers() {
    printf("define pointers :\n");

    /* number -> got memory address that hold 99 in there
     * declare pointer on int number , pointer have to be allocated to memory or NULL
     * */
    int number = 99;
    int *pnumber = NULL;

    printf("\nnumber address > %p", &number);
    printf("\nnumber value %d\n", number);

    pnumber = &number; // store the address of num in pnumber
    printf("\npnumber address > %p", &pnumber); // address of it self
    printf("\nsize of the pointer > %d", (int) sizeof(pnumber)); // size
    printf("\npnumber value > %p", pnumber); // address of number
    printf("\n*pnumber data poindet to  > %d \n", *pnumber); // value that point to
    /* pointer holds address of int number */


    return 0;
}

int exe_1() {
    printf("\nbasic exercise : \n");
    int value = 10;
    int *pvalue = &value;


    printf("\npointer address : %p", &pvalue);
    printf("\naddress of value : %p", &value);
    printf("\nvalue of the pointer  : %p", pvalue);
    printf("\nis address of the value and pointer value same ? : %s",
           ((&value == pvalue) == 1 ? "True" : "False"));
    printf("\nvalue that the pointer is point to : %d", *pvalue);

    return 0;
}

/**constant pointers*/
int constant_p() {
    long num = 7l;
    printf("\nnum is : %lu", num);
    const long *pnum = &num;
    /* cant assign thru hte pointer but can do thru the num !!! */
//    *pnum += 5l; // error: read-only variable is not assignable
    num += 3l;
    printf("\nnum is : %lu", num);
    printf("\npointer point to value : %lu", *pnum);

    /* and you do can change the pointer value it self to point to other location  */
    long num_2 = 56l;
    pnum = &num_2;
    printf("\npointer point to other value now : %lu", *pnum);
    /* but you cannot change the value thru hte pointer it self because of const ! */

    // ensure that the pointer have immutable address
    long *const pnum_2 = &num;
//    pnum_2 = &num; // error: cannot assign to variable 'pnum_2' with const-qualified type 'long *const'
    *pnum_2 = 65l; // this ok
    printf("\npointer point to other value now : %lu", *pnum_2);

    return 0;
}


/** void pointer */
int void_p() {
    printf("void pointers : ");
    /* the beauty is that you can get any type in
     * but after you need to cast is to type that was specified (decode it )
     * */

    // variable
    int n = 10;
    float fl = 4.45;
    char ch = 'k';

    // pointer
    void *vptr;

    // using
    vptr = &n;
    printf("\nint value \t\t: %d", *(int *) vptr);

    vptr = &fl;
    printf("\nfloat value \t: %.2f", *(float *) vptr);

    vptr = &ch;
    printf("\nchar value \t\t:'%c' ", *(char *) vptr);


    printf("\n");
    return 0;
}

// pointer function
int arrSum(int arr[], const int n) {
    // n size of array
    int sum = 0, *ptr;

    // arr (is address) + n (amount in array)
    for (ptr = arr; ptr < (arr + n); ++ptr) {
        sum += *ptr;
    }

    printf("\nsum all values from array using pointer : %i", sum);
    return 0;
}

int arrSum_p(int *arr, const int n) {
    // (address)arr_end + (int)n
    int sum = 0, *const arr_end = arr + n;
    for (; arr < arr_end; ++arr) {
        sum += *arr;
    }
    printf("\nsame func with other value as pointers : %i", sum);
    return 0;
}

int array_p() {
    printf("array and pointers : \n");
    int values[100] = {11, 12, 13, 14, 15, 16, 17, 2}; // sum = 100


    /**
     * will point to first element in array
     * can do like that because the array is pointer by it self
     * all arrays is pointers (sting is array)
     * */
    int *pvalues;
    pvalues = values; // <-> pvalues = values[0];  (same thing)
    // same address
    printf("\npointer value  : %p", pvalues);
    printf("\nvalues address : %p", &values);
    printf("\npointer value  : %d", *pvalues);

    /**
     * array is a closest chunk of addresses that can be reached thru the pointer
     * pvalues = values;
     * *(pvalues + 1) -> get data from :  pvalue + 1 = values[1]
     *
     */
    // access data tru the array in array
    printf("\nget second element from array : %d", *(pvalues + 1));  // 12

    // 400 / 4 = 100  ( sizeof(values[0]) = 4kb )
    int count = (int) (sizeof(values) / sizeof(values[0])); // 100
    arrSum(values, count);
    arrSum_p(values, count);


    return 0;
}

/**string and pointers*/
void copyString(char a[], char b[]) {
    int i = 0; // outside loop for outer use
    for (; b[i] != '\0'; ++i) {
        a[i] = b[i];
    }
    a[i] = '\0';
}

void copyString_p(char *to, char *from) {
    for (; *from != '\0'; ++from, ++to) {
        // assignment not working ?!
        *to = *from;
    }
    *to = '\0';
}

void copyString_p2(char *to, char *from) {
    while (*from) {
        *to++ = *from++;
    }
    *to = '\0';
}

int string_p() {
    printf("string and pointer :\n");
    char b[] = "123456789";

    char a[10];
    copyString(a, b);
    printf("\ncopyString    : %s", a);

    char c[10];
    copyString_p(c, b);
    printf("\ncopyString_p  : %s", c);

    char e[10];
    copyString_p2(e, b);
    printf("\ncopyString_p2 : %s", e);


    return 0;
};

// pointer arithmetics exercise 1
int exer_util1(const char *a) {
    const char *end = a;
    while (*end) {
        end++; // get to the end position
    }
    return (int) (end - a);
}

void exer_test1() {
    printf("\nexercise 1 testing : %d", exer_util1("12345"));
    printf("\nexercise 1 testing : %d", exer_util1(""));
    printf("\nexercise 1 testing : %d", exer_util1("12"));
}


/**pass by value and pass by reference , argument to function*/
int swap_by_value(int a, int b) {
    // the arguments is passed by value ,
    // the just copy of real for the function inside of it
    int tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int swap_by_reference(int *a, int *b) {
    // change the data thru the pointer
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return 0;
}

int pass_by() {

    // here is using the pointer as param in functions
    // like that you can modify data outside the function

    int a = 100, b = 200;
    printf("\nbefore swap a = 100 : %s", (a == 100 ? "true" : "false"));
    swap_by_value(a, b);
    printf("\nafter swap_by_value a = 100 : %s", (a == 100 ? "true" : "false"));
    swap_by_reference(&a, &b); // must assign address
    printf("\nafter swap_by_reference a = 100 : %s -> %d", (a == 100 ? "true" : "false"), a);

    /**
     * now you understand why to put constant in argument with pointers
     * int do_some(const char* mess){}   <- here you won't change the mess that was pass thru the pointer !
     *
     * */

}

int exer_2_util(int *num) {
    *num = *num * *num;
    return *num;
}

int exe_2_test() {
    int n1 = 3, n2 = 4;

    printf("\nqsr %i", exer_2_util(&n1));
    printf("\nqsr %i", exer_2_util(&n2));

}

/**Dynamic memory allocation nad memory control */
int memory_my(){


    return 0;
}


int my_main() {
//    string_p();
//    exer_test1();
//    pass_by();
//    exe_2_test();
    array_p();
//    memory_my();
    return 0;
}