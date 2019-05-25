#!/bin/bash

#enter into debugger mode
gdb ./mission5

#get the main function assembly code
disass main

#get out from debugger mode
p