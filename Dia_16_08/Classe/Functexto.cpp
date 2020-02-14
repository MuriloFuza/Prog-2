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

class Functexto{
	public:
	struct funcionario vetor[20];
	int tl;
	void carrega();
	void exibe();
	int busca(char nome[10]);
	void adicionar();
	void regravar();
};

void Functexto::carrega(){
	
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



void Functexto::exibe(){
	int i;
	for(i = 0; i< tl;i++){
		printf("Nome: %s 	Salario: %.2f 	Idade: %d \n",vetor[i].nome, vetor[i].salario, vetor[i].idade);
	}
		system("pause");
}

int Functexto::busca(char nome[10]){
	int i;
	int pos = -1;
	for(i = 0; i <=tl;i++){
		if(strcmp(vetor[i].nome,nome) == 0){
			pos = i;
		}
	}
	return pos;
}

void Functexto::adicionar(){
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

void Functexto::regravar(){
	int i;
	FILE *arq=fopen("empresa.txt","w");

		for(i = 0;i<tl;i++){
			fprintf(arq,"%s " "%5.2f " "%d\n",vetor[i].nome, vetor[i].salario, vetor[i].idade);
		}
	fclose(arq);
	printf("Vetor regravado com sucesso!!\n");
	system("pause");
}

main(){
	Functexto f = Functexto();
	int op;
	f.tl = 0;
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
						f.carrega();
						printf("\n tl = %d",f.tl);
					break;
				}
			
				case 2: {
					//Função para exibir os funcionarios
						system("cls");
						f.exibe();
					break;
				}
			
				case 3:{
					//Busca a pessoa pelo nome que é perguntado e armazena na variavel nome criada no main e mandada para a função
						system("cls");
					printf("Nome da pessoa : ");
					scanf("%s",nome);
					
					pos = f.busca(nome);
					if(pos == -1){
						printf("\n\nFuncionario nao encontrado!\n\n");
					}else{
						printf("Pessoa encontrada na posicao %d\n",pos);
						printf("Nome	:	%s\n",f.vetor[pos].nome);
						printf("Salario	:	%.2f\n",f.vetor[pos].salario);
						printf("Idade	:	%d\n",f.vetor[pos].idade);
					}
					system("pause");
					break;
						
				}
				
				case 4: {
					system("cls");
					f.adicionar();
					system("pause");
					break;
				}
				
				
				case 5: {
					//função para carregar o arquivo txt
						system("cls");
						f.regravar();
					break;
				}
				
				
		}
	}

	getchar();
}
