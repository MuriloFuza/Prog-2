#include "hash.c"

int main()
{
    int menu;
    char tipo, desc[50];
    tabela item[tamanho];
    inicializar(item);

    do
    {
        limpar();
        printf("LEMBRE-SE: Todas as letras de categoria/tipo tem de ser digitadas em MAIUSCULO, caso contrario, nada vai funcionar!!\n");
        printf("1 - inserir item\n");
        printf("2 - listar itens em uma categoria/tipo\n");
        printf("3 - exibir a quantidade de produtos em cada tipo\n");
        printf("0 - sair\n");

        printf("menu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                limpar();
                printf("insira o tipo do item (A = Alimento, H = Higiene, L = Limpeza e V = Vestimenta)\ntipo> ");
                fflush(stdin);
                tipo = fgetc(stdin);
                printf("insira uma descricao do item: ");
                fflush(stdin);
                fgets(desc, 50, stdin);
                if(inserir(item, tipo, desc))
                    printf("inserido com sucesso\n");
                else
                    printf("nao foi possivel inserir, verifique o tipo especificado!\n");
                parar();
            break;
            }

            case 2:
            {
                limpar();
                printf("qual tipo de item deseja exibir? (A = Alimento, H = Higiene, L = Limpeza, V = Vestimenta)\ntipo> ");
                fflush(stdin);
                tipo = fgetc(stdin);
                exibir(item, tipo);
                parar();
            break;
            }

            case 3:
            {
                limpar();
                estoque(item);
                parar();
            break;
            }
        }
    } while(menu != 0);
    return 0;
}