#!/bin/bash

#enter into debugger mode
gdb ./mission3 

#create a break point into main
b *main

#run the program
r

#print the system address and save it somewhere
p system

#print the exit address and save it somewhere
p exit

#exit from gdb
q

