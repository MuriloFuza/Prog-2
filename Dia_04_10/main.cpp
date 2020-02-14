#include <stdio.h>
#include <stdlib.h>
#include "func.cpp"
int main(){
    int op = 999;
    lista num;
    int chave;
    do
    {
        printf("1   -   Iniciar vetor\n");
        printf("2   -   exibir vetor\n");
        printf("3   -   Hash!\n");
        printf("0   -   Sair\n");
        printf("Opcao: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
                inicia(&num);
                printf("vetor iniciado!");
                system("pause");
                system("cls");
            break;

        case 2:
                exibe(&num);
                system("pause");
                system("cls");
            break;

        case 3:
               printf("Qual chave deseja inserir: ");
               scanf("%d",&num);
               inserir(lista *a,&num);
            break;

        }
    } while (op!=0);


    return 0;
}
