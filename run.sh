#!/bin/bash

clear

gcc -c main.c convert_to_csv.c read_csv.c
gcc main.o convert_to_csv.o read_csv.o
./a.out

rm main.o
rm convert_to_csv.o
rm read_csv.o

echo "Compiling and running successful"
