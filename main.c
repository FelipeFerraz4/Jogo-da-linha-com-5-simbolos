#include <stdio.h>
#include "Tabuleiro.h"

int main()
{
    //definindo tamanho das linhas e colunas.
    int linhas = (9*2)+2, colunas = (9*2)+2;
    //criando o tabuleiro.
    char tabuleiro[linhas][colunas];//criando matriz tabuleiro
    tabuleiro_inicial(linhas, colunas, tabuleiro);//preenchendo as configurações padrões do tabuleiro

    //apresentando o tabuleiro
    tabuleiro_imprimir(linhas,colunas,tabuleiro);
    return 0;
}
