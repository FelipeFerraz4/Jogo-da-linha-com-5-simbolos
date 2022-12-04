#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h> //cor

int tabuleiro_linha(char linha);
int tabuleiro_coluna(char coluna);
int tabuleiro_pecas(int linhas, int colunas,char matriz[linhas][colunas],char simbolo);

int tabuleiro_vazio (int linhas, int colunas, char tabuleiro[linhas][colunas]);

//função para gravar o status inicial da tabela
int tabuleiro_inicial(int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    //criação do tabuleiro
    tabuleiro_vazio(linhas, colunas, tabuleiro);

    //adição das peças no tabuleiro
    tabuleiro_pecas(linhas,colunas,tabuleiro,'X'); //adição das peças X
    tabuleiro_pecas(linhas,colunas,tabuleiro,'O');//adição das peças O

    return 0;
}

//cria um tabuleiro vazio
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

int posicao_vazia(char posicao[2], int linhas, int colunas, char tabuleiro[linhas][colunas])
{
    int linha = tabuleiro_linha(posicao[0]), coluna = tabuleiro_coluna(posicao[1]);
    if(tabuleiro[linha][coluna]==' ')
        return 0;
    else
        return 1;
}

//Essa função adiciona as peças no tabuleiro de forma aleatória
int tabuleiro_pecas(int linhas, int colunas,char matriz[linhas][colunas],char simbolo)
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
            int linha = tabuleiro_linha(coordenadas[0]);
            int coluna = tabuleiro_coluna(coordenadas[1]);
            matriz[linha][coluna] = simbolo;
            cont++;
        }
    }while(cont<5);
    return 0;
}

//função para imprimir o tabuleiro
int exibeTabuleiro(int linhas, int colunas,char tabuleiro[linhas][colunas])
{
    int i,j;

    printf("O Tabuleiro do jogo: \n\n");
    for(i=0;i<linhas;i++)
    {
        for(j=0;j<colunas;j++)
        {
            if(tabuleiro[i][j]=='x')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10 /*cor*/);
                printf("%c", tabuleiro[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 /*cor*/);
            }
            else if(tabuleiro[i][j]=='o')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3 /*cor*/);
                printf("%c", tabuleiro[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 /*cor*/);
            }
            else
            {
                printf("%c", tabuleiro[i][j]);
            }
            setbuf(stdin,NULL);
        }
        printf("\n");
    }
    return 0;
}

//verifica se a posição existe
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

char naCasa(char posicao[2], int linhas, int colunas, char tabuleiro[linhas][colunas], char simbolo)
{
    int linha = tabuleiro_linha(posicao[0]), coluna = tabuleiro_coluna(posicao[1]);
    if(tabuleiro[linha][coluna]==' ')
        return ' ';
    else if (tabuleiro[linha][coluna]=='X')
        return 'X';
    else if (tabuleiro[linha][coluna]=='O')
        return 'O';
    else
        return '1';
}

