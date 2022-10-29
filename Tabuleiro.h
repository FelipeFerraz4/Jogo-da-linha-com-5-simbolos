#include <stdio.h>

int tabuleiro_pecas(int linhas, int colunas,char matriz[linhas][colunas],
                    int inicio_i,int inicio_j,int fim_i,int fim_j,char dif_simbolo);

int tabuleiro_vazio (int linhas, int colunas, char tabuleiro[linhas][colunas]);

//função para gravar o status inicial da tabela
int tabuleiro_inicial(int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    //criação do tabuleiro
    tabuleiro_vazio(linhas, colunas, tabuleiro);

    //adição das peças no tabuleiro
    tabuleiro_pecas(linhas,colunas,tabuleiro,1,2,3,6,'X'); //adição das peças X
    tabuleiro_pecas(linhas,colunas,tabuleiro,15,16,17,18,'O');//adição das peças O

    return 0;
}

int tabuleiro_vazio (int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    int i, j;
    char letras = 'A', numero = '1';

    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            //primeira linha do tabuleiro
            if(i==0)
            {
                if (j==0)
                {
                    tabuleiro[i][j] = ' ';
                }
                else if(j%2!=0)
                {
                    tabuleiro[i][j] = ' ';
                }
                else
                {
                    tabuleiro[i][j] = '_';
                }
            }
            // linha de separação / linha do meio / linha do espaço vazio
            else if(i%2==0)
            {
                if (j==0)
                {
                    tabuleiro[i][j] = ' ';
                }
                else if(j%2!=0)
                {
                    tabuleiro[i][j] = '|';
                }
                else
                {
                    tabuleiro[i][j] = '_';
                }
            }
            //linha das letras
            else if(i==(linhas-1))
            {
                if (j==0)
                {
                    tabuleiro[i][j] = ' ';
                }
                else if(j%2!=0)
                {
                    tabuleiro[i][j] = ' ';
                }
                else
                {
                    tabuleiro[i][j] = letras;
                    letras++;
                }
            }
            //linha com os símbolos
            else
            {
                if (j==0)
                {
                    tabuleiro[i][j] = numero;
                    numero++;
                }
                else if(j%2!=0)
                {
                    tabuleiro[i][j] = '|';
                }
                else
                {
                    tabuleiro[i][j] = ' ';
                }
            }
        }
    }

    return 0;
}

//Essa função adiciona as peças no tabuleiro
int tabuleiro_pecas(int linhas, int colunas,char matriz[linhas][colunas],
                    int inicio_i,int inicio_j,int fim_i,int fim_j,char dif_simbolo)
{
    int i,j;
    for(i=inicio_i;i<=fim_i;i+=2)
    {
        for(j=inicio_j;j<=fim_j;j+=2)
        {
            if(dif_simbolo=='X') matriz[i][j] = 'X';
            else matriz[i][j] = 'O';
        }
        if(dif_simbolo=='X') fim_j-=2;
        else inicio_j-=2;
    }
    return 0;
}


//função para imprimir o tabuleiro
int tabuleiro_imprimir(int linhas, int colunas,char tabuleiro[linhas][colunas])
{
    int i,j;

    printf("O Tabuleiro do jogo: \n\n");
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            printf("%c", tabuleiro[i][j]);
            setbuf(stdin,NULL);
        }
        printf("\n");
    }
    return 0;
}
