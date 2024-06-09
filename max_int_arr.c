#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, i;
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int *arr = (int*)malloc(sizeof(int) * n);

        printf("Enter elements: ");
        for (int j = 0; j < 3; j++)
        {
                scanf("%d", &arr[i]);
                if (j == 0)
                {
                        i = arr[0];
                }
                else if (temp < arr[j])
                {
                        i = arr[j]
                }
        }
        printf("The maximum number is: %d\n", i);
        free(arr);

        return 0;
}