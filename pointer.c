#include <stdio.h>
#include <stdlib.h>

int main()
{
        int *f = (int*) malloc(sizeof(int));
        int *s = (int*) malloc(sizeof(int));
        int *t = (int*) malloc(sizeof(int));
        printf("Enter 2 numbers: ");
        scanf("%d %d", f, s);

        // * - dereferences value and gets pointer value (ONLY FOR POINTERS)
        // & - everything else uses this
        printf("%d\n", *f);
        printf("%d\n", *s);
        printf("\n");

        t = f;
        f = s;
        s = t;

        printf("%d\n", *f);
        printf("%d\n", *s);

        return 0;
}