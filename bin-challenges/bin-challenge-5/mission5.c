#include <stdio.h>
#include <stdlib.h>

char flag[1024];

void main(void){
  FILE *flag_fp;
  int compare_result;
  int i;
  char *ptr;
  char input_buffer [11];
  char *flag_not_found;
  ptr = input_buffer;
  
  for(i = 0xe; i != 0; i--, ptr += 4)
      *ptr = 0;


  flag_fp = fopen("./flag","rb");
  if (flag_fp == (FILE *)0x0) {
    puts("[!] Flag not found!");
    exit(-1);
  }
  fread(flag,0x400,1,flag_fp);

  puts("Guess the flag!");
  gets(input_buffer);
  
  compare_result = strncmp(input_buffer,flag,0x400);
  if (compare_result == 0) {
    printf("Great Job!\n Here is the flag %s\n",flag);
  }
  else {
    printf(" %s\n",
           "[!] Wrong! You should really make better guesses. This one was really poor. I bet youcan do better. Try againg."
          );
  }

  exit(0);
}