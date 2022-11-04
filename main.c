#include <stdio.h>
#include "Tabuleiro.h"

int main()
{
    int status_jogo;
    srand(time(NULL));//para que a cada execução, a função rand() gere valores diferentes
    do
    {
        printf("\n\tJogo dos 5 simbolos\n\n"
               "1 ------- Iniciar jogo\n"
               "0 ------- Fechar o programa\n"
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
