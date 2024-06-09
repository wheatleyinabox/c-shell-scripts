#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, count;
    printf("Input three different integers: ");
    scanf("%d", &num1);
    count++;
    scanf("%d", &num2);
    count++;
    scanf("%d", &num3);
    count++;

    int sum = num1 + num2 + num3;
    int average = (num1+num2+num3) / count;
    int product = num1 * num2 * num3;
    
    int minimum = num1;
    if (minimum > num2)
    {
        minimum = num2;
    }
    if (minimum > num3)
    {
        minimum = num3;
    }

    printf("Sum is %d\n", sum);
    printf("Average is %d\n", average);
    printf("Product is %d\n", product);
    printf("Smallest is %d\n", minimum);
    // printf("Largest is %d\n", maximum);

    return 0;
}