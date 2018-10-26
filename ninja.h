#ifndef __NINJA_H__
#define __NINJA_H__
#define ARQUIVO "ninjas.txt"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


char * inicializa_arquivo(FILE * file);

int random_line();

void ninja_free(Ninja* ninja);

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two,
int attribute);

#endif