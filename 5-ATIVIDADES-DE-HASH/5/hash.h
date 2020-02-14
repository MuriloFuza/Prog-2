#include <stdio.h>
#include <string.h>
#define tamanho 100
#define cAno 2019
#define cMes 10
#define cDia 23

typedef struct
{
    char nome[50];
    int dia, mes, ano;
} pessoas;

void inicializar(pessoas aniversario[tamanho]);
int hash(pessoas aniversario[tamanho]);
int inserir(pessoas aniversario[tamanho], char nome[50], int dia, int mes, int ano);
int aniversariantesMes(pessoas aniversario[tamanho], int mes);