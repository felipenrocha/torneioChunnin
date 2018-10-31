#ifndef __ARVORE_H__
#define __ARVORE_H__

#include "ninja.h"

#include "structs.h"

t_node* tree_create();

t_node* node_create();

void add_ninjas(t_lista_dupla* lista, t_node* root);

void tree_print_preorder(t_node * root);

t_node * busca_parent_node(t_node * root, Ninja * player);
#endif