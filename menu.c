//Diogo Baptista Pinto 2020133653

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void menu(int *flagBot) {

    int opcao;
/*
    printf( "    /$$$$$                                           /$$                                                    /$$$$$$                             \n");
    printf( "   |__  $$                                          | $$                                                   /$$__  $$                            \n");
    printf( "      | $$  /$$$$$$   /$$$$$$   /$$$$$$         /$$$$$$$  /$$$$$$         /$$$$$$$  /$$$$$$  /$$$$$$/$$$$ | $$  |__//$$$$$$   /$$$$$$   /$$$$$$ \n");
    printf( "      | $$ /$$__  $$ /$$__  $$ /$$__  $$       /$$__  $$ /$$__  $$       /$$_____/ /$$__  $$| $$_  $$_  $$| $$$$   /$$__  $$ /$$__  $$ /$$__  $$\n");
    printf( " /$$  | $$| $$  | $$| $$  | $$| $$  | $$      | $$  | $$| $$  | $$      |  $$$$$$ | $$$$$$$$| $$ | $$ | $$| $$_/  | $$  | $$| $$  |__/| $$  | $$\n");
    printf( "| $$  | $$| $$  | $$| $$  | $$| $$  | $$      | $$  | $$| $$  | $$       |____  $$| $$_____/| $$ | $$ | $$| $$    | $$  | $$| $$      | $$  | $$\n");
    printf( "|  $$$$$$/|  $$$$$$/|  $$$$$$$|  $$$$$$/      |  $$$$$$$|  $$$$$$/       /$$$$$$$/|  $$$$$$$| $$ | $$ | $$| $$    |  $$$$$$/| $$      |  $$$$$$/\n");
    printf( " |______/  |______/  |____  $$ |______/        |_______/ |______/       |_______/  |_______/|__/ |__/ |__/|__/     |______/ |__/       |______/ \n");
    printf( "                     /$$  | $$                                                                                                                  \n");
    printf( "                    |  $$$$$$/                                                                                                                  \n");
    printf( "                     |______/                                                                                                                   \n");
*/
    printf("JOGO DO SEMAFORO\n");
    printf("1- Single player\n");
    printf("2- Multiplayer\n");
    printf("3- Recuperar dados do ultimo jogo\n");
    printf("4- sair\n");

    while(1) {
        printf("Digite uma opcao:");
        scanf("%d", &opcao);

        if (opcao == 1) {
            *flagBot = 1;
            break;
        } else if (opcao == 2) {
            return;
        } else if (opcao == 3) {
            break;
        } else if (opcao == 4) {
            exit(0);
        } else
            printf("\nDigite uma opcao valida!\n");
    }

}
