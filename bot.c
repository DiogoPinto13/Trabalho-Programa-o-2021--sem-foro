//Diogo Baptista Pinto 2020133653

#include "bot.h"
#include <stdio.h>
#include "utils.h"
#include "bot.h"
#include "tabuleiro.h"
#include "jogadas.h"

void jogaBot(char **tab, int *linhas, int *colunas, char *peca, char pedra, int *contaJogada, int *jogaP){
    int randomLin, randomCol;
    initRandom();

    randomLin = intUniformRnd(0,(*linhas) - 1);
    randomCol= intUniformRnd(0, (*colunas) -1);

    if(probEvento(0.80) == 1){   //jogada normal
        jogada(tab, *linhas, *colunas, peca,pedra, contaJogada,randomLin,randomCol, jogaP);
    }

    else{
        if(probEvento(0.50)){   //pedra
            *jogaP = 1;
            jogada(tab, *linhas, *colunas, peca,pedra, contaJogada,randomLin,randomCol, jogaP);
            *jogaP = 0;
        }
        else{
            if(probEvento(0.50)){   //adiciona linha
                tab = adicionaLinha(tab,linhas,colunas);
                (*contaJogada)++;
            }
            else{      //adiciona coluna
                adicionaColuna(tab,linhas,colunas);
                (*contaJogada)++;
            }
        }
    }

}

