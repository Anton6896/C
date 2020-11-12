//
// Created by anton on 09/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

    printf("\nstrlen() return long %llu", strlen(st_1));

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


    // func to count the string leters etc
    char text_3[] = {"social purposes. Governmental and non-governmental , organizations"
                     "use text messaging for communication: between colleagues. In the 2010s"};
    int n_letters = 0;
    int n_digets = 0;
    int n_punct = 0;
    int i = 0;

    printf("\ncount the number of (l d p) :");
    while (text_3[i]) {
        if (isalpha(text_3[i])) {
            ++n_letters;
        } else if (isdigit(text_3[i])) {
            ++n_digets;
        } else if (ispunct(text_3[i])) {
            ++n_punct;
        };
        ++i;
    };
    printf("\nletters : %d\ndigits : %d\npunct : %d", n_letters, n_digets, n_punct);



    /* converting strings func */
    char text_4[] = {"\nthis text is was in lower  123 case letters !"};
    for (int j = 0; (text_4[j] = (char) toupper(text_4[j])) != '\0'; ++j);

    printf("%s", text_4);

    // text to int ( atoi(), atol(), atoll(), atof() ) <> itoa()
    char number[] = "345.5";
    double num = atof(number);
    printf("\nconverted number : %.2f", num);


    return 0;
};


int my_char_counter(char text[]) {
    // return number of letters in the string
    int counter = 0;
    int nlet = 0;
    int ndig = 0;
    int npunc = 0;

    while (text[counter] != '\0') {
        if (isalpha(text[counter])) {
            ++nlet;
        } else if (isdigit(text[counter])) {
            ++ndig;
        } else if (ispunct(text[counter])) {
            ++npunc;
        };
        ++counter;
    };
    printf("\nletters : %d\ndigits : %d\npunct : %d", nlet, ndig, npunc);
    return counter;
};


const char *my_concat(char str1[], char str2[]) {
    return strcat(str1, str2);
};

bool my_compare(char str1[], char str2[]) {
    return strcmp(str1, str2) == 0 ? true : false;
}
