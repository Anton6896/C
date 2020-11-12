//
// Created by Anton on 11/12/20.
//

/**
 * create and use structures ( like array )
 * is an class without methods ( same as class behavior +- )
 * point is to group related variables together
 *
 * can declare array of structures !
 * struct date myDates[10];
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct date {
    int day;
    int month;
};

struct time {
    int hours;
    int minutes;
};

struct person {
    char name[20];
    int age;
    char place[30];
    char add[30];
};

struct person_1 {
    char name[20];
    struct date birthday;
    struct living {
        char city[20];
        char street[20];
        // etc
    } place;
};

struct person_2 {
    char *name;
    int *age;
};

struct namect {
    char *fname;
    char *lname;
    int letters;
};

void get_info(struct namect *pst);


void cus() {
    /// array :
    struct date my_dates[10];

    my_dates[2].month = 2;
    my_dates[2].day = 1;

    my_dates[1] = (struct date) {1, 3};

    struct date other_date[3] = {
            {1, 2},
            {3, 6}
    };


    struct date today;
    today.day = 1;
    today.month = 11;
    printf("today day %i, month %i", today.day + 11, today.month);

    struct date other_day = {7, 3};

    // after you have struct initialized you can reassign values
    today = (struct date) {2, 4};


    struct person p1;
    p1 = (struct person) {
            "name1", 34, "new place", "addi info"
    };
    printf("\nnew person %s, %i years old at %s, thet %s", p1.name, p1.age, p1.place, p1.add);


    /// nested struct object
    struct date_adn_time {
        struct date date;
        struct time time;
    };

    struct date_adn_time dat;
    dat = (struct date_adn_time) {
            .date.day = 1,
            .date.month = 2,
            .time.hours = 12,
            .time.minutes = 34
    };

    printf("\nget data from the nested: %i minutes ", dat.time.minutes);

    struct date_adn_time dat_2 = {
            {1, 4},
            {3, 45}
    };

    struct person_1 p2 = {
            .name = "mikle",
            .birthday.day = 23,
            .birthday.month = 4,
            .place.city = "my city",
            .place.street = "my street"
    };


    /// pointer in struct
    struct date *date_ptr = NULL;
    struct person_1 *p3_ptr = NULL;
    p3_ptr = &p2;
    date_ptr = &today;
    // must put (*arg).  for getting right data
    // new syntax  pointer -> data in it
    printf("\nprint from pointer : %i", date_ptr->day);
    printf("\nperson_1 p2 var '%s' ", p3_ptr->place.street);


    /// struct with 2 pointers doesn't have an memory space  ( working with memory )
    // crete place
    struct person_2 my_p2;
    // alocate memmory
    my_p2.name = (char *) calloc(25, sizeof(char));
    my_p2.age = (int *) calloc(5, sizeof(int));
    //fill with data
    if (my_p2.name && my_p2.age) {
        strcpy(my_p2.name, "person_2");
        *my_p2.age = 43;
        // use
        printf("\nname: %s, age: %i\n", my_p2.name, *my_p2.age);
    } else {
        printf("\nmem problem ----------+++++++------  ");
    }

    // free memory
    free(my_p2.name);
    free(my_p2.age);
    my_p2.name = NULL;
    my_p2.age = NULL;


    /// passing struct to method
    struct namect one;
    get_info(&one);
}

void get_info(struct namect *pst) {

    char temp[50];

    printf("first name : ");
    scanf(" %[^\n]", temp);
    pst->fname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);

    printf("last name : ");
    scanf(" %[^\n]", temp);
    int ln = (int) strlen(temp);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);

    printf("fname: %s, lname: %s", pst->fname, pst->lname);

    free(pst->fname);
    free(pst->lname);

}

void main_strunc() {
    printf("main struct : \n");
    cus();
}