#include <stdio.h>
#include <stdlib.h>

int my_pointers() {
    printf("define pointers :\n");

    /* number -> got memory address that hold 99 in there
     * declare pointer on int number , pointer have to be allocated to memory or NULL
     * */
    int number = 99;
    int *pnumber = &number;

    /* get the data from pointer */
    printf("\ndata that pointer points *name : %d\n", *pnumber);


    return 0;
}