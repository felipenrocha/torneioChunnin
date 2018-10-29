#include "ninja.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char * inicializa_arquivo(FILE * file){

int i=0;

if ( file != NULL ){

fseek(file, 0, SEEK_END);
long fsize = ftell(file);  //Pega o tamanho do arquivo para alocar
fseek(file, 0, SEEK_SET);  //Retorna ao inicio
char *string = malloc(fsize + 1);
fread(string, fsize, 1, file);


string[fsize] = '\0';
    return string;
}

    return NULL;
}

t_lista_dupla* separa_ninjas(char* texto, FILE * file){

t_lista_dupla* lista = aloca_lista();
int ninjutsu, genjutsu,taijutsu, defesa,i,j;
int  aux = 0;

if(lista){


while(aux != 16){
    //Carrega lista:
   
    char * nome = NULL;
    do{
       
        i = 0;    
        j = random_line();
       //nome:
        while(texto[j] != ','){
            i++;
            j++;
        }      
        nome = (char*) malloc((i+1)*sizeof(char));
        j = j - i;
        i = 0;

        while(texto[j] != ','){

            nome[i] = texto[j];
            i++;
            j++;

        }

        nome[i] = '\0';
      //  printf("%s\n", nome);
        
    }while(!checa_ninja(lista, nome));


    //Elemento: 

    j = j + 2; //Pula ',' e ' '  
    i = 0;

    
    while(texto[j] != ','){
        i++;
        j++;
    }
    char * elemento = (char*) malloc((i+1)*sizeof(char));
    j = j - i;
    i = 0;
    
    while(texto[j] != ','){
        elemento[i] = texto[j];
        j++;
        i++;
    }
    elemento[i] = '\0';


    //Ninjutsu:
    i = 0; 
    j = j + 2;
    while(texto[j] != ','){
        i++;
        j++;
    }
    char * ninjutsuchar = (char*) malloc( sizeof(char)*(i + 1));
    j = j - i;
    i = 0;
    while(texto[j] != ','){
        ninjutsuchar[i] = texto[j];
        j++;
        i++;
    }
    ninjutsuchar[i] = '\0';
    ninjutsu = atol(ninjutsuchar);


    //Genjutsu:
    i = 0; 
    j = j + 2;
    while(texto[j] != ','){
        i++;
        j++;
    }
    char * genjutsuchar = (char*) malloc(sizeof(char)*(i + 1));
    j = j - i;
    i = 0;
    while(texto[j] != ','){
        genjutsuchar[i] = texto[j];
        j++;
        i++;
    }
    genjutsuchar[i] = '\0';
    genjutsu = atol(genjutsuchar);

    //taijutsu

    i = 0; 
    j = j + 2;


    while(texto[j] != ','){
        i++;
        j++;
    }
    char * taijutsuchar = (char*) malloc(sizeof(char)*(i + 1));
    j = j - i;
    i = 0;
    while(texto[j] != ','){
        taijutsuchar[i] = texto[j];
        j++;
        i++;
    }
    taijutsuchar[i] = '\0';
    taijutsu = atol(taijutsuchar);

    //defesa
    i = 0; 
    j = j + 2;
    while(texto[j] != '\n'){
        i++;
        j++;
    }
    char * defesachar = (char*) malloc( sizeof(char)*(i + 1));
    j = j - i;
    i = 0;
    while(texto[j] != '\n'){
        defesachar[i] = texto[j];
        j++;
        i++;
    }
    defesachar[i] = '\0';
    defesa = atol(defesachar);
    insere_ninja(lista, nome, elemento, ninjutsu, genjutsu, taijutsu, defesa);
    free(nome);
    free(elemento);
    free(ninjutsuchar);
    free(taijutsuchar);
    free(genjutsuchar);
    free(defesachar);
    aux++;
    

        }

        return lista;}

        return NULL;
}





Ninja* ninja_create(char* nome, char* elemento, int ninjutsu,int genjutsu, int taijutsu, int defesa){

    Ninja* ninja = (Ninja*) malloc(sizeof(Ninja));
    ninja->nome = (char*) malloc((strlen(nome)+1)*sizeof(nome));
    ninja->elemento = (char*) malloc((strlen(nome)+1)*sizeof(elemento));
    strcpy(ninja->nome, nome);
    strcpy(ninja->elemento, elemento);
    ninja->ninjutsu = ninjutsu;
    ninja->genjutsu = genjutsu;
    ninja->taijutsu = taijutsu;
    ninja->defesa = defesa;

    return ninja;

}

