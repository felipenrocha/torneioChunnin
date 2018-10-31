#ifndef __STRUCTS_H__
#define __STRUCTS_H__


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
    int tag;
    int n_lutas;
    struct elemento_ninja* proximo;
    struct elemento_ninja* anterior;

}elemento_ninja;

typedef struct node {
    Ninja * node;
    struct node* left;
    struct node * right;
}t_node;



typedef struct lista {

    elemento_ninja* inicio;
    elemento_ninja* fim;
    int tamanho;
    

}t_lista_dupla;

#endif