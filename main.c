#include "ninja.h"

int main()
{
    FILE *file = fopen(ARQUIVO, "r");
   char * texto = inicializa_arquivo(file);
   separa_ninjas(texto, file);
    return 0;
}
