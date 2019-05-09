#!/bin/bash

cd writable/
nano program.c

#Into the nano write the code into program.c file

#Compile the new file
gcc -m32 -no-pie -fno-stack-protector -z execstack -o program program.c

#Execute the new file in order to retrieve the address value
./prog