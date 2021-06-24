//Diogo Baptista Pinto 2020133653
#include "jogadas.h"
#include <stdio.h>
#include <stdlib.h>

pno guardaNo(pno novoNo ,char caracter, int lin, int col, char player, int contaJogada, int linhas, int colunas, int contaAdiciona1, int contaAdiciona2, int contaPedra1, int contaPedra2){

    novoNo = NULL;

    novoNo = malloc(sizeof(no));
    if(novoNo == NULL){
        printf("\nErro na alocacao do novo no com a jogada!\n\n");
        exit(0);
    }
    novoNo->jogada = contaJogada;
    novoNo->linhas = linhas;
    novoNo->colunas = colunas;
    novoNo->contaAdiciona1 = contaAdiciona1;
    novoNo->contaAdiciona2 = contaAdiciona2;
    novoNo->contaPedra1 = contaPedra1;
    novoNo->contaPedra2 = contaPedra2;
    novoNo->peca = caracter;
    novoNo->x = lin;
    novoNo->y = col;
    novoNo->player = player;
    novoNo->prox = NULL;

    return novoNo;
}

pno geraLista(pno novoNo, pno lista, int contaJogada){

    if(contaJogada == 1){
        lista = novoNo;
    }
    else{
        novoNo->prox = lista;
        lista = novoNo;
    }
    return lista;
}

void imprimeLista(pno lista){

    int k, i = 0;
    printf("\nIntroduza quantas jogadas quer ver por favor: \n");
    scanf("%d",&k);
    while(lista != NULL && i < k){
        printf("\nO jogador %c meteu a peca %c na posicao %d %d\n", lista->player, lista->peca,lista->x,lista->y);
        lista = lista->prox;
        i++;
    }
}

void guardaBinario(pno lista){

    FILE *f = NULL;
    f = fopen("jogo.bin", "wb");
    if(f == NULL){
        printf("\nErro ao abrir o ficheiro para escrita!\n\n");
        fclose(f);
        return;
    }

    while(lista != NULL){
        fwrite(lista,1,sizeof(no),f);
        lista = lista->prox;
    }
    fclose(f);
}

void apagaLista(pno lista){
    pno aux;
    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

void guardaTexto(pno lista){

    FILE *f = NULL;
    char nomeF[50];
    printf("\nDigite o nome do ficheiro de texto onde quer guardar o tabuleiro (meta .txt no final)\n");
    scanf(" %50[^\n]s",nomeF);
    f = fopen(nomeF,"wt");
    if(f == NULL){
        printf("\nErro ao abrir o ficheiro para escrita!\n\n");
        fclose(f);
        exit(0);
    }

    while(lista != NULL){
        fprintf(f,"%d %d %d %d %d %d %d %c %d %d %c\n", lista->jogada, lista->linhas, lista->colunas, lista->contaAdiciona1, lista->contaAdiciona2, lista-> contaPedra1, lista->contaPedra2,lista->peca, lista->x, lista->y, lista->player);
        lista = lista->prox;
    }
    fclose(f);
}


