#include <stdio.h>
int tabuleiro[10][10]; // [coluna][linha]
int lineA, lineB, lineC, lineD; // Navio 1, 2, 3, 4
int columnA, columnB, columnC, columnD; // Navio 1, 2, 3, 4
int columnAI, columnBI, columnCI, columnDI, lineAI, lineBI, lineCI, lineDI; // Váriaveis de entrada dos navios

void initialize(){ // nao lembro oq faz, mas espero que crie uma linha para os navios
    for(int i = 0; i < 10; i++){ 
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
}

void resultBoard(){ // Imprime o tabuleiro final
    for(int i = 0; i < 10; i++){ 
        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

}

void defineShips(){ 
    int usedCoord1, usedCoord2, usedCoord3, usedCoord4;
    // Navio 1
    printf("\nDigite a coluna e a linha para o 1º navio (ex: 4 8): ");
    scanf("%d %d", &columnAI, &lineA);
    usedCoord1 = (tabuleiro[columnAI][lineA] || tabuleiro[columnAI + 3][lineA + 3] == 3) ? 1 : 0;

    if(usedCoord1 == 0){
        for(columnA = columnAI; columnA < columnAI + 3; columnA++){
                tabuleiro[columnA][lineA] = 3;
            }
        resultBoard();
        }
    else if(usedCoord1 == 1){
        printf("Há um navio nas coordenadas escolhidas.");
    }

    // Navio 2
    printf("\nDigite a coluna e a linha para o 2º navio, respectivamente (ex: 4 8): ");
    scanf("%d %d", &columnB, &lineBI);
    usedCoord2 = (tabuleiro[columnB][lineBI] || tabuleiro[columnB + 3][lineBI + 3] == 3) ? 1 : 0;

    if(usedCoord2 == 0){
        for(lineB = lineBI; lineB < lineBI + 3; lineB++){
                tabuleiro[columnB][lineB] = 3;
            }
        resultBoard();
        }
    else if(usedCoord2 == 1){
        printf("Há um navio nas coordenadas escolhidas.");
    }

    // Navio 3
    printf("\nDigite a coluna e a linha para o 3º navio, respectivamente (ex: 4 8): ");
    scanf("%d %d", &columnCI, &lineCI);
    usedCoord3 = (tabuleiro[columnCI][lineCI] || tabuleiro[columnCI + 3][lineCI + 3] == 3) ? 1 : 0;

    if(usedCoord3 == 0){
        for(columnC = columnCI; columnC < columnCI + 3; columnC++, lineCI++){
            tabuleiro[columnC][lineCI] = 3;
        }
        resultBoard();
        }

    else if(usedCoord3 == 1){
        printf("Há um navio nas coordenadas escolhidas.");
    }

    // Navio 4
    printf("\nDigite a coluna e a linha para o 4º navio, respectivamente (ex: 4 8): ");
    scanf("%d %d", &columnDI, &lineDI);
    usedCoord4 = (tabuleiro[columnDI][lineDI] || tabuleiro[columnDI + 3][lineDI + 3] == 3) ? 1 : 0;

    if(usedCoord4 == 0){
        for(columnD = columnDI; columnD < columnDI + 3; columnD++, lineDI--){
            tabuleiro[columnD][lineDI] = 3;
        }
        resultBoard();
        }

    else if(usedCoord4 == 1){
        printf("Há um navio nas coordenadas escolhidas.");
    }

}

int main(){
    int opcao;

    initialize();
    printf("Seja bem vindo ao jogo de Batalha Naval!\n");
    printf("1. Ver regras.\n");
    printf("2. Iniciar jogo.\n");
    printf("3. Ver tabuleiro.\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        printf("\nVence quem derrotar todos os navios do inimigo.\n");
        break;
    case 2:
        defineShips();
        break;
    case 3:
        resultBoard();
        break;
    default:
        printf("\nA opção escolhida não existe.");
        break;
    }
}
