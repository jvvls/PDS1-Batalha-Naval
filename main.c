#include <stdio.h>                                                              //bibliotecas necessárias
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
    int alg[10][10], est[10][10];                                                                                       //inicia dois tabueliros 10x10 para os dois jogadores
    int tamanho, linha, coluna, barcos, Alin, Acol, Aq, AE1 = 0, AE2 = 0, med1 = 0, med2 = 0, SA1 = 0, SA2 = 0;         //inicia as variaveis inteiras:variaves de tamanho do barco, posição do barco, posição de ataque(linha e coluna), quantidade de ataques, quantidade de barcos, contadores de acertos para ataque especial e contador para definir se há peças no tabuleiro
    char orientacao, tipo, Eorientacao;                                                                                 //inicia as variaveis de caracter: orientação da construção do barco, tipo de ataque selecionado e sentido do ataque especial

    for (int i = 0; i < 10; i++) {                                                                                         //inicia os tabuleiro de ambos os lados com todas as posições zeradas representando água
        for (int j = 0; j < 10; j++) {
            alg[i][j] = 0;
            est[i][j] = 0;
        }
    }
    for (int jogador = 1; jogador <= 2; jogador++) {                                //loop que permite trocar entre o jogador 1 e o 2 no posicionamento de barcos                 
        scanf("%d", &barcos);                                                       //recebe a quantidade de barcos que será inserido
        for (int i = 0; i < barcos; i++) {                                          //loop que faz a quantidade de barcos desejada
            scanf("%d %c %d %d", &tamanho, &orientacao, &linha, &coluna);           //lê como será o barco e sua posição inicial
            if (orientacao == 'h') {                                                //quando e pedido barco horizontal inicia a função de posicionamento que fixa a linha e muda a coluna
                for (int j = 0; j < tamanho; j++) {
                    if (coluna + j > 9) {                                           //verifica se a construção do barco vai exceder o tamanho do tabuleiro
                        if (jogador == 1) {                                         //parte do sistema de trocar entre jogador 1 e 2
                            alg[linha][(coluna + j) % 10] = 1;                      //quando excede o tabuleiro calcula o modulo da atual posição desejada para reajustar dentro do toroide
                        }
                        if (jogador == 2) {                                         //parte do sistema de trocar entre jogador 1 e 2
                            est[linha][(coluna + j) % 10] = 1;
                        }
                    }
                    else {
                        if (jogador == 1) {                                         //sistema de mudança de jogador
                            alg[linha][coluna + j] = 1;                             //fixa a linha e aumenta a coluna de 1 em 1 para formar o barco desejado
                        }
                        if (jogador == 2) {                                         //sistema de mudança de jogador
                            est[linha][coluna + j] = 1;                             //fixa a linha e aumenta a coluna de 1 em 1 para formar o barco desejado
                        }
                    }
                }
            }
            if (orientacao == 'v') {                                                //para barcos verticais ele ira fixar a coluna e mudar a linha 
                for (int j = 0; j < tamanho; j++) {                                 //repete a mesma lógia anterior porém com colunas fixas ao invés de linhas
                    if (linha + j > 9) {
                        if (jogador == 1) {
                            alg[(linha + j) % 10][coluna] = 1;
                        }
                        if (jogador == 2) {
                            est[(linha + j) % 10][coluna] = 1;
                        }

                    }
                    else {
                        if (jogador == 1) {
                            alg[linha + j][coluna] = 1;
                        }
                        if (jogador == 2) {
                            est[linha + j][coluna] = 1;
                        }
                    }
                }
            }
        }
    }
    scanf("%d", &Aq);                                                           //mede quantos ataques serão realizados
    for (int i = 1; i <= Aq; i++) {                                             //para garantir que os jogadores sempre joguem a mesma quantidade foi definido uma distribuição de jogadas pares e impares
        if (i % 2 == 1) {                                                       //vez do jogador 1 (impar)
            scanf("%s ", &tipo);                                                //lê a entrada de tipo e por um if separa o ataque normal do especial buscando a formatação de entrada de dados desejada
            if (tipo == 'n') {                                                  //sistema de ataque normal
                scanf("%d %d", &Alin, &Acol);                                   //lê as coordenadas de linha e coluna para o ataque normal
                if (est[Alin][Acol] != 0) {                                         //executa o ataque quando a casa está preenchida com barco
                    est[Alin][Acol] = 0;                                            //substitui a casa de barco para água      
                    AE1++;                                                          //conta o acerto para o especial
                }
                else {
                    AE1 = 0;                                                      //caso não tenha barco marca o erro 
                }
            }
            if (tipo == 'e') {                                                      //sistema de ataque especial
                scanf("%c %d", &Eorientacao, &Acol);                                //lê a orientação desejada(vertical v ou horizontal h)
                if (AE1 >= 2) {
                    if (Eorientacao == 'v') {                                       //define que o ataque será realizado verticalmente
                        for (int j = 0; j < 10; j++) {                             
                            if (est[j][Acol] != 0) {                                //verifica se acertou algo no especial
                                SA1++;
                            }
                            est[j][Acol] = 0;                                       //fixa a coluna e passa por todas as linhas
                        }
                    }
                    if (Eorientacao == 'h') {                                       //o processo se repete porém na horizontal             
                        for (int j = 0; j < 10; j++) {
                            if (est[Acol][j] != 0) {
                                SA1++;
                            }
                            est[Acol][j] = 0;                                     //fixa a linha e passa por todas as colunas
                        }
                    }

                    if (SA1 == 0) {                                             //caso o ataque especial não acerte nada o contador de especial é zerado
                        AE1 = 0;
                    }
                }
            }
            SA1 = 0;
        }
        if (i % 2 == 0) {                                                          //vez do jogador 2 (par)
            scanf("%s ", &tipo);                                                  //segue a mesma rotina do jogador 1 porém com a matriz alvo sendo alg(jogador 1)
            if (tipo == 'n') {
                scanf("%d %d", &Alin, &Acol);
                if (alg[Alin][Acol] != 0) {
                    alg[Alin][Acol] = 0;
                    AE2++;
                }
                else {
                    AE2 = 0;
                }
            }
            if (tipo == 'e') {
                scanf("%c %d", &Eorientacao, &Acol);
                if (AE2 >= 2) {
                    if (Eorientacao == 'v') {
                        for (int j = 0; j < 10; j++) {
                            if (alg[j][Acol] != 0) {
                                SA2++;
                            }
                            alg[j][Acol] = 0;
                        }
                    }
                    if (Eorientacao == 'h') {
                        for (int j = 0; j < 10; j++) {
                            if (alg[Acol][j] != 0) {
                                SA2++;
                            }
                            alg[Acol][j] = 0;
                        }
                    }
                    if (SA2 == 0) {
                        AE2 = 0;
                    }
                }
            }
            SA2 = 0;
        }
    }
    printf("  |");                                                          //imprime a matriz do jogador 1
    for (int j = 0; j <= 9; j++) {
        printf(" %d", j);
    }
    printf("\n");
    printf("--+");
    for (int j = 0; j <= 9; j++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i <= 9; i++) {
        printf("%d |", i);
        for (int j = 0; j <= 9; j++) {
            printf(" %d", alg[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("  |");                                                          //imprime a matriz do jogador 2
    for (int j = 0; j <= 9; j++) {
        printf(" %d", j);
    }
    printf("\n");
    printf("--+");
    for (int j = 0; j <= 9; j++) {
        printf("--");
    }
    printf("\n");
    for (int i = 0; i <= 9; i++) {
        printf("%d |", i);
        for (int j = 0; j <= 9; j++) {
            printf(" %d", est[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {         //verifica se ainda há barcos para ambos os times
        for (int j = 0; j < 10; j++) {
            if (alg[i][j] == 1) {
                med1++;
            }
            if (est[i][j] == 1) {
                med2++;
            }
        }
    }
    if ((med1 != 0) && (med2 == 0)) {           //testa se há peças para o jogador 1 e o jogado 2 não
        printf("1");                            //vitoria para o jogador 1
    }
    if ((med2 != 0) && (med1 == 0)) {           //testa se há peças para o jogador 2 e o jogado 1 não
        printf("2");                            //vitória para o jogador 2
    }
    if ((med1 == 0) && (med2 == 0)) {           //caso ambos sofram aniquiliação total empata
        printf("0");
    }
    if ((med1 != 0) && (med2 != 0)) {           //caso os dois tenham peças sobrando declara empata
        printf("0");        
    }
    printf("\n");
}