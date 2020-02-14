#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max 25 //TAMANHO TOTAL DA LISTA
#define tp 10 //AREA DE OVERFLOW

typedef struct
{
    char status;
    int cod;
    char nome[40];
    int notaf;
    int elo;
}pessoa;

class hash_enc_over_flow
{
public:
    pessoa lista[max];
    void inserir(int cod,char nome[40],int notaf);
    void consulta_todos();
    int hash(int cod);
    void consultaaprovados();

    //construtor
    hash_enc_over_flow()
    {
        int i =0;
            for(i=0;i<max;i++)
            {
                lista[i].status = 'L';
                lista[i].cod = NULL;
                strcpy(lista[i].nome,"vazio");
                lista[i].notaf = NULL;
                lista[i].elo = -1;
            }
    };//contrutor
};

int hash_enc_over_flow::hash(int cod)
{
    return (cod % tp);
}



void hash_enc_over_flow::consulta_todos()
{
    int i =0;
    for(i=0;i<max;i++)
    {
        printf("Status %c ::",lista[i].status);
        printf("Cod: %d  ::",lista[i].cod);
        printf("Nome: %s  ::",lista[i].nome);
        printf("Nota F.: %d  ::",lista[i].notaf);
        printf("Elo: %d\n",lista[i].elo);
    }
}

void hash_enc_over_flow::inserir(int cod,char nome[40], int notaf)
{
    int end = 0;
    int cont = 0;
    end = hash(cod);
    if(lista[end].status == 'L')
    {
        cont =0;
    }
    if(lista[end].status == 'L')
    {
        lista[end].status = 'O';
        lista[end].cod = cod;
        strcpy(lista[end].nome,nome);
        lista[end].notaf = notaf;
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
                    if (end == hash(cod))
                    {
                    lista[k].status = 'O';
                    lista[k].cod = cod;
                    strcpy(lista[k].nome,nome);
                    lista[k].notaf = notaf;
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

void hash_enc_over_flow::consultaaprovados()
{
    for(int i = 0; i < max; i++)
    {
        if(lista[i].notaf >= 7)
        {
            printf("Cod: %d  ::",lista[i].cod);
            printf("Nome: %s  ::",lista[i].nome);
            printf("Nota F.: %d  ::",lista[i].notaf);
            printf("Elo: %d\n",lista[i].elo);
        }
    }
}



//programa principal
int main()
{
    int op = 0;
    hash_enc_over_flow f = hash_enc_over_flow();
    char nome[40];
    int cod, notafinal;
    do
    {
        printf("1    -   Casdastrar aluno\n");
        printf("2    -   Consultar todas os alunos\n");
        printf("3    -   Consultar aprovados\n");
        printf("4    -   Sair\n");
        scanf("%d",&op);

            switch (op)
            {
                case 1:
                        printf("Insira o codigo do aluno: ");
                        scanf("%d",&cod);
                        printf("\nInsira o nome do aluno: ");
                        fflush(stdin);
                        gets(nome);
                        printf("\nInsira a nota do aluno: ");
                        scanf("%d",&notafinal);
                        f.inserir(cod,nome,notafinal);
                        system("pause");
                        system("cls");
                    break;

                case 2:
                        f.consulta_todos();
                        system("pause");
                        system("cls");
                    break;

                case 3:
                        printf("Lista de aprovados!\n");
                       f.consultaaprovados();
                        system("pause");
                        system("cls");
                    break;


                case 4:

                    break;
            }
    } while (op != 4);


    return 0;
}
