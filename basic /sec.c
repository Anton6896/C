#include <stdio.h>

int main()
{
    // var
    char str[100];
    int i;

    printf("enter text:");
    scanf("%s %d", str, &i);

    printf("\n text is : %s %d \n", str, i);
    return 0;
}