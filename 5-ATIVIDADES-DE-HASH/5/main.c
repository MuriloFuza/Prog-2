#include "hash.c"

int main()
{
    int menu, dia, mes, ano;
    char nome[50];
    pessoas aniversario[tamanho];

    inicializar(aniversario);
    do
    {
        limpar();
        printf("1 - cadastrar amigo\n");
        printf("2 - aniversariantes do mes\n");
        printf("3 - contar pessoas com idade superior a 18 anos\n");
        printf("4 - excluir pessoa por nome\n");
        printf("5 - excluir pessoas de um determinado mes\n");
        printf("0 - sair\n");

        printf("menu> ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                limpar();
                printf("nome: ");
                fflush(stdin);
                fgets(nome, 50, stdin);
                printf("data de nascimento (xx xx xxxx): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                if(inserir(aniversario, nome, dia, mes, ano))
                    printf("inserido com sucesso!\n");
                else
                    printf("nao foi possivel inserir\n");
                parar();
            break;
            }

            case 2:
            {
                limpar();
                printf("deseja exibir os aniversariantes de que mes? ");
                scanf("%d", &mes);
                aniversariantesMes(aniversario, mes);
                parar();
            break;
            }

            case 3:
            {
                limpar();
                printf("existem %d pessoas maiores de 18 anos inseridas\n", superiorDezoito(aniversario));
                parar();
            break;
            }

            case 4:
            {
                limpar();
                printf("quem deseja remover da lista? ");
                fflush(stdin);
                fgets(nome, 50, stdin);
                excluirNome(aniversario, nome);
                printf("%s removido!\n", nome);
                parar();
            break;
            }

            case 5:
            {
                limpar();
                printf("qual mes deseja apagar? ");
                scanf("%d", &mes);
                excluirMes(aniversario, mes);
                printf("aniversariantes do mes %d excluidos com sucesso!\n", mes);
                parar();
            break;
            }
        }
    } while(menu != 0);
}