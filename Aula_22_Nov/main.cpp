#include "func.cpp"

int main()
{
int op = 999;
indexado b = indexado();
b.constroindice();
do
{
    printf("1    -   Inserir no arquivo\n");
    printf("2    -   Exibe desordenado e ordenado\n");
    printf("3    -   Consultar produto\n");
    printf("0    -   Sair\n");
    printf("\nOp...: ");
    scanf("%d",&op);
        switch(op)
        {
            case 1:
                b.insere();
                system("pause");
                system("cls");
                break;

             case 2:
               system("cls");
                printf("\n----------------");
               printf("\n|Exibe Desordenado|");
               printf("\n----------------");
               b.exibedesordenado();
               printf("\n----------------");
               printf("\n|Exibe Ordenado|");
               printf("\n----------------");
               b.exibeordenado();
               printf("\n");
                system("pause");
                system("cls");
                break;

             case 3:
               int cod = 0;
               printf("Insira o codigo do produto desejado: ");
               scanf("%d",&cod);
                  b.consulta(cod);
                  system("pause");
                  system("cls");
            break;

           
        }
}while(op != 0);

}