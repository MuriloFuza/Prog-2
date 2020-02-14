#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <dos.h>
#define TF 50000
#define MAX 99999

class Vetor{
	public:
		int vetor[TF];
		bool ordenado;
		void cria();
		int buscaExaustiva(int elem);
		void ordenaCrescente();
		int buscaSequencial(int elem);
		int buscaBinaria(int elem);
		void exibe();
};

void Vetor::cria(){
	int i;
	srand(time(NULL));
	for(i = 0; i < TF; i++){
		vetor[i] = rand() % MAX;
		ordenado = false;
	}
		printf("Vetor criado!\n");

}

void Vetor::exibe(){
	int i;
	for(i=0;i<TF;i++){
		printf("\nPosicao = %d numero = %d",i,vetor[i]);
	}
	printf("\n");
}

int Vetor::buscaExaustiva(int elem){
	int i;
	int pos = -1;
	for(i = 0;i<TF;i++){
		if(elem == vetor[i]){
			pos = i;
		}
	}
	return pos;
	
}

//Metodo de BOlha, o mais burro!!
void Vetor::ordenaCrescente(){
	int fim,j,aux;
	for(fim = TF-1;fim>0;fim--){
		for(j=0;j<fim;j++){
			if(vetor[j]>vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
	ordenado = true;
}

int Vetor::buscaSequencial(int elem){
	int i = 0;
	int pos = -1;
	while((i<TF)&&(elem>vetor[i])){
		i++;
	}
	if(elem == vetor[i] && (i<TF) ){
		pos = i;
	}
	
	return pos;
}

int Vetor::buscaBinaria(int elem){
	int inicio = 0;
	int fim = TF -1;
	int meio =(inicio+fim) /2;
	int pos = -1;
	while((inicio < fim) && (elem !=vetor[meio])){
		if(elem < vetor[meio]){
			fim = meio;
		}else{
			inicio = meio +1;
		}
		 meio =(inicio+fim) /2;
	}
	
	if(elem == vetor[meio]){
		pos = meio;
	}
	
	return pos;
}


int main(){
	Vetor f = Vetor();
	int op;
	int pos;
	int num;
	int elem;
	
	while(op!=7){
		system("cls");
		printf("1	-	Criar um vetor com nuns aleatorios\n");
		printf("2	-	Exibe o conteudo do vetor\n");
		printf("3	-	Busca exaustiva\n");
		printf("4 	-	Ordem crescente\n");
		printf("5	-	Busca sequencial\n");
		printf("6	-	Busca Binaria\n");
		printf("7	-	Sair\n");
		printf("Opcao: ");
		scanf("%d",&op);
			
			switch(op){
				case 1:{
					f.cria();
						system("pause");
					system("cls");
					break;
				}
				
				case 2:{
					f.exibe();
						system("pause");
					system("cls");
					break;
				}
				
				case 3:{
					printf("\nQual numero deseja busca: ");
					scanf("%d",&elem);
					pos = f.buscaExaustiva(elem);
					printf("\n\n");
					if(pos == -1){
						printf("\nNumero nao encontrado!\n");
					}else{
						printf("Encontrado na posicao %d o numero %d\n",pos,f.vetor[pos]);
					}
					system("pause");
					system("cls");
					break;
				}
				
				case 4:{
					f.ordenaCrescente();
					printf("\nOrdenados\n");
					system("pause");
					system("cls");
					break;
				}
				
				case 5:{
				if(f.ordenado == true){
					printf("\nQual numero deseja busca: ");
					scanf("%d",&elem);
					pos = f.buscaSequencial(elem);
					printf("\n\n");
					if(pos == -1){
						printf("\nNumero nao encontrado!\n");
					}else{
						printf("Encontrado na posicao %d o numero %d\n",pos,f.vetor[pos]);
					}
				}
				else{
					printf("\n\nVetor nao ordenado, ordene e retorne!\n\n");
				}
				
					system("pause");
					system("cls");
					break;
				}
				
				case 6:{
					if(f.ordenado == true){
					printf("\nQual numero deseja busca: ");
					scanf("%d",&elem);
					pos = f.buscaBinaria(elem);
					if(pos == -1){
						printf("\nNumero nao encontrado!\n");
					}else{
						printf("Encontrado na posicao %d o numero %d\n",pos,f.vetor[pos]);
					}
					
					}else{
							printf("\n\nVetor nao ordenado, ordene e retorne!\n\n");
					}
					system("pause");
					system("cls");
					break;
				}
				
				case 7:{
					system("cls");
					printf("\n			Programa finalizado!!\n\n");
					break;
				}
				
			}
		
	}
	
	
	system("pause");
	return 0;
}
