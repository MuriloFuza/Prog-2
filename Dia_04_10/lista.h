#include <stdio.h>
#define max 8

typedef struct
{
	int chave;
   char status[2];
} tipo_elem;

typedef struct
{
	tipo_elem info;
} no;

typedef struct{
	no A[max];
}lista;


   void iniciar(lista *a);
   void exibe(lista  *a);
   int hash1(int chave,lista *a);
   int hash2(int chave,lista *a);
   void inserir(int chave,lista *a);
   void remover(int chave,lista *a);

   


