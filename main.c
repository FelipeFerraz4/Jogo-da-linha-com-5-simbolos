#include <stdio.h>
#include "Tabuleiro.h"

int main()
{
    int status_jogo;
    do
    {
        printf("\n\tJogo dos 5 simbolos\n\n"
               "1 ------- Iniciar jogo\n"
               "0 ------- finalizar o jogo\n"
                );
        scanf("%d", &status_jogo);

        if(status_jogo==1)
            tabuleiro_jogo();

    }while(status_jogo!=0);

    return 0;
}
