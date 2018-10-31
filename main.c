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


   // imprime_lista(lista);

    t_node * root = tree_create(4);

    

    add_ninjas(lista, root);

    printf("Primeira Etapa:\n");
    tree_print_preorder(root);
    Ninja * player  = tela_personagem(lista);
    
  //  luta_npc(root, player);

    
  // tree_print_preorder(root);
    t_node * parent = NULL;
    parent = busca_parent_node(root, player);
    luta_personagem(parent, player);

    return 0;
    
}
