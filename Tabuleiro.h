#include <stdio.h>

int tabuleiro_inicial(int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    int i, j;

    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            if(i==0)
            {
                if(j%2==0)
                {
                    tabuleiro[i][j] = ' ';
                }
                else
                {
                    tabuleiro[i][j] = '_';
                }
            }
            else if(i%2==0)
            {
                if(j%2==0)
                {
                    tabuleiro[i][j] = '|';
                }
                else
                {
                    tabuleiro[i][j] = '_';
                }
            }
            else
            {
                if(j%2==0)
                {
                    tabuleiro[i][j] = '|';
                }
                else
                {
                    tabuleiro[i][j] = 'O';
                }
            }
        }
    }
    return 0;
}

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
