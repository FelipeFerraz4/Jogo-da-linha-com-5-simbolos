#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int linha_tabuleiro(char linha);
int coluna_tabuleiro(char coluna);
int posicao_vazia(char posicao[2], int linhas, int colunas, char tabuleiro[linhas][colunas]);
int tabuleiro_pecas(int linhas, int colunas,char matriz[linhas][colunas],
                    char simbolo);

int tabuleiro_vazio (int linhas, int colunas, char tabuleiro[linhas][colunas]);

//fun��o para gravar o status inicial da tabela
int tabuleiro_inicial(int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    //cria��o do tabuleiro
    tabuleiro_vazio(linhas, colunas, tabuleiro);

    //adi��o das pe�as no tabuleiro
    tabuleiro_pecas(linhas,colunas,tabuleiro,'X'); //adi��o das pe�as X
    tabuleiro_pecas(linhas,colunas,tabuleiro,'O');//adi��o das pe�as O

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

    return 0;
}

//Essa fun��o adiciona as pe�as no tabuleiro de forma aleat�ria
int tabuleiro_pecas(int linhas, int colunas,char matriz[linhas][colunas],
                    char simbolo)
{
    int cont=0, resultado;
    char coordenadas[2];
    do
    {
        coordenadas[0] = (char) ((rand() % 9) + 49);//gera valores entre 49 e 57
        coordenadas[1] = (char) ((rand() % 9) + 65);//gera valores entre 65 e 73
        resultado = posicao_vazia(coordenadas, linhas, colunas, matriz);
        if(resultado==0)
        {
            int linha = linha_tabuleiro(coordenadas[0]);
            int coluna = coluna_tabuleiro(coordenadas[1]);
            matriz[linha][coluna] = simbolo;
            cont++;
        }
    }while(cont<5);
    return 0;
}

//fun��o para imprimir o tabuleiro
int exibeTabuleiro(int linhas, int colunas,char tabuleiro[linhas][colunas])
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

int posicao_existe(char posicao[2])
{
     //uso da tabela ASCII (49=1,57=9)linhas e (65=A,73=I)colunas
    if( (posicao[0]>=49 && posicao[0]<=57) && (posicao[1]>=65 && posicao[1]<=73))
    {
        if(posicao[2]!='\0') return 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

int validaPeca(char posicao[2], int linhas, int colunas,
            char tabuleiro[linhas][colunas],int ocupada)
{
    int valida;
    do
    {
        valida = 0;
        if(ocupada==1)
        {
            printf("Digite a posicao atual da peca, exemplo '1A': \n");
        }
        else
        {
            printf("Digite a nova posicao da peca, exemplo '1A': \n");
        }
        scanf("%s", posicao);
        setbuf(stdin,NULL);
        posicao[1] = toupper(posicao[1]);
        valida += posicao_existe(posicao);
        if(ocupada==1)
        {
            valida += posicao_vazia(posicao,linhas,colunas,tabuleiro);
        }
        else
        {
            valida += posicao_vazia(posicao,linhas,colunas,tabuleiro);
            valida++;
        }

        if(valida!=2)
        {
            printf("Posicao informada invalida !\n\n");
        }
    }while(valida!=2);
    return 0;
}

int linha_tabuleiro(char linha)
{
    switch(linha)
    {
        case '1':
            return 1;
        case '2':
            return 3;
        case '3':
            return 5;
        case '4':
            return 7;
        case '5':
            return 9;
        case '6':
            return 11;
        case '7':
            return 13;
        case '8':
            return 15;
        case '9':
            return 17;
        default:
            return 0;
    }
}

int coluna_tabuleiro(char coluna)
{
    switch(coluna)
    {
        case 'A':
            return 2;
        case 'B':
            return 4;
        case 'C':
            return 6;
        case 'D':
            return 8;
        case 'E':
            return 10;
        case 'F':
            return 12;
        case 'G':
            return 14;
        case 'H':
            return 16;
        case 'I':
            return 18;
        default:
            return 0;
    }
}

int posicao_vazia(char posicao[2], int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    int linha = linha_tabuleiro(posicao[0]), coluna = coluna_tabuleiro(posicao[1]);
    if(tabuleiro[linha][coluna]==' ')
        return 0;
    return 1;
}

int tabuleiro_movimento(int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    char posicao_atual[2], posicao_nova[2];
    validaPeca(posicao_atual,linhas,colunas,tabuleiro,1);
    printf("%s\n", posicao_atual);
    validaPeca(posicao_nova,linhas,colunas,tabuleiro,0);
    printf("%s\n", posicao_nova);
    return 1;
}

int verificaVitoria(int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    int vitoria = 0;

    vitoria = 1;

    if(vitoria==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int tabuleiro_jogo()
{
    int fim_do_jogo;
    //definindo tamanho das linhas e colunas.
    int linhas = (9*2)+2, colunas = (9*2)+2;
    //criando o tabuleiro.
    char tabuleiro[linhas][colunas];//criando matriz tabuleiro
    tabuleiro_inicial(linhas, colunas, tabuleiro);//preenchendo as configura��es padr�es do tabuleiro

    //apresentando o tabuleiro
    exibeTabuleiro(linhas,colunas,tabuleiro);

    do
    {
        tabuleiro_movimento(linhas,colunas,tabuleiro);
        exibeTabuleiro(linhas,colunas,tabuleiro);
        fim_do_jogo = verificaVitoria(linhas,colunas,tabuleiro);
    }while(fim_do_jogo!=1);

    return 0;
}
