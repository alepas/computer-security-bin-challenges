#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char KEY[] = "BLOCKCHAIN";

/*This code is exactely the same of code-challenge.c in order to obtain a memory
structured in the same way of it. In this way, by using a printf, it is possible
to retieve the correct buffer address.
This retrieved address will be used into the shellcode.
*/
void vuln(){
    int i;
    char buffer[804];

    printf("buffer address --> %p\n", buffer);
    fread(buffer, 1, 4 * 1024, stdin);

    for (i = 0; i < 804; i++) {
      buffer[i] ^= KEY[i % sizeof(KEY)];
    }
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]){
    vuln();
    exit(0);
}