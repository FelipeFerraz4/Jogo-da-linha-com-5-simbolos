#include <stdio.h>
#include "Tabuleiro.h"

int main()
{
    //definindo tamanho das linhas e colunas.
    int linhas = (8*2)+1, colunas = (8*2)+1;
    //criando o tabuleiro.
    char tabuleiro[linhas][colunas];//criando matriz tabuleiro
    tabuleiro_inicial(linhas, colunas, tabuleiro);//preenchendo as configura��es padr�es do tabuleiro

    //apresentando o tabuleiro
    imprimindo_tabuleiro(linhas, colunas, tabuleiro);

    return 0;
}
