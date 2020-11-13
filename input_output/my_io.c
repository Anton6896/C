//
// Created by User on 11/13/2020.
/**
 * working with files
 * https://www.programiz.com/c-programming/c-file-input-output
 *
 * */


#include <stdio.h>
#include <limits.h>
#include <string.h>

// for windows ! 
#define my_folder "D:\\Documents\\Code\\C\\basic\\input_output\\files\\"

int io_1() {


/// open and close
    // get directory
    char file_name[PATH_MAX];
    strcpy(file_name, my_folder);
    strcat(file_name, "new.txt");
    printf("path to file : %s", file_name);

    // open file
    FILE *file_ptr = NULL;
    file_ptr = fopen(file_name, "w");
    if (file_ptr == NULL) {
        printf("\nfailed to open ");
        exit(1);
    } else {
        printf("\nopen ... ok ");
    }

    // wright in
    fprintf(file_ptr, "%s\n", file_name);
    fprintf(file_ptr, "%s\n", "other line text ");

    // close the file
    fclose(file_ptr);
    printf("\nopen and wright to file complete , file closed .");
/// rename file ( must be closed )
    char new_name[PATH_MAX] = my_folder;
    strcat(new_name, "other.txt");

    if (rename(file_name, new_name)) {
        printf("\nfailed to rename !!! ");
    } else {
        printf("\nrename ... ok ");
    }
/// remove file
    remove(new_name);
    printf("\nremove ... ok ");


    return 0;
}

void io_2() {

/// fill file with text
    // for windows 
    char file_name[] = "D:\\Documents\\Code\\C\\basic\\input_output\\files\\text.txt";
    char buffer[100];

    FILE *pfile = fopen(file_name, "w");
    if (pfile == NULL) {
        printf("\nfailed to open ");
        exit(1);
    } else {
        printf("open .. ok, ");
        fprintf(pfile, "%s\n",
                "Contrary to popular belief, Lorem Ipsum is not simply random text\n"
                "It has roots in a piece of classical Latin literature from 45 BC,\n"
                "making it over 2000 years old. Richard McClintock, a Latin\n"
                "professor at Hampden-Sydney College in Virginia, looked up one of the\n"
                "more obscure Latin words, consectetur, from a Lorem Ipsum");
    }
    printf("wright in .. ok, ");
    fclose(pfile);
    printf("close .. ok.\n");

/// read text form file
    FILE *file_ptr = NULL;
    int c, counter = 0;

    file_ptr = fopen(file_name, "r");

    if (file_ptr != NULL) {
        printf("\nstart read :\n");

        // read char
//        while ((c = fgetc(file_ptr)) != EOF) {
//            ++counter;
//            printf("%c", c);
//        }

        // read string , this is more efficient from fgetc
        while (fgets(buffer, 100, file_ptr) != NULL){
            printf("%s", buffer);
        }

        // close
        fclose(file_ptr);
        printf("\nend reading total %i chars, file close .. ok", counter);
    } else {
        printf("\nproblem !!");
        exit(1);
    }

    remove(file_name);
    printf("\nremove .. ok");

}

void io_main() {
    printf("from io main :\n");

    io_2();
}