int random_line(){
    FILE *file = fopen(ARQUIVO, "r");
    fseek(file, 0, SEEK_END);
    int fsize = ftell(file);  //Pega o tamanho do arquivo para alocar
    fseek(file, 0, SEEK_SET);  //Retorna ao inicio  
    char *texto = malloc(fsize + 1);
    fread(texto, fsize, 1, file);
    fclose(file); 
    int random = (rand() % (fsize-1));
    // printf("Random inicial: %d\n", random);
    while(texto[random] != '\n' && random != 0){
            random--;
        } 
        if(random != 0){  

        random++;
        
        }
        free(texto);
        return random;
}



int checa_ninja(t_lista_dupla* lista, char * nome){
    elemento_ninja * aux = lista->inicio;
    for(int i = 0; aux != NULL;i++){
        if(strcmp(nome, aux->ninja->nome) == 0){
            free(nome);
            return 0;
        }
        aux = aux->proximo;
    }
    return 1;


}


void ninja_free(Ninja* ninja){

    free(ninja->nome);
    free(ninja->elemento);
    free(ninja);


}

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two,
int attribute){

    switch(attribute){
        case 0:
            if(ninja_one->ninjutsu >= ninja_two->ninjutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 1:
            if(ninja_one->genjutsu >= ninja_two->genjutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 2:
            if(ninja_one->taijutsu >= ninja_two->taijutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 3:
            if(ninja_one->defesa >= ninja_two->defesa){
                return ninja_one;
            }else{
                return ninja_two;
            }
    }

}

Ninja * tela_personagem(t_lista_dupla* lista){

    elemento_ninja * aux = lista->inicio;
    printf("Escolha seu personagem: \n\n");
    

    int i = 0, j;
  
    for(i; i<16;i++){

        j = rand() % 4;
        //printf("\nj = %d\n", j);
   
        if(j == 0){
        printf("Personagem %d:\nNinjutsu: %d  Genjutsu: ?? Taijutsu: ?? Defesa: ??\n\n", i+1, aux->ninja->ninjutsu);
        }
        else if(j == 1){
                printf("Personagem %d:\nNinjutsu: ??  Genjutsu: %d Taijutsu: ?? Defesa: ??\n\n", i+1, aux->ninja->genjutsu);
        }                    
        else if(j == 2){
                printf("Personagem %d:\nNinjutsu: ??  Genjutsu: ?? Taijutsu: %d Defesa: ??\n\n", i+1, aux->ninja->taijutsu);
        }
        else if(j ==3){
                printf("Personagem %d:\nNinjutsu: ??  Genjutsu: ?? Taijutsu: ?? Defesa: %d\n\n", i+1, aux->ninja->defesa);
        }        


        aux = aux->proximo;
        }
        printf("Qual personagem deseja escolher? (Numeros de 1-16)\n");
        int a;
        scanf("%i", &a);
        aux = lista->inicio;
        for(i = 1; i<a; i++){
            aux = aux->proximo;
        }


        printf("\nPersonagem Escolhido: %s\n", aux->ninja->nome);

        return aux->ninja;
       

    }




void luta_npc(t_node * root, Ninja * player){
    int attribute = rand() % 3;

    if(root == NULL){
        return;
    }
    if((root->left->left == NULL && root->right->right == NULL)
    // Checa se há um nó que possui 2 filhos para duelarem
    && (strcmp(root->left->node->nome, player->nome)
    && strcmp(root->right->node->nome, player->nome))){
        Ninja * ninja_one = root->left->node; 
        Ninja * ninja_two = root->right->node;
        root->node = ninja_create(fight(ninja_one, ninja_two, attribute)->nome, 
        fight(ninja_one, ninja_two, attribute)->elemento, 
        fight(ninja_one, ninja_two, attribute)->ninjutsu, 
        fight(ninja_one, ninja_two, attribute)->genjutsu,
        fight(ninja_one, ninja_two, attribute)->taijutsu,
        fight(ninja_one, ninja_two, attribute)->defesa);
        ninja_free(ninja_one);
        ninja_free(ninja_two);
        root->left = NULL;
        root->right = NULL;
    }
    luta_npc(root->left, player);
    luta_npc(root->right, player);


}


t_node * no_personagem(t_node * root, Ninja * player){
 
    if(root == NULL){
        return root;
    }

    if(root->left->node == player || root->right->node == player){
        
        return root;
    }
    no_personagem(root->left, player);
    no_personagem(root->right, player);
    return root;
}