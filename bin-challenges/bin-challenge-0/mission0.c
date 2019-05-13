#include <stdio.h>
#include <string.h>


int vuln(char* str){

        char buf[856];

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
