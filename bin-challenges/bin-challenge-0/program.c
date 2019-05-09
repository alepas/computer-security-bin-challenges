#include <stdio.h>
#include <string.h>

/*This code is exactely the same of mission0.c in order to obtain a memory
structured in the same way of it. In this way, by using a printf, it is possible
to retieve the correct buffer address.
This retrieved address will be used into the shellcode.
*/
int vuln(char* str){

        char buf[856];

	printf("buffer address -> %p\n", buf);
        strcpy(buf, str);
        return 0;
}

int main(int argc, char **argv){
        if (argc < 2){
                printf("missing parameters...");
                return -1;
        }
        vuln(argv[1]);
        return 0;       
}