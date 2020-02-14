/*
Programa para cadastrar funcionarios em um arquivo txt
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct funcionario{
	char nome[30];
	float salario;
	int idade;
};

void carrega(struct funcionario vetor[20],int &tl){
	
	char nome[10];
	float salario;
	int idade;
	tl = 0;
	FILE *arq=fopen("empresa.txt","r");
		if(arq == NULL){
		printf("Erro no arquivo - Não encontrado");
	}else{
		while(!feof(arq)){
			fscanf(arq,"%s %f %d \n",nome,&salario,&idade);
			strcpy(vetor[tl].nome,nome);
			vetor[tl].salario = salario;
			vetor[tl].idade = idade;
			tl++;
		}
		printf("Vetor carregado com sucesso!!\n");
	}
	fclose(arq);
	system("pause");
}

void regravar(struct funcionario vetor[20],int &tl){
	int i;
	FILE *arq=fopen("empresa.txt","w");

		for(i = 0;i<tl;i++){
			fprintf(arq,"%s " "%5.2f " "%d\n",vetor[i].nome, vetor[i].salario, vetor[i].idade);
		}
	fclose(arq);
	printf("Vetor regravado com sucesso!!\n");
	system("pause");
}

void exibe(struct funcionario vetor[20], int tl){
	int i;
	for(i = 0; i< tl;i++){
		printf("Nome: %s 	Salario: %.2f 	Idade: %d \n",vetor[i].nome, vetor[i].salario, vetor[i].idade);
	}
		system("pause");
}

int busca(struct funcionario vetor[20], int tl, char nome[10]){
	int i;
	int pos = -1;
	for(i = 0; i <=tl;i++){
		if(strcmp(vetor[i].nome,nome) == 0){
			pos = i;
		}
	}
	return pos;
}

void adicionar(struct funcionario vetor[20],int &tl){
	char nome[10];
	int idade;
	float salario;
	
	printf("Nome: ");
	scanf("%s",&nome);
	printf("Salario: ");
	scanf("%f",&salario);
	printf("Idade: ");
	scanf("%d",&idade);
	
	strcpy(vetor[tl].nome,nome);
	vetor[tl].idade = idade;
	vetor[tl].salario = salario;
	printf("Funcionario incluido!");
	tl++;
		
}

main(){
	int op;
	int tl = 0;
	struct funcionario vetor[20];
	int pos;
	char nome[10];
	
	while(op!=6){
		system("cls");
		printf("1	-	Leitura do arquivo txt\n");
		printf("2	-	Exibe o conteudo do arquivo\n");
		printf("3	-	Busca um funcionario\n");
		printf("4	-	Incluir um novo funcionario\n");
		printf("5	-	Regravar o vetor no arquivo empresa\n");
		printf("6	-	Sair\n");
		printf("Opcao: ");
		scanf("%d",&op);
		
		switch(op){
				case 1: {
					//função para carregar o arquivo txt
						system("cls");
						carrega(vetor,tl);
					break;
				}
			
				case 2: {
					//Função para exibir os funcionarios
						system("cls");
					exibe(vetor,tl);
					break;
				}
			
				case 3:{
					//Busca a pessoa pelo nome que é perguntado e armazena na variavel nome criada no main e mandada para a função
						system("cls");
					printf("Nome da pessoa : ");
					scanf("%s",nome);
					
					pos = busca(vetor,tl,nome);
					if(pos == -1){
						printf("\n\nFuncionario nao encontrado!\n\n");
					}else{
						printf("Pessoa encontrada na posicao %d\n",pos);
						printf("Nome	:	%s\n",vetor[pos].nome);
						printf("Salario	:	%.2f\n",vetor[pos].salario);
						printf("Idade	:	%d\n",vetor[pos].idade);
					}
					system("pause");
					break;
						
				}
				
				case 4: {
					system("cls");
					adicionar(vetor,tl);
					system("pause");
					break;
				}
				
				
				case 5: {
					//função para carregar o arquivo txt
						system("cls");
						regravar(vetor,tl);
					break;
				}
				
				
		}
	}

	getchar();
}
