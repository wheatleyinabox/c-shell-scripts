pointer: pointer_array.c
        gcc -o pointer -std=c99 -Wall -g pointer_array.c

directory: directory.c
        gcc -o directory -std=gnu99 -Wall -g directory.c

clean:
        rm directory; rm pointer;
