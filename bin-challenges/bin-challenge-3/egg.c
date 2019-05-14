#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char* ptr= getenv("EGG");
  printf("EGG address --> %p\n", ptr);
  return 0;
}