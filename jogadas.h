//Diogo Baptista Pinto 2020133653

#ifndef TRABALHOP_JOGADAS_H
#define TRABALHOP_JOGADAS_H
typedef struct noLista no,*pno;

struct noLista{

    int jogada;
    char player;
    int peca;
    int x;
    int y;
    int linhas;
    int colunas;
    int contaAdiciona1;
    int contaAdiciona2;
    int contaPedra1;
    int contaPedra2;
    pno prox;
};

pno guardaNo(pno novoNo ,char caracter, int lin, int col, char player, int contaJogada, int linhas, int colunas, int contaAdiciona1, int contaAdiciona2, int contaPedra1, int contaPedra2);
pno geraLista(pno novoNo, pno lista, int contaJogada);
void imprimeLista(pno lista);
void guardaBinario(pno lista);
void guardaTexto(pno lista);
void apagaLista(pno lista);
#endif //TRABALHOP_JOGADAS_H
