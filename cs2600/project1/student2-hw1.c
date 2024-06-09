#include <stdio.h>
#include <errno.h>

// This function counts the total number of characters in a file
long count_characters(FILE *);

void main() {
    int j;
    long cnt;
    char ch1, ch2;
    FILE *fp1, *fp2;

    if (fp1 = fopen("File_1.txt", "r")) {
        printf("The FILE has been opened...\n");
        fp2 = fopen("File_2.txt", "w");
        cnt = count_characters(fp1);

        /*
            Makes the pointer fp1 to point at the
            last character of a file
        */
        fseek(fp1, -1L, 2);
        printf("Number of characters to be copied %d\n", ftell(fp1));

        while (cnt) {
            ch1 = fgetc(fp1);
            fputc(ch1, fp2);
            fseek(fp1, -2L, 1); // shifts the pointer to the previous character
            cnt--;
        }
        printf("\n**File copied successfully in reverse order**\n");
    } else {
        perror("Error occured\n");
    }
    fclose(fp1);
    fclose(fp2);
}

/*
    Count the total number of characters in the file
    that *f points to
*/
long count_characters(FILE *f) {
    fseek(f, -1L, 2);
    /*
        returns the position of the
        last element of the file
    */
    long last_pos = ftell(f);
    last_pos++;
    return last_pos;
}
