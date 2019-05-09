#!/bin/bash
gcc -m32 -no-pie -fno-stack-protector -z execstack -o mission0 mission0.c