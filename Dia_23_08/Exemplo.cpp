#include    <stdio.h>
#include    <string.h>
#include    <stdlib.h>
#include    <conio.h>

int dsemana(int, int , int);

int main(){
        static char *diasemana[7]=
{       "Domingo",
        "Segunda-feira",
        "Terça-feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sabado"
};

   int dia, mes, ano;
   const char ESC = 27;
   do{
    printf("Digite a data na forma dd mm aaaa: ");
    scanf("%d%d%d", &dia, &mes, &ano);
    printf("%s\n", diasemana[ dsemana(dia,mes,ano)]);
    printf("ESC para sair ou Enter para recomecar");
   }    while(getch()!= ESC);

    system("Pause");
    return 0;
}

