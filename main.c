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

        switch(status_jogo)
        {
            case 0:
                break;
            case 1:
                tabuleiro_jogo();
                break;
            default:
                printf("\nOpcao digitada nao encontra,"
                       "por favor tente novamente\n");
        }

    }while(status_jogo!=0);

    return 0;
}
