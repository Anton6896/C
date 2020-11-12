//
// Created by User on 11/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** malloc , calloc, realloc
 *
 * malloc return void pointer so you need to cast it for your need !
 * always close/free up the space by   >>> free(name)
 *
 *
 * */

int mem() {
    printf("memory lesson :\n");

    // allocate memory for 25 ints
    int *p_num = (int *) malloc(25 * sizeof(int));
    printf("malloc start : %p\n", p_num);

    if (!p_num) {
        // do some for memory allocate failure ...
    }

    /** releasing memory when you done (always release memory if you allocated !)*/
    free(p_num);
    p_num = NULL;

    // calloc -> same as malloc but he will initialize data straight forward !
    int *p_num_2 = (int *) calloc(25, sizeof(int)); // auto init to 0


    /**
     * realloc allows to change the mem size of alloc or calloc ! with it you can reallocate mem size !
     * in other words he allow to make dynamic memory size
     * extend the new memory
     * */
    p_num_2 = (int *) realloc(p_num_2, 75);  // return void pointer
    free(p_num_2); // free mem
    p_num = NULL;




    // example :  create string obj small and then extend it !
    char *p_str = NULL;
    p_str = (char *) calloc(15, sizeof(char));
    strcpy(p_str, "text new");  // #include <string.h>
    printf("\nString: %s, address: \t%p", p_str, p_str);

    // reallocate mem  / extend for more mem
    p_str = (char *) realloc(p_str, 25);
    strcat(p_str, ".com");
    printf("\nString: %s, address: \t%p", p_str, p_str);

    // free mem !!!
    free(p_str);
    p_str = NULL;


    return 0;
}