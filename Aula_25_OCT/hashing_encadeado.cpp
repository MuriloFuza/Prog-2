#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define alf 26
typedef struct no{
  char nome[10];
  no *prox;
}no;

typedef struct{
  char chave;
  no *cabeca;
}tab;

class hashNome{
public:
  tab tabela[alf];
  hashNome();//construtor
  int hash(char nome[]);// calcular o endereço através de (1°letra) % alf"26" = endereço
  void inserir(char nome[]);//inserir pessoas na tabela
  void exibir();//exibir todas as pessoas
  void consultaP(char nome[]);//consultar pessoas na tabela
  void consultaLI(char *letra);//consultar pessoas pela letra inicial do nome
};
hashNome::hashNome()
{
  int i,j,cont;
  tab p;
  p.chave = (char)65;
  p.cabeca = NULL;
  i = 13;
  j = 65;
    for(cont = 0; cont < 26; cont++)
      {
        tabela[i] = p;
        i++;
        j++;
        p.chave = (char)j;
        if(i==26) i = 0;
      }//for para percorrer a tabela
}//construtor

int hashNome::hash(char nome[]){
  int ender;
  ender = nome[0]%alf;
  return ender;
}// calcular o endereço através de (1°letra) % alf"26" = endereço

void hashNome::inserir(char *nome)
{
  int ender;
  strcpy(nome,strupr(nome));
  ender = hash(nome);
  no *novo = new no;
  strcpy(novo->nome,nome);
  novo->prox = NULL;
  if(tabela[ender].cabeca == NULL) tabela[ender].cabeca = novo;
  else{
    novo->prox = tabela[ender].cabeca;
    tabela[ender].cabeca = novo;
  }
  printf("\nInserido com sucesso!");
}//inserir pessoas na tabela

void hashNome::exibir()
{
  int i;
  no *atual;
    for(i=0;i<alf;i++)
    {
      printf("(%d) Chave: %c\n",i,tabela[i].chave);
      atual = tabela[i].cabeca;
      while(atual!=NULL){
        printf("__________Nome: %s\n",atual->nome);
        atual = atual->prox;
      }
    }
}//exibir todas as pessoas

void hashNome::consultaP(char nome[])
{
    strcpy(nome,strupr(nome));
    int ender = hash(nome);
    no *atual = tabela[ender].cabeca;
    while ((atual!=NULL)&&(strcmp(nome,atual->nome) != 0)) {
        atual = atual->prox;
    }
    if(atual == NULL) printf("Nome %s nao encontrado!",nome);
    else  printf("Nome %s encontrado!",nome);

}//consultar pessoas na tabela

void hashNome::consultaLI(char *letra)
{
  letra = strupr(letra);
  int ender = hash(letra);
  no *atual = tabela[ender].cabeca;
  while(atual != NULL){
    printf("Nome: %s\n",atual->nome);
    atual = atual->prox;
  }
}//consultar pessoas pela letra inicial do nome

int main()
{
  hashNome f = hashNome();
  char nome[10];
  char inicial;
  int op;

  do {
    printf("1 - Inserir Pessoas:\n");
    printf("2 - Exibir tabela:\n");
    printf("3 - Consultar pessoa:\n");
    printf("4 - Consultar atraves da letra inicial:\n");
    printf("0 - Sair:\n");
    printf("Opcao: ");
    scanf("%d",&op);

      switch (op) {
        case 1:
                  printf("\nInsira o nome: ");
                  fflush(stdin);
                  gets(nome);
                  f.inserir(nome);
                  printf("Inserido!\n");
                  system("pause");
                  system("cls");
              break;

        case 2:
                  printf("\n\n      Tabela:\n\n");
                  f.exibir();
                  system("pause");
                  system("cls");
             break;

        case 3:
                  printf("\nInsira o nome: ");
                  fflush(stdin);
                  gets(nome);
                  f.consultaP(nome);
                  system("pause");
                  system("cls");
              break;

        case 4:
                  printf("\nInsira a inicial dos nome: ");
                  fflush(stdin);
                  inicial = getchar();
                  f.consultaLI(&inicial);
                  system("pause");
                  system("cls");
              break;
      }
  } while(op != 0);

}
