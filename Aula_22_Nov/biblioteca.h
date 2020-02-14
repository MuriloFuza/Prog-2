#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  
#include <conio.h>
#define tf 40

typedef struct 
{
    int  cod, min, estoque;
    char nome[tf];
}dados;

typedef struct 
{
    int chave, posaquivo;
}tabela;


class indexado
{
    public:
    tabela vetindice[tf];
    int tl;
    indexado();
    void constroindice();
    dados lemateria();
    //-----EXIBIR-----//
    void exibe_um(dados m);
    void exibeindice();
    void exibeordenado();
    void exibedesordenado();
    //-----INSERIR-----//
    void insere();
    //-----Consulta-Busca-----//
    void consulta(int cod);
    int buscabinaria(int num);


};
