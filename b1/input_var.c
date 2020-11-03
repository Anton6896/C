#include <stdio.h>

int main(int argc, char *argv[])
{
    // int numberOfArguments = argc;
    // char *argument1 = argv[0];
    // char *argument2 = argv[1];
    // printf("number of argument %d \n ", numberOfArguments);
    // printf("arg 1 is prog name %s \n ", argument1);
    // printf("arg 2 is comand line argument %s \n ", argument2);

    // printf("tot argc %d : \n", argc);
    // for (int a = 0; a < argc; a++)
    // {
    //     printf("argv[%02d]: %s\n", a, argv[a]);
    // }

    // double height, width, area, perimeter;

    // printf("enter the Width and height of rectangle : ");
    // scanf("%lf %lf", &width, &height);

    // atoi() convert str->int
    // double height = atoi(argv[1]);
    // double width = atoi(argv[2]);
    // double area, perimeter;

    // area = width * height;
    // perimeter = 2 * (height + width);
    // printf("area : %.3g \n", area);
    // printf("perimeter : %.3g\n", perimeter);

    enum company
    {
        google,
        facebook,
        xerox,
        yahoo,
        ebay,
        microsoft
    };
    enum company comp1, comp2, comp3;
    comp1 = xerox;
    comp2 = google;
    comp3 = ebay;

    printf("%d\n", comp1);
    printf("%d\n", comp2);
    printf("%d\n", comp3);

    return 0;
}