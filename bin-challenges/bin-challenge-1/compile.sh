#!/bin/bash
gcc -m32 -no-pie -fno-stack-protector -z execstack -o mission1 mission1.c