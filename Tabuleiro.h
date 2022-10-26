#include <stdio.h>

//função para gravar o status inicial da tabela
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
                    tabuleiro[i][j] = 'O';
                }
            }
        }
    }
    return 0;
}


//função para imprimir o tabuleiro
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
