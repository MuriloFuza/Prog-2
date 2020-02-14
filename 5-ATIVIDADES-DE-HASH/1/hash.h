#include <stdio.h>
#include <string.h>
#define tamanho 100
#define overflow 4

typedef struct
{
    char tipo, desc[50];
    int link;
} tabela;

void inicializar(tabela item[tamanho]);
int hash(char tipo);
int hashOverflow(tabela item[tamanho]);
int inserir(tabela item[tamanho], char tipo, char desc[50]);
int exibir(tabela item[tamanho], char tipo);
int estoque(tabela item[tamanho]);

