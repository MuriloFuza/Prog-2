#include "lista.h"
#include <time.h>
#include <string.h>
void inicia(lista *a)
{
    int i;
        srand(time(NULL));
        for(i = 0; i < max; i++){
            strcpy(a->A[i].info.status,"l");
        }
};

void exibe(lista *a)
{
    int i=0;
    while(i<max)
		{
			 if(strcmp(a->A[i].info.status,"O") == 0)
            {
                printf("status: %s::(%d)=>%d\n",a->A[i].info.status,i,a->A[i].info.chave);
                i++; 
            }else {
                 printf("status: %s::(%d) = Vazio\n",a->A[i].info.status,i);
                i++; 
            }
           
		}
};

int hash1(int chave)
{
    int ender=0;
    ender = chave % max;
    return ender;
}

int hash2(int chave)
{
    int enderinicial = hash1(chave);
    int i = 1;
    int endernovo = (enderinicial+1) % max;
    return endernovo;
}

void inserir(lista *a,int chave)
{   
    if(strcmp(a->A[hash1(chave)].info.status,"O") == 0)
    {
        a->A[hash2(chave)].info.chave = chave;
        strcpy(a->A[hash2(chave)].info.status,"O");
    }else
    {
        a->A[hash1(chave)].info.chave = chave;
        strcpy(a->A[hash1(chave)].info.status,"O");
    }
    
}

void remover(int chave)
{

}
