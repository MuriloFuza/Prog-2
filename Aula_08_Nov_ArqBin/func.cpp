#include "biblioteca.h"

Binario::Binario(){}

conta Binario::lecliente()
{
    conta c;
    printf("\nEntre com o numero da conta: ");
    scanf("%d",&c.num);
    do{
        printf("Entre com tipo da conta: "); 
        c.tipo = getche();
    }while (!(c.tipo == 'c' || c.tipo == 'e'));

    printf("\nEntre com um nome: ");
    fflush(stdin);
    gets(c.nome);

    if(c.tipo == 'c'){
        c.limite = 0;
    }
    else
    {
        printf("Entre com o Limite: ");
        scanf("%f",&c.limite);
    }
    

    printf("Entre com o saldo: ");
    scanf("%f",&c.saldo);

    return c;
}

void Binario::insere()
{
   conta c = lecliente();
   FILE *arq;
    arq = fopen("cliente.dat","rb");
   if(arq == NULL)
   {
       arq = fopen("cliente.dat","wb");
   }else{
       arq = fopen("cliente.dat","ab");
   }
   fwrite(&c,sizeof(conta),1,arq);
   fclose(arq);
}

void Binario::exibeum(conta c)
{
    printf("\n");
    printf("Num: %d --Nome: %s   --Tipo: %c --Limite: %5.2f  --Saldo: %5.2f",c.num,c.nome,c.tipo,c.limite,c.saldo);
}

void Binario::exibe()
{
    conta c;
    FILE *arq;
    arq = fopen("cliente.dat","rb");
    if(arq == NULL)
        printf("\n Arquivo nao existe!");
    else{
        fread(&c, sizeof(conta),1,arq);
        while(!feof(arq))
        {
            exibeum(c);     
            fread(&c, sizeof(conta),1,arq);       
        }
        fclose(arq);
    }
}

void Binario::busca(int num)
{
    conta c;
    FILE *arq;
    arq = fopen("cliente.dat","rb");
    if(arq == NULL)
        printf("Arquivo nao existe ou NULL");
    else
    {
        fread(&c, sizeof(conta),1,arq);
        while((num != c.num) && (!feof(arq)))
        {
             fread(&c, sizeof(conta),1,arq);
        }
        if(num == c.num)
        {
            exibeum(c);    
        }else{
            printf("Nao encontrado!");
        }
    }
}