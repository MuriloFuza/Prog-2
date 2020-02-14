#include "func.cpp"

int main(){
    Binario b = Binario();
    int op =999;
    int num;
    do
    {
        printf("1   -   Ler um cliente e gravar no arquivo\n"); // Tipo ab -- Escrita: Os dados são inseridos no fim do arquivo;
        printf("2   -   Exibir os clientes cadastrados\n"); //Tipo rb - Leitura: Leitura do arquivo;
        printf("3   -   Buscar um cliente pelo Nro da conta\n"); // Tipo rb;
        printf("0   -   Sair\n");
        printf("Op: ");
        scanf("%d",&op);

            switch (op)
            {
            case 1:
                b.insere();
                printf("\nGravado com Sucesso!!\n");
                system("pause");
                system("cls");

                break;
            
            case 2:
                b.exibe();
                printf("\n");
                system("pause");
                system("cls");
                break;

            case 3:
                printf("\nEntre com o numero da conta: ");
                scanf("%d",&num);
                b.busca(num);
                printf("\n");
                system("pause");
                system("cls");
                break;

            
            }
    } while (op != 0);
    
}