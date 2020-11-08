//
// Created by anton on 03/11/2020.
//

#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = false;
    int minutes = 0;
    int hours = 0;
    int days = 0;
    int years = 0;

    printf(" enter the amount of minutes to convert them to days and years : ");
    scanf("%i", &minutes);

    if (minutes >= 60)
    {
        hours = minutes / 60;
        minutes = minutes % 60;
        if (hours >= 24)
        {
            days = hours / 24;
            hours = hours % 24;
            if (days >= 365)
            {
                years = 365 / days;
                days = days % 365;
            }
        }
    }

    printf("\nyears: %d, days: %d, hours: %d, minutes: %d\n", years, days, hours, minutes);

    //  *a pointer to a
    // (if condition) ? (then x) : (else Y)  <- ternary operator

    return 0;
};