#include <stdio.h>
#include <string.h>

main(){
	FILE *arq=fopen("notas.txt","r");
	if(arq == NULL){
		printf("Erro no arquivo - Não encontrado");
		}else{
		
			int i;
			char nome[15];
			float nota1,nota2,nota3;
			
			while(!feof(arq)){
				fscanf(arq,"%s %f %f %f",nome, &nota1, &nota2, &nota3);
				float media  = (nota1 + nota2 + nota3) / 3;
				printf("%s teve como media : %.2f\n",nome,media);
			}
			
		fclose(arq);
		}
getchar();
}
