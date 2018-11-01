#include "arvore.h"
#include "structs.h"



t_node* node_create(){

    t_node * node = (t_node *) malloc(sizeof(t_node));
    node->left = NULL;
    node->right = NULL;
    node->node = NULL;
    
    return node;



}
t_node* tree_create(int niveis){
    
    t_node* no = node_create();

    if(niveis == 0){

        return no;

    }
    no->left = tree_create(niveis-1);
    no->right = tree_create(niveis-1);
    return no;



}


void tree_print_preorder(t_node* root){

    if(root!=NULL){

        if(root->node != NULL)
        {printf("%s\n", root->node->nome);}
        tree_print_preorder(root->left);
        tree_print_preorder(root->right);

    }
}



int is_parent(t_node * node){
    if(node->right->node != NULL && node->left->node != NULL){
        return 1;
    }else{
        return 0;
    }
}

int is_leaf(t_node * node){

    if(node->right == NULL && node->left == NULL){
        return 1;
    }else{
        return 0;
    }


}


void add_ninjas(t_lista_dupla * lista, t_node* root){
    elemento_ninja * aux = lista->inicio;
    
    //Função destinada a adicionar os ninjas nas folhas da arvore.

    if(root->left == NULL && root->right == NULL){
        while(aux->tag == 1){

            aux = aux->proximo;

        }
        root->node = aux->ninja;
        aux->tag = 1;
        return ;
    }
  
    add_ninjas(lista, root->left);
    add_ninjas(lista, root->right);




}

t_node * busca_parent_node(t_node * root, Ninja * player){
t_node * aux = NULL;
    
    if(root->left == NULL && root->right == NULL){
        return NULL;
    }

    if((root->left->node != NULL && root->right->node != NULL) &&
    (root->right->node == player) || (root->left->node == player)){
        
        aux = root;
        return aux;
    }
   
    aux = busca_parent_node(root->left, player);

    if(aux == NULL){

     aux = busca_parent_node(root->right, player);

    }


    return aux;
   
    
}

void destroy_tree(t_node * root){

    if(!root){
        return;
    }
    if(root->right == NULL && root->left == NULL){
        free(root);
        return;
    }
    destroy_tree(root->left);
    destroy_tree(root->right);



}

