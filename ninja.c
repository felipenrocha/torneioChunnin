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
int ninjutsu, genjutsu,taijutsu, defesa,i,j = random_line();
int  aux = 0;

if(lista){


while(aux != 16){
    //Carrega lista:
   
    char * nome = NULL;
    do{
       
        i = 0 ;
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
    while(texto[j] != '\n' && texto[j] != EOF ){
        i++;
        j++;
    }
    char * defesachar = (char*) malloc(sizeof(char)*(i + 1));
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
    texto[fsize] = 0;
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
    
return ninja_one;
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




t_node * luta_npc(t_node * root, t_node *  parent){

    if(is_leaf(root)){
        return NULL;
    }      
    
   else if(is_parent(root) && root != parent){
      // Checa se há um nó que possui 2 filhos para duelarem
        int attribute = rand() % 3 + 1;
        Ninja * ninja_one = root->left->node; 
        Ninja * ninja_two = root->right->node;
        Ninja * winner = fight(ninja_one, ninja_two, attribute);
        Ninja * loser  = retorna_perdedor(ninja_one, ninja_two, attribute);
        root->node = winner;
        printf("%s (%s %d) x %s (%s %d)  \n%s ganhou a batalha\n",
        ninja_one->nome, retorna_string_atributo(attribute), retorna_valor_atributo(ninja_one, attribute),
        ninja_two->nome, retorna_string_atributo(attribute), retorna_valor_atributo(ninja_two, attribute),
        winner->nome);
        //ninja_free(loser);
        free(root->right);
        free(root->left);
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    else{
       // printf("Oi");
        luta_npc(root->left, parent);

        luta_npc(root->right, parent);
    }

    return root;
}


void luta_personagem(Ninja * player, t_node * root){
      int curr_attribute = 0,a = curr_attribute, i = 0;
while(i<4){
    Ninja * ninja_one = player;
    t_node * parent = busca_parent_node(root, player);
    
    Ninja * ninja_two = NULL;
    if(parent->right->node == player){
     ninja_two = parent->left->node;
    
    }else{
        ninja_two = parent->right->node;
    }
    printf("\n\n\n%da ETAPA\n\n", i+1);
    printf("Seu personagem : %s\n", player->nome);
    if(supremacia_elemental(ninja_one, ninja_two) ==1){

        printf("INFERIORIDADE ELEMENTAL: %s < %s\n", ninja_one->elemento, ninja_two->elemento);
        printf("Todos Atributos foram multiplicados por 0.8x\n\n");

        
    }
    else if(supremacia_elemental(ninja_one, ninja_two) == 2 ){

        printf("SUPREMACIA ELEMENTAL: %s > %s\n", ninja_one->elemento, ninja_two->elemento);
        printf("Todos Atributos foram multiplicados por 1.2x\n\n");

    }
    printf("Seu adversario: %s\n", ninja_two->nome);
    ninja_one = multiplica_atributo(supremacia_elemental(ninja_one, ninja_two), ninja_one);
    a = print_atributos_validos(curr_attribute, player);
    
    curr_attribute = a;

    Ninja * winner = fight(ninja_one, ninja_two, a);
    Ninja * loser  = retorna_perdedor(ninja_one, ninja_two, a);
    printf("%s (%s %d) x %s (%s %d)  \n%s ganhou a batalha\n",
        ninja_one->nome, retorna_string_atributo(a), retorna_valor_atributo(ninja_one, a),
        ninja_two->nome, retorna_string_atributo(a), retorna_valor_atributo(ninja_two, a),
        winner->nome);
    player = retorna_atributos(supremacia_elemental(ninja_one, ninja_two), player);

   // ninja_free(loser);
    free(parent->left);
    free(parent->right);

    parent->right = NULL;
    parent->left = NULL;

    
    parent->node = winner;
    //tree_print_preorder(root);
    if(player == loser){
        printf("\n\n DERROTA \n\n");
        printf("\n\nResultados da %da etapa:\n", i+1);
        root =  luta_npc(root, parent);
        break;
    }
    if(root->node != winner && i != 4){
    printf("\n\nResultados da %da etapa:\n", i+1);
    root =  luta_npc(root, parent);
}
i++;
}
    
       /* while(root->node == NULL){
                printf("\n\nResultados da %da etapa:\n", i+1);
                root = luta_npc(root, NULL);
                i++;
            }*/
    
    if(player == root->node){
        printf("\nVencedor: %s\n", root->node->nome);}

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


Ninja * retorna_perdedor(Ninja * ninja_one, Ninja * ninja_two, int attribute){

    switch(attribute){
        case 1:
            if(ninja_one->ninjutsu < ninja_two->ninjutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 2:
            if(ninja_one->genjutsu < ninja_two->genjutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 3:
            if(ninja_one->taijutsu < ninja_two->taijutsu){
                return ninja_one;
            }else{
                return ninja_two;
            }

        case 4:
            if(ninja_one->defesa < ninja_two->defesa){
                return ninja_one;
            }else{
                return ninja_two;
            }
    }

}

char * retorna_string_atributo( int atributo){

    if(atributo == 1){
        return "Ninjutsu";
    }
    else if(atributo == 2){
        return "Genjutsu";
    }
    else if(atributo == 3){
        return "Taijutsu";
    }
    else if(atributo == 4){
        return "Defesa";
    }
}

int retorna_valor_atributo(Ninja * ninja, int atributo){

    if(atributo == 1){
        return ninja->ninjutsu;
    }
    else if(atributo == 2){
        return ninja->genjutsu;
    }
    else if(atributo == 3){
        return ninja->taijutsu;
    }
    else if(atributo == 4){
        return ninja->defesa;
    }


}


int print_atributos_validos(int current_attribute, Ninja * player_one){
int a = 0;

    if(current_attribute == 0){
        do{
            printf("1) Ninjutsu : %d\n", player_one->ninjutsu);
            printf("2) Genjutsu : %d\n", player_one->genjutsu);
            printf("3) Taijutsu : %d\n", player_one->taijutsu);
            printf("4) Defesa   : %d\n", player_one->defesa);

            
            
                scanf("%i", &a);
                if((a<1 || a > 4)){
                    printf("\nSelecione um atributo valido.\n");
                }
        }while(a<1 || a > 4);
        return a;

    }
    else if(current_attribute == 1){
        do{
            printf("X) XX       : XX\n");
            printf("2) Genjutsu : %d\n", player_one->genjutsu);
            printf("3) Taijutsu : %d\n", player_one->taijutsu);
            printf("4) Defesa   : %d\n", player_one->defesa);               
            scanf("%i", &a);
            if((a<1 || a > 4) || a == 1){
                printf("\nSelecione um atributo valido.\n");
            }
        }while((a<1 || a > 4) || a == 1);
        return a;

    }else if(current_attribute == 2){
        do{
            printf("1) Ninjutsu : %d\n", player_one->ninjutsu);
            printf("X) XX       : XX\n");
            printf("3) Taijutsu : %d\n", player_one->taijutsu);
            printf("4) Defesa   : %d\n", player_one->defesa);
       
            scanf("%i", &a);
            if((a<1 || a > 4) || a == 2){
                printf("\nSelecione um atributo valido.\n");
            }
        }while((a<1 || a > 4) || a == 2);
        return a;
    }
    else if(current_attribute == 3){
        do{
            printf("1) Ninjutsu : %d\n", player_one->ninjutsu);
            printf("2) Genjutsu : %d\n", player_one->genjutsu);
            printf("X) XX       : XX\n");
            printf("4) Defesa   : %d\n", player_one->defesa);     
            scanf("%i", &a);
            if((a<1 || a > 4) || a == 3){
                printf("\nSelecione um atributo valido.\n");
            }
        }while((a<1 || a > 4) || a == 3);
        return a;

    }
    else if(current_attribute == 4){
        do{
            printf("1) Ninjutsu : %d\n", player_one->ninjutsu);
            printf("2) Genjutsu : %d\n", player_one->genjutsu);
            printf("3) Taijutsu : %d\n", player_one->taijutsu);
            printf("X) XX       : XX\n");
        
            scanf("%i", &a);
            if((a<1 || a > 4) || a == 4){
                printf("\nSelecione um atributo valido.\n");
            }
        }while((a<1 || a > 4) || a == 4);
        return a;

    }
    return 0;

}



void menu() {
    printf("----------- BEM VINDO AO EXAME CHUNNIN ----------------\n");
    printf("1) Comecar exame\n");
    printf("2) Sair\n\n");

    int aux = 0;
    do{
        scanf("%i", &aux);
        if(aux != 2 && aux != 1){
            printf("Opcao invalida");
        }
    }while(aux != 2 && aux != 1);
    if(aux == 1){
    srand(time(NULL));

    FILE *file = fopen(ARQUIVO, "r");
    char * texto = inicializa_arquivo(file);
    t_lista_dupla* lista =  separa_ninjas(texto, file);


   // imprime_lista(lista);

    t_node * root = tree_create(4);

    add_ninjas(lista, root);

  
   // tree_print_preorder(root);

    Ninja * player  = tela_personagem(lista);  
    
    luta_personagem(player, root);
    
    destroy_tree(root);

    free_lista(lista);
    
    free(texto);
    fclose(file);
    }
    else{


        return ;


    }
}