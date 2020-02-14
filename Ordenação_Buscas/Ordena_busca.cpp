#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <dos.h>
#include <iostream>
#define TF 10
#define MAX 99

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
		void Quicksort(int inicio, int fim);
		void Heapsort(int fim);
		void startHeap();
		void startQuick();
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
//---------------------------------------------------------------------------------------------------------//
void Vetor::startQuick(){
	Quicksort(0,TF-1);
}
//---------------------------------------------------------------------------------------------------------//
void Vetor::Quicksort(int inicio, int fim){
	int aux, i, j, pivo;
	i = inicio;	j = fim;
	pivo = vetor[(i+j)/2];
	do{
		while (vetor[i]<pivo) i++;
		while (vetor[j]>pivo) j--;
		if(i<=j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}while (i<=j);
		if(j>inicio) Quicksort(inicio,j);
		if(i<fim)Quicksort(i,fim);
}
//---------------------------------------------------------------------------------------------------------//
void Vetor::startHeap(){
	Heapsort(TF);
}
//---------------------------------------------------------------------------------------------------------//
void Vetor::Heapsort(int fim){
	  int i = fim / 2, pai, filho, t;                                                                                                                                
   while(true) {
      if (i > 0) {
          i--;
          t = vetor[i];
      } else {
          fim--;
          if (fim <= 0) return;
          t = vetor[fim];
          vetor[fim] = vetor[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < fim) {
          if ((filho + 1 < fim)  &&  (vetor[filho + 1] > vetor[filho]))
              filho++;
          if (vetor[filho] > t) {
             vetor[pai] = vetor[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      vetor[pai] = t;
   }
}
//---------------------------------------------------------------------------------------------------------//
int Vetor::buscaBinariaRecursiva(int elem, int inicio, int fim){
	int meio = 0;
	if(inicio>fim){
		return -1;
	}else{
		meio = (inicio+fim) / 2;
		if(elem==vetor[meio]){
			return meio;
		}else if(elem>vetor[meio]){
				buscaBinariaRecursiva(elem,meio+1,fim);
		}else{
			buscaBinariaRecursiva(elem,inicio,meio-1);
		}
	}
}

//---------------------------------------------------------------------------------------------------------//
int main(){
	Vetor f = Vetor();
	int op;
	int pos;
	int elem;
	clock_t t[2];

	while(op!=13){
		system("cls");
		printf("1	-	Criar um vetor com nuns aleatorios\n");
		printf("2	-	Exibe o conteudo do vetor\n");
		printf("3	-	Busca exaustiva\n");
		printf("4 	-	Ordem crescente Bolha\n");
		printf("5	-	Busca sequencial\n");
		printf("6	-	Busca Binaria\n");
		printf("7	-	Busca Binaria Recursiva\n");
		printf("8       -       Ordena decrescente\n");
		printf("9       -       Ordena Metodo da SELECAO\n");
		printf("10       -       Ordena Metodo INSERCAO DIRETA\n");
		printf("11	-	Ordena pelo Quick sorte\n");
		printf("12	-	Ordena pelo Heap Sort\n");
		printf("13	-	Sair\n");
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
					printf("Insira o elemento que seja buscar");
					scanf("%d",&elem);
					int posicao = f.buscaBinariaRecursiva(elem,0,TF-1);
					printf("\nEncontrou o elemento na posicao: %d",posicao);
					break;
				}

                case 8:{

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

                case 9:{
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

                case 10:{
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

				case 11:{
					t[0]=clock();
					f.startQuick();
					t[1]=clock();
					printf("\nOrdenados\n");
					float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;
				}
				case 12:{
					t[0]=clock();
					f.startHeap();
					t[1]=clock();
					printf("\nOrdenados\n");
					float diff = (t[1] - t[0])  / CLOCKS_PER_SEC;
                    printf("\nTempo = %f | Vetor de %d posicoes\n",diff ,TF);
					system("pause");
					system("cls");
					break;
					break;
				}

				case 13:{
					system("cls");
					printf("\n			Programa finalizado!!\n\n");
					break;
				}

			}

	}


	system("pause");
	return 0;
}

