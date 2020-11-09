//
// Created by anton on 09/11/2020.
//


#include "char_string/str_learn.c"


int main() {
//    define_string();

    char text_string[] = {
            "he C library function double strtod(const char *str, char **endptr)"
            " converts the string pointed to by the argument str to a floating-poi"};
    char hello[] = "hello";
    char world[] = " world";
    printf("\ncounter is : %d", my_char_counter(text_string));
    printf("\nconcat 2 chars : %s", my_concat(hello, world));

    char w1[] = "abc";
    char w2[] = "abcs";
    printf("\nis they same ? : %d", my_compare(w1, w2));


    return 0;
};