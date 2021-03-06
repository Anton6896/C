#include <stdio.h>

// glob var 
#define MONTH 5
#define YEAR 12

int main()
{
    float tot_rain_year = 0.0f;
    float average_rain_year = 0.0f;
    float average_rain_month = 0.0f;

    float sol[MONTH][YEAR] = {
        {3.4,
         2.5,
         3.2,
         4.5,
         5.2,
         3.2,
         4.5,
         5.2,
         4.5,
         5.2,
         3.2,
         8.4},
        {
            3.2,
            4.5,
            5.2,
            4.5,
            5.2,
            4.5,
            5.2,
            3.2,
            4.5,
            5.2,
            4.5,
        },
        {
            5.2,
            4.5,
            5.2,
            4.5,
            5.2,
            3.2,
            5.2,
            4.5,
            5.2,
            3.2,
            4.5,
            5.2,
        },
        {
            2.5,
            3.2,
            4.5,
            5.2,
            3.2,
            4.5,
            4.5,
            5.2,
            3.2,
            5.2,
            4.5,
            5.2,
        },
        {
            3.2,
            4.5,
            5.2,
            4.5,
            5.2,
            5.2,
            4.5,
            5.2,
            3.2,
            5.2,
            4.5,
            3.2,
        },
    };

    printf("\ntotal rain for year :");
    for (int i = 0; i < MONTH; i++)
    {
        for (int j = 0; j < YEAR; j++)
        {
            tot_rain_year += sol[i][j];
        };
        printf("\nfor year %d was in total ( %.2f ) rain fall .", i + 1, tot_rain_year);
        printf("\nfor year %d avarage rain ( %.2f )  rain in mm  .", i + 1, (tot_rain_year / 12));
        printf("\n--------------");
        tot_rain_year = 0.0f;
    };
    printf("\n");

    printf("\ntotal rain fall monthly : ");
    for (int i = 0; i < YEAR; i++)
    {
        for (int j = 0; j < MONTH; j++)
        {
            average_rain_month += sol[j][i];
        };
        printf("\nfor month %d, was avarage rain fall ( %.2f ) in mm ", i + 1, (average_rain_month / 5));
        average_rain_month = 0.0f;
    };
    printf("\n");

    return 0;
}