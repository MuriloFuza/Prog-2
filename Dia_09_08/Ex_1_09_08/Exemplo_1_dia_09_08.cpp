#include <stdio.h>
#include <string.h>

main(){
	FILE *f=fopen("teste.txt","w");
	int i;

	for(i = 1;i<=10;i++){
		fprintf(f,"%d \n",i);
	}
		fclose(f);
		printf("Endereco %p",i);
	printf("Feito!");
return 0;
}
