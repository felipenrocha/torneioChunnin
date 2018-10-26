#ifndef __NINJA_H__
#define __NINJA_H__
#define ARQUIVO "ninjas.txt"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * inicializa_arquivo(FILE * file);

int random_line();

int checa_ninja(t_lista_dupla* lista, char * nome);//checa se o ninja ja foi selecionado;



#endif