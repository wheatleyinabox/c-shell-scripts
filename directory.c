#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
        const char* path = "/user/vdeleon";
        DIR* directory = opendir(path);

        if (!directory)
        {
                // do something
                printf("ERROR: Directory doesn't exist!");
                return 1; // terminates program

                // return errno;
        }

        struct dirent* file;

        while((file = readdir(directory)) != NULL)
        {
                // print entry's name and type
                printf("%\ns", file->d_name);
                printf("%d\n", file->d_type);
        }

        if (file->d_type == DT_REG)
        {
                // we want to do something for regular files
        }

        closedir(directory);

        return 0;
}