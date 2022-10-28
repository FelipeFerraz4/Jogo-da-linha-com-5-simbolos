#include <stdio.h>

int pecas_do_tabuleiro(int linhas, int colunas,char matriz[linhas][colunas],
                    int inicio_i,int inicio_j,int fim_i,int fim_j,char dif_simbolo);

//fun��o para gravar o status inicial da tabela
int tabuleiro_inicial(int linhas, int colunas, char tabuleiro[linhas][colunas])
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
            // linha de separa��o / linha do meio / linha do espa�o vazio
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
            //linha com os s�mbolos
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

    //adi��o das pe�as no tabuleiro
    pecas_do_tabuleiro(linhas,colunas,tabuleiro,1,2,3,6,'X'); //adi��o das pe�as X
    pecas_do_tabuleiro(linhas,colunas,tabuleiro,15,16,17,18,'O');//adi��o das pe�as O

    return 0;
}

//Essa fun��o adiciona as pe�as no tabuleiro
int pecas_do_tabuleiro(int linhas, int colunas,char matriz[linhas][colunas],
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


//fun��o para imprimir o tabuleiro
int imprimindo_tabuleiro(int linhas, int colunas,char tabuleiro[linhas][colunas])
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
