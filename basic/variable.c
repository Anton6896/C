#include <stdio.h>
#include <stdbool.h>

int main()
{
    // =====================  variables
    int numint = 3;
    float numfloat = 33.4;
    double numdouble = 44.4;
    // char is 'g'  not ("g"=string)  !
    char ch = 'f';
    char mystr[10] = "test";

    // must includ stdbool.h
    bool mybool = false;

    // short, long is also memory space declaration like (short num = 00.3)

    /* 
    Enum is your type that you can specify what is in it , 
    like you can specify the color types ( red, clue , white ) only ! 
     */
    enum primaryColor
    {
        red,
        yellow,
        //  can explicit set as 10
        blue = 10
    };
    enum primaryColor myColor1, myColor2;

    // myColor2  = green; can't use this !
    myColor1 = blue;

    // this will give number as position in the list or explicit
    printf("enum position %d  \n", myColor1);

    // ===================  format specifirs

    printf("integer     = %i \n", numint);
    printf("double      = %.3g \n", numdouble);
    printf("double      = %.3e \n", numdouble);
    // %.2f for 2 decimal points
    printf("float       = %.2f \n", numfloat);
    printf("bool        = %i \n", mybool);
    printf("char        = %c \n", ch);
    printf("string      = %s \n", mystr);

    return 0;
}
