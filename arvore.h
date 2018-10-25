#ifndef __ARVORE_H__
#define __ARVORE_H__

#include "ninja.h"

typedef struct node {
    Ninja * node;
    struct node* left;
    struct node * right;
}t_node;



#endif