//Diogo Baptista Pinto 2020133653
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "tabuleiro.h"

void tamInicial(int *linhas, int *colunas){

    srand(time(0));
    *linhas = (rand()% (5-3+1))+3;
    *colunas = *linhas;   //linhas e colunas tem que ter o mesmo valor no inicio

}

char **criaTab(int linhas, int colunas){
    char **tab;
    int i, j;

    tab = malloc(sizeof(char *)*linhas);   //cria o array inicial que vai conter ponteiros para outros arrays (cada linha)

    if(tab == NULL){
        printf("erro na criacao do tabuleiro!!!!\n");
        exit(0);
    }

    for(i = 0; i<linhas; i++){
        tab[i] = malloc(sizeof(char)*colunas);   //mete em cada posicao do array um ponteiro para cada linha
        if(tab[i] == NULL){
            printf("erro  na criacao do tabuleiro!!!\n");
            free(tab);
            //os outrtos...
            exit(0);
        }
    }

    for(i = 0; i <linhas; i++){
        for(j = 0; j < colunas; j++){
            tab[i][j] = '_';                     //preenche cada posicao
        }
    }


    return tab;
}

char **adicionaLinha(char **tab, int *linhas, int *colunas){
    *linhas = *linhas+1;
    int j;
    char **aux;
    aux = realloc(tab, sizeof(char *)*(*linhas));   //array com ponteiros aumenta uma unidade

    if(aux == NULL){
        printf("erro na alocacao de memoria!\n");
        exit(0);
    }
    tab = aux;

    aux[((*linhas)-1)] = malloc(sizeof(char)*(*colunas));    //aloca a nova linha

    if(aux == NULL){
        printf("erro na alocacao de memoria!\n");
        exit(0);
    }
    tab = aux;

        for(j = 0; j < *colunas; j++){
            tab[(*linhas -1)][j] = '_';
        }

    return tab;
}

void adicionaColuna(char **tab, int *linhas, int *colunas){
    *colunas = *colunas+1;
    int i;
    char *aux;

    for(i = 0; i <*linhas; i++){
        aux = realloc(tab[i], sizeof(char)*(*colunas));
        if(aux == NULL){
            printf("\nErro na realocacao!\n");
            exit(0);
        }
        tab[i] = aux;
    }

    for(i = 0; i < *linhas; i++){
            tab[i][(*colunas -1)] = '_';
    }

}

void imprimeTabuleiro(char **tab, int linhas, int colunas){

    int i,j;

    for(i = 0; i<linhas;i++){
        for(j = 0; j<colunas; j++){
            printf("|%c",tab[i][j]);
            if(j==colunas-1)
                printf("|");
        }
        printf("\n");
        for(j = 0; j<2*colunas+1; j++){
            printf("-");
        }
        printf("\n");
    }

}

void testa(char **tab, int linhas, int colunas, int *flagWin){

    int i,j,contaJogada = 0;

    //verifica linha se ganha
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas-1; j++){

            if(tab[i][j] == tab[i][j+1] && tab[i][j] != '_'){
                contaJogada++;
                if(contaJogada == linhas-1){
                    *flagWin = 1;
                    return;
                }
            }
            else{
                contaJogada = 0;
            }
        }
    }
    contaJogada = 0;
    //verifica coluna ganha
    for(i = 0; i < colunas; i++){
        for(j = 0; j < linhas-1; j++){

            if(tab[j][i] == tab[j+1][i] && tab[j][i] != '_'){
                contaJogada++;
                if(contaJogada == colunas-1){
                    *flagWin = 1;
                    return;
                }
            }
            else{
                contaJogada = 0;
            }
        }
    }
    contaJogada = 0;

    if(linhas == colunas){         //se o tabuleiro nao for um quadrado nao ha diagonal
        //diagonal normal
        for(i = 0; i < linhas-1; i++){

            if(tab[i][i] == tab[i+1][i+1] && tab[i][i] != '_'){
                contaJogada++;
                if(contaJogada == linhas-1){
                    *flagWin = 1;
                    return;
                }
            }
            else{
                contaJogada = 0;
            }
        }
        //diagonal invertida
        for(i = linhas-1, j = 0; j < linhas-1; j++,i--){
            if(tab[i][j] == tab[i-1][j+1] && tab[i][j] != '_'){
                contaJogada++;
                if(contaJogada == linhas-1){
                    *flagWin = 1;
                    return;
                }
            }
            else{
                contaJogada = 0;
            }
        }
    }


}

void jogada(char **tab, int linhas, int colunas, char *caracter, char pedra, int *contaJogada,int lin,int col, int *jogaP){

    int i,j;
    *caracter = 'G';

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){

            if(i == lin && j == col){
                if(tab[i][j] == '_'){         //se ta livre a casa
                    if(*jogaP == 1){           //jogada pedra
                        tab[i][j] = pedra;
                    }
                    else
                        tab[i][j] = *caracter;
                }
                else{
                    if(tab[i][j] == 'G'){
                        *caracter = tab[i][j] = 'Y';
                    }
                    else if(tab[i][j] == 'Y'){
                        *caracter = tab[i][j] = 'R';
                    }
                    else if(tab[i][j] == 'R'){
                        printf("\nJa nao podes colocar nenhuma peca aqui!\n");
                    }
                    else{
                        printf("\nnao podes colocar uma peca nessa casa!\n");
                    }
                }
            }
        }
    }

    *contaJogada = *contaJogada + 1;
    *jogaP = 0;
}

void limpaEcra(){
    for(int i = 0; i < 10; i++)
        printf("\n");
}

void limpaTab(char **tab, int linhas, int colunas){
    for(int i = 0; i <linhas; i++){
        free(tab[i]);  //elimina as linahs
    }

    free(tab);  //elimina o array dos ponteiros
}



