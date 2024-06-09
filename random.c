#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
        int random;
        
        //srand(time_now);

        random = rand();
        printf("Seed = %d, Random number 1= %d\n", time(0), random);

        // random = (rand() % 16) + 5;

        return 0;
}