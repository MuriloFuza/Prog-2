#include "hash.h"

void inicializar(pessoas aniversario[tamanho])
{
    for(int i = 0; i < tamanho; i++)
    {
        aniversario[i].dia = NULL;
        aniversario[i].mes = NULL;
        aniversario[i].ano = NULL;
    }
}

int hash(pessoas aniversario[tamanho])
{
    for(int i = 0; i < tamanho; i++)
        if(aniversario[i].mes == NULL)
            return i;
    return -1;
}

int inserir(pessoas aniversario[tamanho], char nome[50], int dia, int mes, int ano)
{
    int endereco = hash(aniversario);
    if(endereco == -1)
        return 0;
    strcpy(aniversario[endereco].nome, nome);
    aniversario[endereco].dia = dia;
    aniversario[endereco].mes = mes;
    aniversario[endereco].ano = ano;
    return 1;
}

int aniversariantesMes(pessoas aniversario[tamanho], int mes)
{
    for(int i = 0; i < tamanho; i++)
        if(aniversario[i].mes == mes)
            printf("%d/%d/%d - %s\n", aniversario[i].dia, aniversario[i].mes, aniversario[i].ano, aniversario[i].nome);
}

int superiorDezoito(pessoas aniversario[tamanho])
{
    int cont = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(aniversario[i].ano > 0 && aniversario[i].mes > 0 && aniversario[i].dia > 0)
        {
            if(cAno - aniversario[i].ano > 18)
                cont = cont + 1;
            else if(cAno - aniversario[i].ano == 18)
            {
                if(cMes - aniversario[i].mes > 0)
                    cont = cont + 1;
                else
                {
                    if(cDia - aniversario[i].dia >= 0)
                        cont = cont + 1;
                }
            }
        }
    }
    return cont;
}

int excluirNome(pessoas aniversario[tamanho], char nome[50])
{
    int i;
    for(i = 0; i < tamanho, strcmp(aniversario[i].nome, nome) == 1; i++);
    aniversario[i].mes = 0;
    return 1;
}

int excluirMes(pessoas aniversario[tamanho], int mes)
{
    for(int i = 0; i < tamanho; i++)
    {
        if(aniversario[i].mes == mes)
            aniversario[i].mes = NULL;
    }
    return 1;
}

void parar()
{
    printf("pressione qualquer tecla para continuar...");
    fflush(stdin);
    getchar();
}

void limpar()
{
    for(int i = 0; i < 100; i++)
        printf("\n");
}