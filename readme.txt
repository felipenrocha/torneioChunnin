OS: Linux - Ubuntu 18.04
Compiler: GCC 7.3.0 (C99)
Valgrind: 3.14.0

Compiling commands:
gcc -c lista.c
gcc -c arvore.c 
gcc -c ninja.c 
gcc -g -o main main.c lista.o arvore.o ninja.o 

Execução:

./main 

Execução com valgrind: 

valgrind ./main

