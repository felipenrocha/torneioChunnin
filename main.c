#include "ninja.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    FILE *file = fopen(ARQUIVO, "r");
    char * texto = inicializa_arquivo(file);
    separa_ninjas(texto, file);
    return 0;
}
