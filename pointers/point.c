#include <stdio.h>

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