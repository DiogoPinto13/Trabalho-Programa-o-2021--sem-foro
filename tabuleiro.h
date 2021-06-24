//Diogo Baptista Pinto 2020133653
#ifndef TRABALHOP_TABULEIRO_H
#define TRABALHOP_TABULEIRO_H

void tamInicial(int *linhas, int *colunas);
char **criaTab(int linhas, int colunas);
char **adicionaLinha(char **tab, int *linhas, int *colunas);
void adicionaColuna(char **tab, int *linhas, int *colunas);
void imprimeTabuleiro(char **tab, int linhas, int colunas);
void testa(char **tab, int linhas, int colunas, int *flagWin);
void jogada(char **tab, int linhas, int colunas, char *caracter, char pedra, int *contaJogada,int lin,int col, int *jogaP);
void limpaEcra();
void limpaTab(char **tab, int linhas, int colunas);
#endif //TRABALHOP_TABULEIRO_H
