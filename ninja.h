#ifndef __NINJA_H__
#define __NINJA_H__
#define ARQUIVO "ninjas.txt"
#include "lista.h"
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

char * inicializa_arquivo(FILE * file);

int random_line();

void ninja_free(Ninja* ninja);

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two,int attribute);

Ninja *  tela_personagem(t_lista_dupla* lista);

t_node * luta_npc(t_node * root, t_node * parent);

void luta_personagem(Ninja * player, t_node * root);


int supremacia_elemental(Ninja* player_one, Ninja* player_two);

Ninja * multiplica_atributo(int n, Ninja * player);

Ninja * retorna_atributos(int n, Ninja * player);


Ninja * retorna_perdedor(Ninja * ninja_one, Ninja * ninja_two, int attribute);

int retorna_valor_atributo(Ninja * ninja, int atributo);
char * retorna_string_atributo( int atributo);

int print_atributos_validos(int current_attribute, Ninja * player_one);

void menu();

#endif