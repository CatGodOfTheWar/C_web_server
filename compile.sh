#!/bin/bash 

gcc -c create.c -o create.o
gcc -c handle_html.c -o handle_html.o
gcc -c css_js.c -o css_js.o
gcc -c image_music.c -o image_music.o
gcc -c r_error.c -o r_error.o
gcc -c w_error.c -o w_error.o
gcc -c logs.c -o logs.o -l sqlite3
gcc -o main main.c create.o css_js.o handle_html.o image_music.o r_error.o w_error.o logs.o -l sqlite3

echo "Compile complete!"
echo "The program will start!"
./main 
