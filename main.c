//Diogo Baptista Pinto 2020133653
#include<stdio.h>
#include<stdlib.h>
#include "tabuleiro.h"
#include "jogadas.h"
#include "menu.h"
#include "bot.h"

int main(){

    int linhas = 0;
    int colunas = 0;
    int contaAdiciona1=2, contaAdiciona2=2;
    char caracter = 'G';
    char pedra = 'S';
    int jogaP = 0;
    int contaPedra1 = 1, contaPedra2 = 1;
    int contaJogada = 0;
    int flagWin = 0;
    char player;
    int option = 0;
    int lin,col;
    int flagBot = 0;
    pno lista;
    pno novoNo;

    tamInicial(&linhas,&colunas);

    char **tab = criaTab(linhas, colunas);
    //adicionaColuna(tab, &linhas, &colunas);
    //tab = adicionaLinha(tab,&linhas,&colunas);
    //imprimeTabuleiro(tab,linhas,colunas);
    menu(&flagBot);

    do{
        limpaEcra();
        imprimeTabuleiro(tab, linhas, colunas);
        if(contaJogada % 2 == 0)
            player = 'A';
        else
            player = 'B';

            do{
                printf("\nVez do jogador %c", player);
                printf("\nO que quer fazer?");
                if(player == 'A'){
                    printf("\n1- colocar peca normal, 2-colocar pedra (%d uso restante), 3-adicionar linha(%d usos restantes), 4-adicionar coluna(%d usos restantes), 5-ver jogadas anteriores, 6-encerrar o jogo\n",contaPedra1,contaAdiciona1,contaAdiciona1);
                }
                else{
                    printf("\n1- colocar peca normal, 2-colocar pedra (%d uso restante), 3-adicionar linha(%d usos restantes), 4-adicionar coluna(%d usos restantes), 5-ver jogadas anteriores, 6- encerrar o jogo\n",contaPedra2,contaAdiciona2,contaAdiciona2);
                }
                scanf("%d",&option);

                if(option == 1){
                    printf("\nIntroduza uma jogada: (numero linha),(numero coluna)\n");
                    scanf("%d,%d", &lin, &col);
                    lin--;
                    col--;

                    if((player == 'A' || player == 'B') && flagBot == 0)
                        jogada(tab,linhas,colunas,&caracter,pedra,&contaJogada,lin,col,&jogaP);
                    else
                        jogaBot(tab, &linhas, &colunas, &caracter, pedra, &contaJogada, &jogaP);
                    testa(tab,linhas, colunas, &flagWin);
                }
                else if(option == 2){
                    if(player == 'A' && contaPedra1 != 0){
                        jogaP = 1;
                        printf("\nOnde queres a pedra?: (numero linha),(numero coluna)\n");
                        scanf("%d,%d", &lin, &col);
                        contaPedra1--;
                        lin--;
                        col--;
                        jogada(tab,linhas,colunas,&caracter,pedra,&contaJogada,lin,col,&jogaP);
                        testa(tab,linhas, colunas, &flagWin);
                    }
                    else if(player == 'B' && contaPedra2 != 0 && flagBot == 0){
                        jogaP = 1;
                        printf("\nOnde queres a pedra?: (numero linha),(numero coluna)\n");
                        scanf("%d,%d", &lin, &col);
                        contaPedra2--;
                        lin--;
                        col--;
                        jogada(tab,linhas,colunas,&caracter,pedra,&contaJogada,lin,col,&jogaP);
                    }
                    else {
                        printf("\nJa nao podes colocar mais nenhuma pedra!!!\n\n");
                    }

                }
                else if(option == 3){
                    if(player == 'A' && contaAdiciona1 != 0){
                        tab = adicionaLinha(tab, &linhas,&colunas);
                        contaAdiciona1--;
                        contaJogada++;
                        imprimeTabuleiro(tab, linhas, colunas);
                    }
                    else if(player == 'B' && contaAdiciona2 != 0 && flagBot == 0){
                        tab = adicionaLinha(tab, &linhas,&colunas);
                        contaAdiciona2--;
                        contaJogada++;
                        imprimeTabuleiro(tab, linhas, colunas);
                    }
                    else
                        printf("\nJa nao podes adicionar mais nenhuma linha!!!\n\n");
                }
                else if(option == 4){
                    if(player == 'A' && contaAdiciona1!=0){
                        adicionaColuna(tab, &linhas, &colunas);
                        contaAdiciona1--;
                        contaJogada++;
                        imprimeTabuleiro(tab,linhas,colunas);
                    }
                    else if(player == 'B' && contaAdiciona2!=0 && flagBot == 0){
                        adicionaColuna(tab, &linhas, &colunas);
                        contaAdiciona2--;
                        contaJogada++;
                        imprimeTabuleiro(tab,linhas,colunas);
                    }
                    else
                        printf("\nJa nao podes adicionar mais nenhuma coluna!\n\n");
                }
                else if(option == 5){
                    imprimeLista(lista);
                }
                else if(option == 6){
                    if(lista != NULL){
                        guardaBinario(lista);
                        apagaLista(lista);
                    }
                    limpaTab(tab,linhas,colunas);
                    exit(0);
                }
                else{
                    printf("\nIntroduza uma opcao valida!!\n");
                }

            }while(lin > linhas && col > colunas);

            novoNo = guardaNo(novoNo, caracter, lin, col, player, contaJogada, linhas, colunas, contaAdiciona1, contaAdiciona2, contaPedra1, contaPedra2);
            lista = geraLista(novoNo, lista, contaJogada);
            //guardaBinario(lista);
    }while(flagWin != 1);

    if(flagWin == 1){
        imprimeTabuleiro(tab, linhas, colunas);
        printf("\nO jogador %c ganhou o jogo!!!\n\n",player);
        guardaTexto(lista);
        limpaTab(tab,linhas,colunas);
        apagaLista(lista);
        return 0;
    }

    imprimeTabuleiro(tab, linhas, colunas);

    limpaTab(tab,linhas,colunas);  //liberta memoria antes de acabar o programa
    apagaLista(lista);
    return 0;
}

