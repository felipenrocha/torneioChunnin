#include <time.h>

#include "ninja.h"
#include "lista.h"
#include "arvore.h"
#include "structs.h"

int main()
{
    srand(time(NULL));

    FILE *file = fopen(ARQUIVO, "r");
    char * texto = inicializa_arquivo(file);
    t_lista_dupla* lista =  separa_ninjas(texto, file);


    imprime_lista(lista);

    t_node * root = tree_create(4);

    

    add_ninjas(lista, root);

    printf("Primeira Etapa:\n");
    tree_print_preorder(root);
   Ninja * player = tela_personagem(lista);

  //  luta_npc(root, player);

  // printf("Segunda etapa: \n");
   // tree_print_preorder(root);
   t_node * no = no_personagem(root, player);
   if(no->right){
       printf("%s", no->right->node->nome);
   }else if(no->left){
       printf("%s", no->left->node->nome);
   }
    return 0;
    
}
