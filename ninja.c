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
        case 1:
            if(ninja_one->ninjutsu >= ninja_two->ninjutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 2:
            if(ninja_one->genjutsu >= ninja_two->genjutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 3:
            if(ninja_one->taijutsu >= ninja_two->taijutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 4:
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
        int a;
        do{
        printf("Qual personagem deseja escolher? (Numeros de 1-16)\n");
        
        scanf("%i", &a);
        if(a<1 || a>16){
            printf("Selecione um personagem valido entre 1 e 16.\n");
        }
        
        }while(a<1 || a>16);
        aux = lista->inicio;
        for(i = 1; i<a; i++){
            aux = aux->proximo;
        }


       // printf("\nPersonagem Escolhido: %s\n", aux->ninja->nome);

        return  aux->ninja;
       

    }




void luta_npc(t_node * root, t_node *  parent){
    int attribute = rand() % 3;

    if(root == parent){
        return ;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }
       
 
    if((root->left->left == NULL && root->right->right == NULL)
     && (root->left->node != NULL && root->right->node !=NULL) ){
      // Checa se há um nó que possui 2 filhos para duelarem
       
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

   if(root->left->node == NULL && root->right->node == NULL){

            luta_npc(root->left, parent);

            luta_npc(root->right, parent);

    }


}


void luta_personagem(t_node * parent, Ninja * player, t_node * root){
    Ninja * ninja_one = player;
    Ninja * ninja_two = NULL;
    if(parent->right->node == player){
     ninja_two = parent->left->node;
    
    }else{
        ninja_two = parent->right->node;
    }
    

    printf("1a ETAPA\n\n");
    printf("Seu personagem : %s\n", player->nome);
    if(supremacia_elemental(ninja_one, ninja_two) ==1){

        printf("INFERIORIDADE ELEMENTAL: %s < %s\n", ninja_one->elemento, ninja_two->elemento);
        printf("Todos Atributos foram multiplicados por 0.8x\n\n");

        
    }
    else if(supremacia_elemental(ninja_one, ninja_two) == 2 ){

        printf("SUPREMACIA ELEMENTAL: %s > %s\n", ninja_one->elemento, ninja_two->elemento);
        printf("Todos Atributos foram multiplicados por 1.2x\n\n");

    }

    ninja_one = multiplica_atributo(supremacia_elemental(ninja_one, ninja_two), ninja_one);


    printf("1)Ninjutsu : %d\n", player->ninjutsu);
    printf("2)Genjutsu : %d\n", player->genjutsu);
    printf("3)Taijutsu : %d\n", player->taijutsu);
    printf("4)Defesa   : %d\n", player->defesa);
 
        printf("\nSeu adversario: %s\n\n", ninja_two->nome);

    
    int a;
    do{
    printf("Selecione um atributo: ");
    scanf("%i",&a);
    if(a<1 || a>4){

        printf("Selecione um atributo valido.\n");}

    }while(a<1 || a > 4);

    Ninja * winner = fight(ninja_one, ninja_two, a);
    if(winner == ninja_one){
        printf("Vitoria\n");

        player = retorna_atributos(supremacia_elemental(ninja_one, ninja_two), player);

        ninja_free(ninja_two);
        parent->right = NULL;
        parent->left = NULL;

    }
    else if(winner == ninja_two){
        ninja_free(ninja_one);
        parent->right = NULL;
        parent->left = NULL;
        printf("Derrota");
    }
    parent->node = winner;
    


}





Ninja * multiplica_atributo(int n, Ninja * player){

if(n == 1){

    player->ninjutsu = 0.8 * player->ninjutsu;
    player->genjutsu = 0.8 * player->genjutsu;
    player->taijutsu = 0.8 * player->taijutsu;
    player->defesa =   0.8 * player->defesa;
    return player;
}

else if(n == 2){

    player->ninjutsu = 1.2 * player->ninjutsu;
    player->genjutsu = 1.2 * player->genjutsu;
    player->taijutsu = 1.2 * player->taijutsu;
    player->defesa =   1.2 * player->defesa;
    return player;
}

return player;

}






int supremacia_elemental(Ninja* player_one, Ninja* player_two){

    if(!strcmp(player_one->elemento,"Fogo")){

        if(!strcmp(player_two->elemento, "Agua")){
            return 1;
        }
        else if(!strcmp(player_two->elemento, "Vento")){
            return 2;
        }
        else{
            return 0;
        }
    }


    
    else if(!strcmp(player_one->elemento,"Vento")){
        
        if(!strcmp(player_two->elemento, "Fogo")){
            return 1;
        }
        else if(!strcmp(player_two->elemento, "Relampago")){
            return 2;
        }
        else{
            return 0;
        }



    }

    else if(!strcmp(player_one->elemento,"Relampago")){

        if(!strcmp(player_two->elemento, "Vento")){
            return 1;
        }
        else if(!strcmp(player_two->elemento, "Terra")){
            return 2;
        }
        else{
            return 0;
        }


    }
    else if(!strcmp(player_one->elemento,"Terra")){

        if(!strcmp(player_two->elemento, "Relampago")){
            return 1;
        }
        else if(!strcmp(player_two->elemento, "Agua")){
            return 2;
        }
        else{
            return 0;
        }

    }
    else if(!strcmp(player_one->elemento,"Agua")){


        if(!strcmp(player_two->elemento, "Terra")){
            return 1;
        }
        else if(!strcmp(player_two->elemento, "Fogo")){
            return 2;
        }
        else{
            return 0;
        }
    }

return 0;


}


Ninja * retorna_atributos(int n, Ninja * player){

    if(n == 1){
        player->ninjutsu = player->ninjutsu / 0.8;
        player->genjutsu = player->genjutsu / 0.8;
        player->taijutsu = player->taijutsu / 0.8;
        player->defesa = player->defesa / 0.8;

        return player;
    }
    else if(n == 2){

        player->ninjutsu = player->ninjutsu / 1.2;
        player->genjutsu = player->genjutsu / 1.2;
        player->taijutsu = player->taijutsu / 1.2;
        player->defesa = player->defesa / 1.2;
        
        
        return player;

    }

return player;

}