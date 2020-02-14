#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <dos.h>
#include <iostream>
#define TF 50000
#define MAX 50000

class Vetor{
	public:
		int vetor[TF];
		bool ordenado;
		void cria();
		void ordenaDrecescente();
		void ordenaBolha();
		void ordenaSelecao();
		void ordenaInsercaoDireta();
		void ordenaInsercaoBinaria();
		int buscaExaustiva(int elem);
		int buscaSequencial(int elem);
		int buscaBinaria(int elem);
		int buscaBinariaRecursiva(int elem, int inicio, int fim);
		void exibe();
};
//---------------------------------------------------------------------------------------------------------//
void Vetor::cria(){
	int i;
	srand(time(NULL));
	for(i = 0; i < TF; i++){
		vetor[i] = rand() % MAX;
		ordenado = false;
	}
		printf("Vetor criado!\n");

}
//---------------------------------------------------------------------------------------------------------//
void Vetor::exibe(){
	int i;
	for(i=0;i<TF;i++){
		printf("\nPosicao = %d numero = %d",i,vetor[i]);
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------------------//
int Vetor::buscaExaustiva(int elem){
	int i;
	int pos = -1;
	for(i = 0;i<TF;i++){
		if(elem == vetor[i]){
			pos = i;
		}
	}
	printf("Prim : %d",vetor[24999]);
	return pos;

}
//---------------------------------------------------------------------------------------------------------//
//Metodo de BOLHA, o mais burro!!
void Vetor::ordenaBolha(){
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
//---------------------------------------------------------------------------------------------------------//
void Vetor::ordenaInsercaoDireta(){
            int aux,j,n,posicao;
            if(vetor[0]>vetor[1]){
                aux = vetor[0];
                vetor[0] = vetor[1];
                vetor[1] = aux;
            }
            for(n=2;n<TF;n++){
                aux=vetor[n];
                posicao = buscaSequencial(aux);
                for(j=n;j>posicao;j--){
                    vetor[j]=vetor[j-1];
                }
                    vetor[posicao] = aux;
            }
            ordenado = true;
}
//---------------------------------------------------------------------------------------------------------//
void Vetor::ordenaSelecao(){
            int i,j, menor, posmenor;
                for(i=0;i<TF-1;i++){
                    menor = vetor[i];
                    posmenor=i;
                    for(j=i+1;j<TF;j++){
                        if(vetor[i]<menor){
                            menor = vetor[j];
                            posmenor = j;
                        }
                        vetor[posmenor] = vetor[i];
                        vetor[i] = menor;
                    }
                }
                ordenado = true;
}
//---------------------------------------------------------------------------------------------------------//
void Vetor::ordenaDrecescente(){
        int fim,j,aux;
	for(fim = TF-1;fim>0;fim--){
		for(j=0;j<fim;j++){
			if(vetor[j]<vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------------//
int Vetor::buscaSequencial(int elem){
	 int i=0;
	 while((elem>vetor[i]) && (i<TF))
        i = i+1;
     return i;
}
//---------------------------------------------------------------------------------------------------------//
int Vetor::buscaBinaria(int elem){
	int inicio = 0;
	int fim = TF -1;
	int meio =(inicio+fim) /2;
	while((elem !=vetor[meio])&& (inicio<fim)){
		if(elem > vetor[meio]){
			inicio = meio+1;
		}else{
			fim = meio;
		}
		 meio =(inicio+fim) /2;
	}

	if(elem >vetor[meio]){
		return (meio+1);
	}else
	return meio;
}


int main(){
	Vetor f = Vetor();
	int op;
	int pos;
	int num;
	int elem;
	clock_t t[2];

	while(op!=10){
		system("cls");
		printf("1	-	Criar um vetor com nuns aleatorios\n");
		printf("2	-	Exibe o conteudo do vetor\n");
		printf("3	-	Busca exaustiva\n");
		printf("4 	-	Ordem crescente Bolha\n");
		printf("5	-	Busca sequencial\n");
		printf("6	-	Busca Binaria\n");
		printf("7       -       Ordena decrescente\n");
		printf("8       -       Ordena Metodo da SELECAO\n");
		printf("9       -       Ordena Metodo INSERCAO DIRETA\n");
		printf("10	-	Sair\n");
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
					t[0] = clock();
					pos = f.buscaExaustiva(elem);
					t[1] = clock();
					printf("\n\n");
					if(pos == -1){
						printf("\nNumero nao encontrado!\n");
					}else{
						printf("Encontrado na posicao %d o numero %d\n",pos,f.vetor[pos]);
					}

					float diff = (t[1] - t[0]) / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;
				}

				case 4:{
				    t[0]=clock();
					f.ordenaBolha();
					t[1]=clock();
					printf("\nOrdenados\n");
					float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;
				}

				case 5:{
				if(f.ordenado == true){
					printf("\nQual numero deseja busca: ");
					scanf("%d",&elem);
					printf("\n\n");
					t[0] = clock();
					int pos = f.buscaSequencial(elem);
					t[1] = clock();
					if(pos == elem){
						printf("\nNumero nao encontrado!" );
					}else{
						printf("\nEncontrado\n");
					}
				}
				else{
					printf("\n\nVetor nao ordenado, ordene e retorne!\n\n");
				}
                    float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("pause");
					system("cls");
					break;
				}

				case 6:{

					if(f.ordenado == true){
					printf("\nQual numero deseja busca: ");
					scanf("%d",&elem);
                    t[0] = clock();
					pos = f.buscaBinaria(elem);
                    t[1] = clock();
					if(pos == -1){
						printf("\nNumero nao encontrado!\n");
					}else{
						printf("\nEncontrado \n");
					}

					}else{
							printf("\n\nVetor nao ordenado, ordene e retorne!\n\n");
					}
                    float diff = (t[1] - t[0]) / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);


					system("pause");
					system("cls");
					break;
				}

                case 7:{

				    t[0]=clock();
					f.ordenaDrecescente();
					t[1]=clock();
					printf("\nOrdenados\n");
					float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;

                }

                case 8:{
                   t[0]=clock();
					f.ordenaSelecao();
					t[1]=clock();
					printf("\nOrdenados\n");
					float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;

                    break;
                }

                case 9:{
                        t[0]=clock();
					f.ordenaInsercaoDireta();
					t[1]=clock();
					printf("\nOrdenados\n");
					float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;
                }


				case 10:{
					system("cls");
					printf("\n			Programa finalizado!!\n\n");
					break;
				}

			}

	}


	system("pause");
	return 0;
}