int validaPeca(char posicao[2], int linhas, int colunas,char tabuleiro[linhas][colunas],char simbolo)
{
    int valida = 0;
    char valor;

    //verifica se a posição digita existe no tabuleiro
    valida += posicao_existe(posicao);

    if(valida==1)
    {
        //verifica se na posição é valida, no sentido de ter a peça adequada ou ser ela tá vazia
        valor = naCasa(posicao,linhas,colunas,tabuleiro,simbolo);
        if(simbolo==valor)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}

int tabuleiro_linha(char linha)
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

int tabuleiro_coluna(char coluna)
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

int receber_posicao(char posicao[2], char simbolo)
{
        if(simbolo!=' ')
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
    return 0;
}

int validaMovimento(int linha_atual,int coluna_atual, char posicao[2],
                    int linhas,int colunas,char tabuleiro[linhas][colunas])
{
    int linha_nova, coluna_nova,i,j;
    linha_nova = tabuleiro_linha(posicao[0]);
    coluna_nova = tabuleiro_coluna(posicao[1]);
    if(linha_atual==linha_nova)
    {
        if(coluna_atual>coluna_nova)
        {
            for(i=coluna_atual-2;i>=coluna_nova;i-=2)
            {
                if(tabuleiro[linha_atual][i]=='X'||tabuleiro[linha_atual][i]=='O')
                    return 0;
            }
        }
        else
        {
            for(i=coluna_atual+2;i<=coluna_nova;i+=2)
            {
                if(tabuleiro[linha_atual][i]=='X'||tabuleiro[linha_atual][i]=='O')
                    return 0;
            }
        }
        return 1;
    }
    else if(coluna_atual==coluna_nova)
    {
        if(linha_atual>linha_nova)
        {
            for(i=linha_atual-2;i>=linha_nova;i-=2)
            {
                if(tabuleiro[i][coluna_atual]=='X'||tabuleiro[i][coluna_atual]=='O')
                    return 0;
            }
        }
        else
        {
            for(i=linha_atual+2;i<=linha_nova;i+=2)
            {
                if(tabuleiro[i][coluna_atual]=='X'||tabuleiro[i][coluna_atual]=='O')
                    return 0;
            }
        }
        return 1;
    }
    else
    {
        if(linha_atual>linha_nova)
        {
            if(coluna_atual>coluna_nova)
            {
                for(i=linha_atual-2,j=coluna_atual-2;i>=linha_nova;i-=2,j-=2)
                {
                    if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O') return 0;
                    if(linha_nova==i&&coluna_nova==j) return 1;
                }

            }
            else
            {
                for(i=linha_atual-2,j=coluna_atual+2;i>=linha_nova;i-=2,j+=2)
                {
                    if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O') return 0;
                    if(linha_nova==i&&coluna_nova==j) return 1;
                }

            }
        }
        else
        {
            if(coluna_atual<coluna_nova)
            {
                for(i=linha_atual+2,j=coluna_atual+2;i<=linha_nova;i+=2,j+=2)
                {
                    if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O') return 0;
                    if(linha_nova==i&&coluna_nova==j) return 1;
                }

            }
            else
            {
                for(i=linha_atual+2,j=coluna_atual-2;i<=linha_nova;i+=2,j-=2)
                {
                    if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O') return 0;
                    if(linha_nova==i&&coluna_nova==j) return 1;
                }

            }
        }
    }
    return 0;
}

int verificaConversao(int linhas,int colunas,char tabuleiro[linhas][colunas],
                      int linha_atual,int coluna_atual,int linha_nova,int coluna_nova)
{
    int i,j;
    if(linha_atual==linha_nova)
    {
        if(coluna_atual>coluna_nova)
        {
            for(j=coluna_atual-2;j>=coluna_nova;j-=2)
            {
                if(tabuleiro[linha_atual][j]=='x') tabuleiro[linha_atual][j]='o';
                else if(tabuleiro[linha_atual][j]=='o') tabuleiro[linha_atual][j]='x';
            }
        }
        else
        {
            for(j=coluna_atual+2;j<=coluna_nova;j+=2)
            {
                if(tabuleiro[linha_atual][j]=='x') tabuleiro[linha_atual][j]='o';
                else if(tabuleiro[linha_atual][j]=='o') tabuleiro[linha_atual][j]='x';
            }
        }
        return 1;
    }
    else if(coluna_atual==coluna_nova)
    {
        if(linha_atual>linha_nova)
        {
            for(i=linha_atual-2;i>=linha_nova;i-=2)
            {
                if(tabuleiro[i][coluna_atual]=='x') tabuleiro[i][coluna_atual]='o';
                else if(tabuleiro[i][coluna_atual]=='o') tabuleiro[i][coluna_atual]='x';
            }
        }
        else
        {
            for(i=linha_atual+2;i<=linha_nova;i+=2)
            {
                if(tabuleiro[i][coluna_atual]=='x') tabuleiro[i][coluna_atual]='o';
                else if(tabuleiro[i][coluna_atual]=='o') tabuleiro[i][coluna_atual]='x';
            }
        }
        return 1;
    }
    else
    {
        //subindo na diagonal(baixo para cima)
        if(linha_atual>linha_nova)
        {
            if(coluna_atual>coluna_nova)
            {
                //diagonal principal
                for(i=linha_atual-2,j=coluna_atual-2;i>=linha_nova;i-=2,j-=2)
                {
                    if(tabuleiro[i][j]=='x') tabuleiro[i][j]='o';
                    else if(tabuleiro[i][j]=='o') tabuleiro[i][j]='x';
                }

            }
            else
            {
                //diagonal secundaria
                for(i=linha_atual-2,j=coluna_atual+2;i>=linha_nova;i-=2,j+=2)
                {
                    if(tabuleiro[i][j]=='x') tabuleiro[i][j]='o';
                    else if(tabuleiro[i][j]=='o') tabuleiro[i][j]='x';
                }

            }
        }//descendo na diagonal(cima para baixo)
        else
        {
            if(coluna_atual<coluna_nova)
            {
                //diagonal principal
                for(i=linha_atual+2,j=coluna_atual+2;i<=linha_nova;i+=2,j+=2)
                {
                    if(tabuleiro[i][j]=='x') tabuleiro[i][j]='o';
                    else if(tabuleiro[i][j]=='o') tabuleiro[i][j]='x';
                }

            }
            else
            {
                //diagonal secundaria
                for(i=linha_atual+2,j=coluna_atual-2;i<=linha_nova;i+=2,j-=2)
                {
                    if(tabuleiro[i][j]=='x') tabuleiro[i][j]='o';
                    else if(tabuleiro[i][j]=='o') tabuleiro[i][j]='x';
                }

            }
        }
    }
    return 0;
}

int pecaPodeMover(int linha_peca,int coluna_peca,int linhas,int colunas,char tabuleiro[linhas][colunas])
{
    int i,j;

    //horizontal
    i = linha_peca;

    //x-direita
    for(j=coluna_peca+2;j<=18;j+=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }
    //x-esquerda
    for(j=coluna_peca-2;j>=2;j-=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }

    //vertical
    j = coluna_peca;

    //y-cima
    for(i=linha_peca-2;i>=1;i-=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }
    //y-baixo
    for(i=linha_peca+2;i<=17;i+=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }

    //diagonal principal - subindo
    for(i=linha_peca-2,j=coluna_peca-2;i>=1&&j>=2;i-=2,j-=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }
    //diagonal principal - descendo
    for(i=linha_peca+2,j=coluna_peca+2;i<=17&&j<=18;i+=2,j+=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }

    //diagonal secundaria - subindo
    for(i=linha_peca-2,j=coluna_peca+2;i>=1&&j<=18;i-=2,j+=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }
    //diagonal sencundaria - descendo
    for(i=linha_peca+2,j=coluna_peca-2;i<=17&&j>=2;i+=2,j-=2)
    {
        if(tabuleiro[i][j]=='X'||tabuleiro[i][j]=='O')
        {
            break;
        }
        else if(tabuleiro[i][j]==' ')
        {
            return 0;
        }
        else continue;
    }
    return 1;
}

int tabuleiro_movimento(int linhas, int colunas, char tabuleiro[linhas][colunas],
                        char simbolo)
{
    int linha_atual,coluna_atual,linha_nova,coluna_nova,valida = 0;
    char posicao_atual[2] = "00", posicao_nova[2];

    //mostra de que é a vez
    printf("Rodada do simbolo: %c\n", simbolo);

    //pegar a posição da peca valida
    do
    {
        receber_posicao(posicao_atual,simbolo);
        valida += validaPeca(posicao_atual,linhas,colunas,tabuleiro,simbolo);
        if(1==pecaPodeMover(tabuleiro_linha(posicao_atual[0]),tabuleiro_coluna(posicao_atual[1]),linhas,colunas,tabuleiro))
        {
            valida = 0;
        }
        if (valida==0) printf("Posicao informada invalida !\n\n");
    }while(valida==0);
    valida = 0;

    //armazena a linha e coluna da posição em um int
    linha_atual = tabuleiro_linha(posicao_atual[0]);
    coluna_atual = tabuleiro_coluna(posicao_atual[1]);

    //pegar uma nova posicao da peça valida
    do
    {
        receber_posicao(posicao_nova,' ');
        valida = validaPeca(posicao_nova,linhas,colunas,tabuleiro,' ');
        valida += validaMovimento(linha_atual,coluna_atual,posicao_nova,linhas,colunas,tabuleiro);
        if (valida!=2) printf("Posicao informada invalida !\n\n");
    }while(valida!=2);

    //armazena a linha e coluna da posição em um int
    linha_nova = tabuleiro_linha(posicao_nova[0]);
    coluna_nova = tabuleiro_coluna(posicao_nova[1]);

    //a troca de posição das peças
    verificaConversao(linhas,colunas,tabuleiro,linha_atual,coluna_atual,linha_nova,coluna_nova);
    tabuleiro[linha_nova][coluna_nova] = simbolo;
    simbolo = tolower(simbolo);
    tabuleiro[linha_atual][coluna_atual] = simbolo;

    return 1;
}

int vitoriaLinha(int linhas, int colunas, char tabuleiro[linhas][colunas], char simbolo)
{
    int cont = 0,i,j,inicio_j,fim_j;
    for(i=1;i<=17;i+=2)
    {
        for(inicio_j = 2,fim_j = 10 ; inicio_j <= 10/*,fim_j<= 18*/ ; inicio_j+=2,fim_j+=2)
        {
            for(j=inicio_j;j<=fim_j;j+=2)
            {
                if(tabuleiro[i][j]==simbolo || tabuleiro[i][j]==toupper(simbolo))
                {
                    cont++;
                }
            }
            if(cont==5)
            {
                return 1;
            }
            else
            {
                cont = 0;
            }
        }
    }
    return 0;
}

int vitoriaColuna(int linhas, int colunas, char tabuleiro[linhas][colunas], char simbolo)
{
    int cont = 0, i,j, inicio_i,fim_i;
    for(j=2;j<=18;j+=2)
    {
        for(inicio_i = 1,fim_i = 9 ; inicio_i <= 9 /*, fim_i = 17*/; inicio_i+=2,fim_i+=2)
        {
            for(i=inicio_i;i<=fim_i;i+=2)
            {
                if(tabuleiro[i][j]==simbolo || tabuleiro[i][j]==toupper(simbolo))
                {
                    cont++;
                }
            }
            if(cont==5)
            {
                return 1;
            }
            else
            {
                cont = 0;
            }
        }
    }
    return 0;
}

int vitoriaDPrincipal(int linhas, int colunas, char tabuleiro[linhas][colunas], char simbolo)
{
    int cont = 0, i,j, inicio_i,inicio_j,modInicio_j,modInicio_i,inicio_cond,modCond, modInicioCond;

    for(modInicio_j = 2,modCond = 17 ; modInicio_j <= 10 ; modInicio_j+=2,modCond-=2)
    {
        for(inicio_i = 1,inicio_j = modInicio_j ,inicio_cond = 9 ; inicio_cond <= modCond ; inicio_cond+=2,inicio_i+=2,inicio_j+=2)
        {
            for(i=inicio_i,j=inicio_j ; i<=inicio_cond ; i+=2,j+=2)
            {
                if(tabuleiro[i][j]==simbolo || tabuleiro[i][j]==toupper(simbolo))
                {
                    cont++;
                }
            }
            if(cont==5)
            {
                return 1;
            }
            else
            {
                cont = 0;
            }
        }

    }

    for(modInicio_i = 1,modInicioCond = 9 ; modInicio_i <= 9 ; modInicio_i+=2,modInicioCond+=2)
    {
        for(inicio_i = modInicio_i,inicio_j = 2,inicio_cond = modInicioCond ; inicio_cond <= 17; inicio_cond+=2,inicio_i+=2,inicio_j+=2)
        {
            for(i=inicio_i,j=inicio_j ; i<=inicio_cond ; i+=2,j+=2)
            {
                if(tabuleiro[i][j]==simbolo || tabuleiro[i][j]==toupper(simbolo))
                {
                    cont++;
                }
            }
            if(cont==5)
            {
                return 1;
            }
            else
            {
                cont = 0;
            }
        }

    }

    return 0;
}

int vitoriaDSecundaria(int linhas, int colunas, char tabuleiro[linhas][colunas], char simbolo)
{
    int cont = 0, i,j, inicio_i,inicio_j,modInicio_j,modInicio_i,inicio_cond,modCond, modInicioCond;

    for(modInicio_j = 10, modCond = 9 ; modCond <= 17 ; modInicio_j+=2,modCond+=2)
    {
        for(inicio_i = 1,inicio_j = modInicio_j,inicio_cond = 9 ; inicio_cond <= modCond ; inicio_i+=2,inicio_j-=2,inicio_cond+=2)
        {
            for(i=inicio_i,j=inicio_j ; i<=inicio_cond ; i+=2,j-=2)
                {
                    if(tabuleiro[i][j]==simbolo || tabuleiro[i][j]==toupper(simbolo))
                    {
                        cont++;
                    }
                }
                if(cont==5)
                {
                    return 1;
                }
                else
                {
                    cont = 0;
                }
        }

    }

    for(modInicio_i = 1,modInicioCond = 9 ; modInicioCond <= 17 ; modInicio_i+=2,modInicioCond+=2)
    {
        for(inicio_i = modInicio_i,inicio_j = 18,inicio_cond = modInicioCond ; inicio_cond <= 17 ; inicio_i+=2,inicio_j-=2,inicio_cond+=2)
        {
            for(i=inicio_i,j=inicio_j ; i<=inicio_cond ; i+=2,j-=2)
                {
                    if(tabuleiro[i][j]==simbolo || tabuleiro[i][j]==toupper(simbolo))
                    {
                        cont++;
                    }
                }
                if(cont==5)
                {
                    return 1;
                }
                else
                {
                    cont = 0;
                }
        }

    }

    return 0;
}

int vitoriaSemMovimento(int linhas,int colunas,char tabuleiro[linhas][colunas],char simbolo)
{
    int i,j,cont=0;
    simbolo = toupper(simbolo);

    for(i=1;i<=17;i+=2)
    {
        for(j=2;j<=18;j+=2)
        {
            if(tabuleiro[i][j]==simbolo)
            {
                cont += pecaPodeMover(i,j,linhas,colunas,tabuleiro);
            }
        }
    }

    if(cont==5)
    {
        return 1;
    }

    return 0;
}

int verificaVitoria(int linhas, int colunas, char tabuleiro[linhas][colunas], char simbolo)
{
    int vitoria = 0;

    vitoria = vitoriaLinha(linhas,colunas,tabuleiro,simbolo);
    if(vitoria==1) return 1;
    vitoria = vitoriaColuna(linhas,colunas,tabuleiro,simbolo);
    if(vitoria==1) return 1;
    vitoria = vitoriaDPrincipal(linhas,colunas,tabuleiro,simbolo);
    if(vitoria==1) return 1;
    vitoria = vitoriaDSecundaria(linhas,colunas,tabuleiro,simbolo);
    if(vitoria==1) return 1;
    vitoria = vitoriaSemMovimento(linhas,colunas,tabuleiro,simbolo);
    if(vitoria==1) return 1;

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
    int fim_do_jogo = 0, rodada = 0;
    //definindo tamanho das linhas e colunas
    int linhas = (9*2)+2, colunas = (9*2)+2;
    //criando o tabuleiro
    char tabuleiro[linhas][colunas],simbolo_vencedor;//criando matriz tabuleiro
    do
    {
        tabuleiro_inicial(linhas, colunas, tabuleiro);//preenchendo as configurações padrões do tabuleiro
        fim_do_jogo += verificaVitoria(linhas,colunas,tabuleiro,'x');
        fim_do_jogo += verificaVitoria(linhas,colunas,tabuleiro,'o');
    }while(fim_do_jogo!=0);


    //apresentando o tabuleiro
    exibeTabuleiro(linhas,colunas,tabuleiro);

    int vencedor=0;

    do
    {
        if(rodada%2==0)
        {
            tabuleiro_movimento(linhas,colunas,tabuleiro,'X');
            fim_do_jogo += verificaVitoria(linhas,colunas,tabuleiro,'x');
            if(fim_do_jogo==1)
            {
                simbolo_vencedor = 'x';
                vencedor++;
                fim_do_jogo = 0;
            }
            fim_do_jogo += verificaVitoria(linhas,colunas,tabuleiro,'o');
            if(fim_do_jogo==1)
            {
                simbolo_vencedor = 'o';
                vencedor++;
                fim_do_jogo = 0;
            }
        }
        else
        {
            tabuleiro_movimento(linhas,colunas,tabuleiro,'O');
            fim_do_jogo += verificaVitoria(linhas,colunas,tabuleiro,'o');
            if(fim_do_jogo==1)
            {
                simbolo_vencedor = 'o';
                vencedor++;
                fim_do_jogo = 0;
            }
            fim_do_jogo += verificaVitoria(linhas,colunas,tabuleiro,'x');
            if(fim_do_jogo==1)
            {
                simbolo_vencedor = 'x';
                vencedor++;
                fim_do_jogo = 0;
            }
        }
        exibeTabuleiro(linhas,colunas,tabuleiro);
        rodada++;
    }while(vencedor==0);
    if(vencedor==1)
    {
        if(simbolo_vencedor=='x') printf("Jogador do X venceu\n");
        else printf("Jogador do O venceu\n");
    }
    else printf("O jogo deu empate\n");

    return 0;
}
