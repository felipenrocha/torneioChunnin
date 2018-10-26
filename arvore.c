#include "arvore.h"
t_node* node_create(){
    t_node * node = (t_node *) malloc(sizeof(t_node));
    node->left = NULL;
    node->right = NULL;
    node->node = NULL;
    
    return node;



}
t_node* tree_create(int niveis){
    
    t_node* no = node_create();

    if(niveis == 1){
        
        return no;
    }

    no->left = tree_create(niveis--);
    no->right = tree_create(niveis--);

    return no;



}