#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max 34 //TAMANHO TOTAL DA LISTA
#define tp 26 //AREA DE OVERFLOW

typedef struct
{
    char status;
    char nome[40];
    int elo;
}pessoa;

class hash_enc_over_flow
{
public:
    pessoa lista[max];
    void inserir(char nome[40]);
    void consulta_todos();
    int hash(char nome[40]);
    void buscaUm(char nome[40]);
    void consultaletra(char letra);
    bool excluir(char nome[]);

    //construtor
    hash_enc_over_flow()
    {
        int i =0;
            for(i=0;i<max;i++)
            {
                lista[i].status = 'L';
                strcpy(lista[i].nome,"vazio");
                lista[i].elo = -1;
            }
    };//contrutor
};

int hash_enc_over_flow::hash(char nome[])
{
    return (nome[0] % tp);
}



void hash_enc_over_flow::consulta_todos()
{
    int i =0;
    for(i=0;i<max;i++)
    {
        printf("[%d] :: ",i);
        printf("Status: %c  ::",lista[i].status);
        printf("Nome: %s  ::",lista[i].nome);
        printf("Elo: %d\n",lista[i].elo);
    }
}

void hash_enc_over_flow::inserir(char nome[40])
{
    int end = 0;
    int cont = 0;
    end = hash(nome);
    if(lista[end].status == 'L')
    {
        cont =0;
    }
    if(lista[end].status == 'L')
    {
        lista[end].status = 'O';
        strcpy(lista[end].nome,nome);
        printf("\nInseriu %s sem colosao em %d",nome,end);
    }else
        {//OCORREU COLISÃO -- POSIÇÃO DE NOME JA ESTA OCUPADA
             int k = tp;
            while ((lista[k].status != 'L') && (k < max)){ k++;}
            if(k == max){printf("Lista cheia--ERRO!");}
            else
            {
                if(lista[k].status == 'L')
                {
                    cont++;
                    if (end == hash(nome))
                    {
                    lista[k].status = 'O';
                    strcpy(lista[k].nome,nome);
                    lista[k].elo == lista[end].elo;
                    lista[end].elo = k;
                    if((k != tp) &&(lista[k-1].nome[0] == nome[0])){
                        if (lista[k].status != 'L')
                        {
                            lista[k].elo = k - cont;
                        }
                    }
                    }

                }
            }
        }
}
void hash_enc_over_flow::buscaUm(char nome[40])
{
    int end_nome;
    end_nome = hash(nome);
    if(strcmp(lista[end_nome].nome,nome) == 0)
    {
        printf("\nEncontrou, Pos: %d",end_nome);
    }else if(strcmp(lista[end_nome].nome,nome) == 1){
       //busca no elo
       while ((lista[end_nome].elo != -1) && (strcmp(nome,lista[end_nome].nome) != 0))
       {
           end_nome = lista[end_nome].elo;
           printf("\nEncontrou, Pos: %d",end_nome);
       }
    }else
    {
         printf("\nNao encontrou!");
    }
}
void hash_enc_over_flow::consultaletra(char letra)
{
    for(int i = 0; i < max; i++)
    {
        if(lista[i].nome[0] == letra)
        {
            printf("[%d] :: ",i);
            printf("Status: %c  ::",lista[i].status);
            printf("Nome: %s  ::",lista[i].nome);
            printf("Elo: %d\n",lista[i].elo);
        }
    }
}



//programa principal
int main()
{
    int op = 0;
    hash_enc_over_flow f = hash_enc_over_flow();
    char nome[40],letra;
    do
    {
        printf("1    -   Inserir apenas o nome\n");
        printf("2    -   Consultar todas as pessoas\n");
        printf("3    -   Buscar um nome\n");
        printf("4    -   Consultar todas as pessoas com uma inicial digitada\n");
        printf("5    -   Sair\n");
        scanf("%d",&op);

            switch (op)
            {
                case 1:
                        printf("Insira um nome: ");
                        fflush(stdin);
                        gets(nome);
                        f.inserir(nome);
                        system("pause");
                        system("cls");
                    break;

                case 2:
                        f.consulta_todos();
                        system("pause");
                        system("cls");
                    break;

                case 3:
                        printf("Qual nome deseja buscar? ");
                        fflush(stdin);
                        gets(nome);
                        f.buscaUm(nome);
                        system("pause");
                        system("cls");
                    break;

                case 4:
                        printf("Entre com uma inicial: ");
                        fflush(stdin);
                        letra = getchar();
                        f.consultaletra(letra);
                        system("pause");
                        system("cls");
                    break;

                case 5:

                    break;
            }
    } while (op != 5);


    return 0;
}
