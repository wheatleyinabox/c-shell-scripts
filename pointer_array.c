#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a[9] = {1, 5, 6, 11, 12, 5, 2, 13, 31};
        int *p = a;

        for (int i = 0; i < 9; i += 2)
        {
                printf("%d\n", *(p + i));
        }

        return 0;
}