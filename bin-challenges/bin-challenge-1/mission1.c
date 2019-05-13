#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char KEY[] = "BLOCKCHAIN";

void vuln(){
    int i;
    char buffer[256];

    fread(buffer, 1, 4 * 1024, stdin);

    for (i = 0; i < 256; i++) {
      buffer[i] ^= KEY[i % sizeof(KEY)];
    }
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]){
    vuln();
    exit(0);
}