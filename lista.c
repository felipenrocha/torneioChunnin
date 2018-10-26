#include "lista.h"
#include "ninja.h"


t_lista_dupla* aloca_lista(){
    t_lista_dupla * lista = (t_lista_dupla*) malloc(sizeof(t_lista_dupla));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    return lista;
}

elemento_ninja* aloca_elemento(Ninja * ninja){

    elemento_ninja* elemento = (elemento_ninja*) malloc(sizeof(elemento_ninja));
    elemento->ninja = ninja;
    elemento->proximo = NULL;
    elemento->anterior = NULL;

    return elemento;


}


t_lista_dupla * insere_ninja(t_lista_dupla* lista, char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa){

    Ninja * ninja = ninja_create(nome, elemento, ninjutsu, genjutsu, taijutsu, defesa);
    elemento_ninja* aux = aloca_elemento(ninja);
    if(lista->inicio == NULL && lista->fim == NULL){
        //insere inicio
        lista->inicio = aux;
        lista->fim = lista->inicio;
        lista->tamanho++;
       
    }
    else{
        //insere final
        lista->fim->proximo = aux;
        aux->anterior = lista->fim;
        lista->fim = aux;

    }

    return lista;

}

void imprime_lista(t_lista_dupla* lista){
 elemento_ninja * aux = lista->inicio;

while(aux != NULL){
    printf("Nome: %s\n", aux->ninja->nome);
    aux = aux->proximo;
 }

}