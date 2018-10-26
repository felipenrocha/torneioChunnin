
#ifndef __LISTA_H__
#define __LISTA_H__

#include "ninja.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ninja{
    
    char* nome;
    char* elemento;
    int ninjutsu;
    int genjutsu;
    int taijutsu;
    int defesa;
    
}Ninja;

typedef struct elemento_ninja{
    Ninja* ninja;
    struct elemento_ninja* proximo;
    struct elemento_ninja* anterior;

}elemento_ninja;


typedef struct lista {

    elemento_ninja* inicio;
    elemento_ninja* fim;
    int tamanho;
    

}t_lista_dupla;

t_lista_dupla* aloca_lista();

elemento_ninja* aloca_elemento(Ninja * ninja);

t_lista_dupla* insere_ninja(t_lista_dupla* lista, char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa);

t_lista_dupla* separa_ninjas(char* arquivotexto, FILE * file); 

Ninja* ninja_create(char* nome, char* elemento, int ninjutsu,int genjutsu, int taijutsu, int defesa);

void imprime_lista(t_lista_dupla* lista);
#endif