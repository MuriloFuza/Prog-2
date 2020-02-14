#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define tf 50
//PROGRAMA COM PROBLEMA NO INSERE NOVO FUNCIONARIO
struct indice{
        char chave[10];
        int posicao;
};

struct funcionario{
        int matricula;
        char nome[10];
        float salario;
};

class TabIndexado{
public:
    struct indice vetindice[tf];
    struct funcionario vetdados[tf];
    //construtor
    TabIndexado();
    int tl;
    //fun豫o para carregar as duas tabelas
    void letextocarregatabelas();
    void ExibeTabelasDesordenadas();
    void RelatorioOrdenado();
    void insere();
    funcionario LeUmFuncionario();
    int BuscaBinaria(char nome[10]);
};
//FUN플O PARA BUSCA BINARIA
TabIndexado ::BuscaBinaria(char nome[10]){
    int meio;
    int fim = tl-1;
    int inicio = 0;
    meio = (inicio+fim) / 2;
    while((strcmp(nome,vetindice[meio].chave) !=0)   && (inicio <fim)){
            if(strcmp(nome,vetindice[meio].chave)>0){
                inicio = meio+1;
            }else{
                fim = meio;
            }
            meio = (inicio + fim) /2;
    }
        if(strcmp(vetindice[meio].chave,nome) == 0){
            return meio;
        }else{
            if(strcmp(vetindice[meio].chave,nome) > 0)
                return meio+1;
                else
                    return meio;
        }


}
//INICIALIZA플O
TabIndexado ::TabIndexado(){
    tl =0;
    int i;
    for(i=0;i<tf;i++)
        strcpy(vetindice[i].chave ,"vazio");
}
//EXIBE AS TABELAS DESORDENADAS
void TabIndexado ::ExibeTabelasDesordenadas(){
        int i;
            for(i=0;i<tl;i++){
                printf("Chave: %s, Pos: %d ......Matric: %d, Nome: %s, Salario %.2f\n",vetindice[i].chave, vetindice[i].posicao,vetdados[i].matricula,vetdados[i].nome,vetdados[i].salario);
            }
            system("pause");
}
// FUN플O PARA INSERIR UM FUNCIONARIO
void TabIndexado::insere(){
    struct funcionario f;
    f = LeUmFuncionario();
    vetdados[tl] = f;
    int posideal = BuscaBinaria(f.nome);
    if(posideal < tl){
        for(int i=tl;i>=posideal;i--){
            vetindice[i] = vetindice[i-1];
        }
    }
    strcpy(vetindice[posideal].chave,f.nome);
    vetindice[posideal].posicao = tl;
    tl++;
    ExibeTabelasDesordenadas();
    system("pause");

}
//FUN플O PARA LER O TEXTO  E CARREGAR AS TABELAS
void TabIndexado::letextocarregatabelas(){
    struct funcionario f;
    FILE*arq=fopen("Funcionario.txt","r");
        if(arq ==NULL){
            printf("\nArquivo nao encontrado!!");
            tl =0;
            }else{
                tl = 0;
                    while(!feof(arq)){

                                fscanf(arq ,"%d %s %f\n",&f.matricula,&f.nome,&f.salario);
                                vetdados[tl] = f;
                                strcpy(vetindice[tl].chave,f.nome);
                                vetindice[tl].posicao = tl;
                                tl++;
                                }
                    fclose(arq);
                    int i;
                    //ordenando o vetor
                   struct indice aux;
                    int fim;
                    for(fim = tl-1;fim>0;fim--)
                        for(i=0;i<fim;i++){
                            if(strcmp(vetindice[i].chave , vetindice[i+1].chave)==1){
                                aux = vetindice[i];
                                vetindice[i] = vetindice[i+1];
                                vetindice[i+1] = aux;
                            }
                        }
                }
                printf("\nFeito!\n");
                system("pause");
}
//FUN플O  PARA LER OS DADOS DO FUNCIONARIO
funcionario TabIndexado::LeUmFuncionario(){
    struct funcionario f;
    printf("\nEntre com a matricula do novo funcionario: ");
    scanf("%d",&f.matricula);
    printf("\nEntre com o nome do funcionario: ");
    fflush(stdin);
    gets(f.nome);
    printf("\nEntre com o salario do funcionario: ");
    scanf("%f",&f.salario);
    return f;
}
//FUN플O PARA APRESENTAR UM RELATORIO ORDENADO
void TabIndexado::RelatorioOrdenado(){
        int i;
        int posdado;
        printf("\n              RELATORIO: \n\n");
        for(i=0;i<tl;i++){
            posdado = vetindice[i].posicao;
               printf("Matric: %d, Nome: %s, Salario %.2f\n",vetdados[posdado].matricula,vetdados[posdado].nome,vetdados[posdado].salario);
        }
            system("pause");


}

main(){
    TabIndexado i = TabIndexado();
    int posdados, posindice;
    char nome[10];
    int op = 0;
        while(op != 6){
                system("cls");
            printf("\n1 -   Ler arquivo texto e carregar as tabelas");
            printf("\n2 -   Exibe tabelas de Indice e Dados desordenado");
            printf("\n3 -   Insere um novo funcionario");
            printf("\n4 -   Exibe tabelas de Indice e Dados ordenados");
            printf("\n5 -   Busca Binaria pelo nome");
            printf("\n6 -   Sair");
            printf("\nOpcao: ");
            scanf("%d",&op);

                    switch(op){

                            case 1:{
                                        i.letextocarregatabelas();
                                        system("cls");
                                break;
                            }

                            case 2:{
                                        i.ExibeTabelasDesordenadas();
                                        system("cls");
                                break;
                            }

                            case 3:{
                                        i.insere();
                                        system("cls");
                                break;
                            }

                            case 4:{
                                        i.RelatorioOrdenado();
                                        system("cls");
                                break;
                            }

                            case 5:{
                                        printf("\nEntre com o nome a procurar: ");
                                        fflush(stdin);
                                        gets(nome);
                                        posindice = i.BuscaBinaria(nome);
                                            if((posindice < i.tl) && (strcmp(nome,i.vetindice[posindice].chave) == 0)){
                                                posdados = i.vetindice[posindice].posicao;
                                                printf("\nAchou no indice = %d e Dado  = %d\nMeio: %d",posindice,posdados,posindice);
                                            }else{
                                                printf("\nParou no meio : %d!!",posindice);
                                            }
                                            printf("\n");
                                            system("pause");
                                            system("cls");
                                break;
                            }
                    }//fecha switch
        }//fecha while

}// fecha main




