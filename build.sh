#!/bin/bash
gcc -o tetris.exe main.c  -I include -L lib -lraylib -lgdi32 -lwinmm
./tetris.exe