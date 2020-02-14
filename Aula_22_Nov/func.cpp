#include "biblioteca.h"

//----------------------------------------------------------------------------------------------/
    indexado::indexado()//Construtor
    {
        tl = 0;
        int i = 0;
        while (i<40)
        {
            vetindice[i].chave = 0;
            vetindice[i].posaquivo = -1;
            i++;
        }
    }
//----------------------------------------------------------------------------------------------/
    void indexado::constroindice()
    {
        dados m;
        FILE *arq = fopen("material.dat","rb");
        if(arq == NULL)
        {
            printf("ERRO -- Arquivo nao existe!!");
        }else
        {
            tl = 0;
            fread(&m,sizeof(dados),1,arq);
            while (!feof(arq))
            {
                vetindice[tl].chave = m.cod;
                vetindice[tl].posaquivo = tl;
                tl++;
                fread(&m,sizeof(dados),1,arq);
            }
            fclose(arq);
        } 

        //APLICAR O METODO BOLHA NO INDICE
        int i = 0;
        int fim  = tl -1;
        while(fim > 0)
        {
            while(i<fim)
            {
                if(vetindice[i].chave > vetindice[i+1].chave)
                {
                    tabela aux = vetindice[i];
                    vetindice[i] = vetindice[i+1];
                    vetindice[i+1] = aux;
                    i++;
                }
            }    
            fim--;
        }
    }
//----------------------------------------------------------------------------------------------/
    dados indexado::lemateria()
    {
        dados m;
        printf("Entre com o codigo do produto: ");
        scanf("%d",&m.cod);

        printf("\nEntre com a especificacao do produto: ");
        fflush(stdin);
        gets(m.nome);
        
        printf("Entre com o estoque minimo: ");
        scanf("%d",&m.min);

        printf("Entre com o estoque atual: ");
        scanf("%d",&m.estoque);

        return m;
    }
//----------------------------------------------------------------------------------------------/
    //-----EXIBIR-----//
    void indexado::exibe_um(dados m)
    {
        printf("\nCodigo: %d -- Nome: %s -- Est.Minimo: %d -- QtdEstoque: %d",m.cod,m.nome,m.min,m.estoque);
        printf("\n|--------------------------------------------------------|\n");
    }
//----------------------------------------------------------------------------------------------/
    void indexado::exibeindice()
    {
        int i = 0;
        printf("\n              Indice Ordenado\n\n");
        while(i<tl)
        {
            printf("i = %d -- Chave: %d -- Posdado: %d",i,vetindice[i].chave,vetindice[i].posaquivo);
            i++;
        }
    }
//----------------------------------------------------------------------------------------------/
    void indexado::exibeordenado()
    {
        int i = 0, posdado;
        dados m;
        FILE *arq = fopen("material.dat","rb");
        if(arq == NULL)
        {
             printf("ERRO -- Arquivo nao existe!!");
        }else
        {
            printf("\n\nRelatorio Ordenado, TL = %d \n",tl);
            while(i<tl)
            {
                posdado = vetindice[i].posaquivo;
                fseek(arq,posdado*sizeof(dados),SEEK_SET);
                fread(&m,sizeof(dados),1,arq);
                printf("\nNo vetor indice chave: %d, posdado: %d",vetindice[i].chave,vetindice[i].posaquivo);
                exibe_um(m);
                i++;
            }
            fclose(arq);
        }
    }
//----------------------------------------------------------------------------------------------/    
    void indexado::exibedesordenado()
    {
        dados m;
        FILE *arq = fopen("material.dat","rb");
        if(arq==NULL)
        {
            printf("ERRO -- Arquivo nao existe!!");
        }else
        {
            fread(&m,sizeof(dados),1,arq);
            while(!feof(arq))
            {
                exibe_um(m);
                fread(&m,sizeof(dados),1,arq);
            }
            fclose(arq);
        }
        
    }
//----------------------------------------------------------------------------------------------/    
    //-----INSERIR-----//
    void indexado::insere()
    {
         dados m = lemateria();
         int i, posideal;
            FILE *arq = fopen("material.dat","rb");
            if(arq == NULL)
            {
                arq = fopen("material.dat","wb");
            }else{
                arq = fopen("material.dat","ab");
            }
            fseek(arq,sizeof(dados),SEEK_END);
            fwrite(&m,sizeof(dados),1,arq);

        if(tl == 0)
        {
            posideal = 0;
        }else
            {
                posideal = buscabinaria(m.cod);
            }
        
        if(posideal < tl)
        {
            i = tl;
            while(i>posideal)
            {
                vetindice[i] = vetindice[i-1];
                i--;
            }
        }

        vetindice[posideal].chave = m.cod;
        vetindice[posideal].posaquivo = tl;
        tl++; 
        fclose(arq);

        printf("\n\nExibe o Indice: ");
        exibeindice();
    }
//----------------------------------------------------------------------------------------------/    
    //-----Consulta-Busca-----//
    void indexado::consulta(int cod)
    {
        int  posdado, posindice;
        dados m;
        FILE *arq = fopen("material.dat","rb");
        if(arq == NULL)
        {
            printf("ERRO -- Arquivo nao existe!!");
        }else
        {
            posindice = buscabinaria(cod);   
            if((vetindice[posindice].chave == cod) && (tl>0))
            {
                posdado = vetindice[posindice].posaquivo;
                fseek(arq,posdado*sizeof(dados),SEEK_SET);
                fread(&m,sizeof(dados),1,arq);
                exibe_um(m);
            }
            fclose(arq);
        }   
    }
//----------------------------------------------------------------------------------------------/    
    int indexado::buscabinaria(int num)
    {
        int inicio = 0;
        int fim = tl -1;
        int meio = (inicio + fim) / 2;

            while ((inicio<fim) && (num != vetindice[meio].chave))
            {
                if(num > vetindice[meio].chave)
                {
                    inicio = meio +1;
                }else
                {
                    fim = meio;
                }
                meio = (inicio + fim) / 2;
            }
            if(num>vetindice[meio].chave)
            {
                return meio +1;
            }else
            {
                return meio;
            }
            
    }
//----------------------------------------------------------------------------------------------/    

