#include <stdio.h>
#include <ctype.h>

int posicao_vazia(char posicao[2], int linhas, int colunas, char tabuleiro[linhas][colunas]);
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

int posicao(char posicao[2], int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    int valida;
    do
    {
        valida = 0;
        printf("Digite uma posicao, exemplo '1A'; \n");
        scanf("%s", posicao);
        setbuf(stdin,NULL);
        posicao[1] = toupper(posicao[1]);
        valida += posicao_existe(posicao);
        valida += posicao_vazia(posicao,linhas,colunas,tabuleiro);
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
    posicao(posicao_atual,linhas,colunas,tabuleiro);
    printf("%s\n", posicao_atual);
//    posicao(posicao_nova,linhas,colunas,tabuleiro);
//    printf("%s\n", posicao_nova);
    return 1;
}

int tabuleiro_jogo()
{
    int fim_do_jogo;
    //definindo tamanho das linhas e colunas.
    int linhas = (9*2)+2, colunas = (9*2)+2;
    //criando o tabuleiro.
    char tabuleiro[linhas][colunas];//criando matriz tabuleiro
    tabuleiro_inicial(linhas, colunas, tabuleiro);//preenchendo as configurações padrões do tabuleiro

    do
    {
        //apresentando o tabuleiro
        tabuleiro_imprimir(linhas,colunas,tabuleiro);
        tabuleiro_movimento(linhas,colunas,tabuleiro);
        tabuleiro_imprimir(linhas,colunas,tabuleiro);
        fim_do_jogo = 1;
    }while(fim_do_jogo!=1);

    return 0;
}
