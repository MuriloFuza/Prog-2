#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct 
{
    int num;
    char tipo;
    char nome[15];
    float limite;
    float saldo;
}conta;

class Binario
{
public: 
    Binario();
    void insere();
    conta lecliente();
    void exibeum(conta c);
    void exibe();
    void busca(int num);
};