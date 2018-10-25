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
fclose(file);

string[fsize] = 0;
int j = 0, nline=0,nchar=0, nmax=0;
//printf("%s", string);
while(j != fsize){
    
    if(string[j] == '\n'){
        nline++;
        if(nmax<nchar){
            nmax = --nchar;
        }
        nchar = 0;
    }
    nchar++;
    j++;
}
j = 0;
int i = 0, aux = 0;
printf("\n%s\n", string);
char texto[nline][nmax];


for(i=0;i<nline-1;i++,j++){
    for(aux = 0; texto[i][aux] != '\n';aux++,j++){
    texto[i][aux] = string[j];
       // printf("%c", string[j]);
    }
    texto[i][aux] = '\n';
    

}

for(i=0;i<nline;i++){
        for(aux = 0; texto[i][aux] != '\n';aux++){
            printf("%c", texto[i][aux]);
        }
        printf("\n");

    }
    return string;
}

    return NULL;
}

t_lista_dupla* separa_ninjas(char* texto, FILE * file){

t_lista_dupla* lista = aloca_lista();
    
int ninjutsu, genjutsu,taijutsu, defesa;
int  aux = 0;
int j = 0;
while(aux != 17){

    int i = 0;
    //nome:
    while(texto[j] != ','){
        i++;
        j++;
    }
    
    
    char * nome = (char*) malloc(i*sizeof(char)+1);
    j = j - i;
    i = 0;

    while(texto[j] != ','){
        nome[i] = texto[j];
        i++;
        j++;
    }

    nome[i] = '\0';


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
    aux++;
}

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

char * random_line(char * texto, FILE * file){
    srand((unsigned) time(0));
    int j = 0;
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);  //Pega o tamanho do arquivo para alocar
    fseek(file, 0, SEEK_SET);  //Retorna ao inicio  

    int random = (rand() % fsize);
    while(texto[random] != '\n' && texto[random] != EOF){
        random++;
    }
    j = random;
    if(texto[j] == EOF){
        while(texto[j] != '\n'){
         j--;
        }
        j++;
    }
   int i = 0;
   while(texto[j] != '\n' && texto[j] != EOF){
       i++;
       j++;
   }
    j = j - i;
    char * line = (char*) malloc(sizeof(char)*i + 1);
    i = 0;
    while(texto[j] != '\n' && texto[j] != EOF){
        line[i] = texto[j];
        i++;
        j++;
    }

    printf("%s", line);
    return line;
}