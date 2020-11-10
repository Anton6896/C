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

int pointer_and_constant() {
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

int poiner_to_void() {
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



