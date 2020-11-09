#include <stdio.h>
#include <stdlib.h>

int my_pointers() {
    printf("define pointers :\n");

    /* number -> got memory address that hold 99 in there
     * declare pointer on int number , pointer have to be allocated to memory or NULL
     * */
    int number = 99;
    int *pnumber = &number;

    /* accsess data from pointer */
    printf("\nint number = %d", number);
    printf("\n value that hold *number : %d", *pnumber);
    // return hexadecimal address
    printf("\n *number value : %p", pnumber);
    // 8 bytes for (64 sys)
    printf("\nnumber of bytesthat that pointer use : %d", (int)sizeof(pnumber));
    printf("\n >>> *number address : %p\n", &pnumber);

    return 0;
}