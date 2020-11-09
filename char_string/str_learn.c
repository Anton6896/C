//
// Created by anton on 09/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constant values for all use */
#define PI 3.14159f
#define my_num 56
const char msg[] = "\nsome constant message ... ";


int define_string() {
    printf("\ndefine string func :");

    /* compiler will define size for this string automatically */
    char st[] = {"\nsome auto string define"};
    printf("%s", st);

    /* using constant */
    printf("\nconstant %.2f", PI);
    printf("\nconstant %d", my_num);

    printf("%s", msg);

    char st_1[] = "my new string";
    char st_2[] = "my new string 2";

    char dest[35];
    /* ( dest , source , num of arguments for copy ) */
    strncpy(dest, st_1, strlen(st_1) + 1);
    printf("\ncopyead string : %s", dest);

    printf("\nstrlen() return long %ld", strlen(st_1));

    /* return <0 -> the str is differ , return >0 str1 differ , return 0 equality */
    printf("\nis two string are equal ? : strcmp() ->  %d", strcmp(st_1, st_2));

    /* look for the sub string strstr(), case sensitive */
    char text_1[] = {"the dogs is amazing"};
    char word_1[] = {"dogs"};
    char *p_found = NULL;
    p_found = strstr(text_1, word_1);
    printf("\nthe word that found from string '%s': '%s' ", text_1, p_found);

    /* the token idea */
    printf("\nthe idea of tokens :");
    char text_2[] = {"first line - second line - other line "};
    const char s[2] = "-";
    char *token;

    // get first token
    // python <- spit('-')
    token = strtok(text_2, s);

    // walk thru the other tokens ( it will be separated with -
    // look like the walk in linked list
    while (token != NULL) {
        printf("\n%s", token);
        token = strtok(NULL, s);
    };


    return 0;
}