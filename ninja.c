#include "ninja.h"
#include "lista.h"
#include "time.h"
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

srand(time(NULL));


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
        
        
        nome = (char*) malloc(i*sizeof(char)+1);
        j = j - i;
        i = 0;

        while(texto[j] != ','){

            nome[i] = texto[j];
            i++;
            j++;

        }

        nome[i] = '\0';
        printf("%s\n", nome);
        
    }while(!checa_ninja(lista, nome));


    //Elemento: 

    j = j + 2; //Pula ',' e ' '  
    i = 0;

    
    while(texto[j] != ','){
        i++;
        j++;
    }
    char * elemento = (char*) malloc(i*sizeof(char)+1);
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
    char * ninjutsuchar = (char*) malloc( sizeof(char)*i + 1);
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
    char * genjutsuchar = (char*) malloc( sizeof(char)*i + 1);
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
    char * taijutsuchar = (char*) malloc( sizeof(char)*i + 1);
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
    char * defesachar = (char*) malloc( sizeof(char)*i + 1);
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
 imprime_lista(lista);
}




Ninja* ninja_create(char* nome, char* elemento, int ninjutsu,int genjutsu, int taijutsu, int defesa){

    Ninja* ninja = (Ninja*) malloc(sizeof(Ninja));
    ninja->nome = (char*) malloc(sizeof(nome));
    ninja->elemento = (char*) malloc(sizeof(elemento));
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
            return 0;
        }
        aux = aux->proximo;
    }
    return 1;


}


