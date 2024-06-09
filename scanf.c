#include <stdio.h>

int main()
{
        int testInt;
        printf("Enter an integer: ");
        // %d format string is used in case of integer
        scanf("%d", &testInt);
        printf("Number = %d", testInt);
        return 0;
}