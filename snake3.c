#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define ALTURA 20
#define LARGURA 40
#define MAX_CAUDA 500
#define MAX_RANKING 5
#define MAX_NOME 50
#define ARQUIVO_RANKING "snake_ranking.dat"


int main() 
{
    // Variáveis do jogo
    typedef struct {
        char nome[MAX_NOME];
        int pontuacao;
    } Jogador;

    typedef enum { STOP = 0, ESQUERDA, DIREITA, CIMA, BAIXO } Direcao;
    int x, y, frutaX, frutaY, pontuacao, nCauda = 0, delay = 150;
    int caudaX[MAX_CAUDA], caudaY[MAX_CAUDA];
    Direcao dir = STOP;
    bool gameOver = false;
    char snake_skin = 'O';
    Jogador ranking[MAX_RANKING];
    int totalRanking = 0;
    int opcao = 0;
    
    // Inicialização
    srand(time(0));
    
    // Carregar ranking
    FILE *arquivo = fopen(ARQUIVO_RANKING, "rb");
    if (arquivo) {
        fread(&totalRanking, sizeof(int), 1, arquivo);
        fread(ranking, sizeof(Jogador), totalRanking, arquivo);
        fclose(arquivo);
    }

    while (opcao != 5) {
        // Limpar tela de forma mais portável
        for (int i = 0; i < 50; i++) printf("\n");
        printf("+-----------------------+\n");
        printf("|         SNAKE         |\n");
        printf("+-----------------------+\n");
        printf("|  1 - Novo Jogo        |\n");
        printf("|  2 - Ver Ranking      |\n");
        printf("|  3 - Sobre            |\n");
        printf("|  4 - Comandos         |\n");
        printf("|  5 - Sair             |\n");
        printf("+-----------------------+\n");
        printf("Escolha: ");
        
        // Validação de entrada
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            opcao = 0;
        }
        while (getchar() != '\n');

        switch (opcao) {
            case 1: { // Novo Jogo
                // Configuração inicial
                Jogador atual;
                printf("Digite seu nome (max 49 chars): ");
                fgets(atual.nome, 50, stdin);
                atual.nome[strcspn(atual.nome, "\n")] = '\0';
                
                printf("Escolha o simbolo da cobra: ");
                scanf(" %c", &snake_skin);
                while (getchar() != '\n');
                
                // Seleção de dificuldade com validação
                int nivel = 0;
                do {
                    printf("Nivel (1-Facil, 2-Medio, 3-Dificil): ");
                    if (scanf("%d", &nivel) != 1) {
                        while (getchar() != '\n');
                        nivel = 0;
                    }
                } while (nivel < 1 || nivel > 3);
                
                switch (nivel) {
                    case 1: delay = 200; break;
                    case 2: delay = 120; break;
                    case 3: delay = 60; break;
                }
                
                // Inicialização do jogo
                x = LARGURA / 2;
                y = ALTURA / 2;
                frutaX = rand() % LARGURA;
                frutaY = rand() % ALTURA;
                pontuacao = 0;
                nCauda = 0;
                dir = STOP;
                gameOver = false;
                
                // Limpar cauda
                for (int i = 0; i < MAX_CAUDA; i++) {
                    caudaX[i] = -1;
                    caudaY[i] = -1;
                }
                
                // Loop principal do jogo
                while (!gameOver) {
                    // Desenhar tela
                    system("cls");
                    for (int i = 0; i < LARGURA + 2; i++) printf("#");
                    printf("\n");
                    
                    for (int i = 0; i < ALTURA; i++) {
                        printf("#");
                        for (int j = 0; j < LARGURA; j++) {
                            if (i == y && j == x) printf("@");
                            else if (i == frutaY && j == frutaX) printf("F");
                            else {
                                bool parteCauda = false;
                                for (int k = 0; k < nCauda; k++) {
                                    if (caudaX[k] == j && caudaY[k] == i) {
                                        printf("%c", snake_skin);
                                        parteCauda = true;
                                        break;
                                    }
                                }
                                if (!parteCauda) printf(" ");
                            }
                        }
                        printf("#\n");
                    }
                    
                    for (int i = 0; i < LARGURA + 2; i++) printf("#");
                    printf("\nPontos: %d | Comprimento: %d\n", pontuacao, nCauda + 1);
                    
                    // Controles
                    if (_kbhit()) {
                        char tecla = _getch();
                        if (tecla == 'a' && dir != DIREITA) dir = ESQUERDA;
                        else if (tecla == 'd' && dir != ESQUERDA) dir = DIREITA;
                        else if (tecla == 'w' && dir != BAIXO) dir = CIMA;
                        else if (tecla == 's' && dir != CIMA) dir = BAIXO;
                        else if (tecla == 'x') gameOver = true;
                        else if (tecla == 'r') { // Rotação
                            if (dir == ESQUERDA) dir = CIMA;
                            else if (dir == CIMA) dir = DIREITA;
                            else if (dir == DIREITA) dir = BAIXO;
                            else if (dir == BAIXO) dir = ESQUERDA;
                            Beep(800, 80);
                        }
                    }
                    
                    // Movimentação da cauda
                    if (nCauda > 0) {
                        for (int i = nCauda - 1; i > 0; i--) {
                            caudaX[i] = caudaX[i - 1];
                            caudaY[i] = caudaY[i - 1];
                        }
                        caudaX[0] = x;
                        caudaY[0] = y;
                    }
                    
                    // Movimentação da cabeça
                    switch (dir) {
                        case ESQUERDA: x--; break;
                        case DIREITA: x++; break;
                        case CIMA: y--; break;
                        case BAIXO: y++; break;
                    }
                    
                    // Verificar colisões
                    if (x < 0 || x >= LARGURA || y < 0 || y >= ALTURA) {
                        gameOver = true;
                    }
                    
                    for (int i = 0; i < nCauda; i++) {
                        if (caudaX[i] == x && caudaY[i] == y) {
                            gameOver = true;
                        }
                    }
                    
                    // Verificar se comeu fruta
                    if (x == frutaX && y == frutaY) {
                        pontuacao += 10;
                        Beep(1000, 80); Beep(1200, 80);
                        
                        // Gerar nova fruta em posição válida
                        bool posValida;
                        do {
                            posValida = true;
                            frutaX = rand() % LARGURA;
                            frutaY = rand() % ALTURA;
                            
                            if (frutaX == x && frutaY == y) posValida = false;
                            for (int i = 0; i < nCauda && posValida; i++) {
                                if (frutaX == caudaX[i] && frutaY == caudaY[i]) {
                                    posValida = false;
                                }
                            }
                        } while (!posValida);
                        
                        // Aumentar cauda
                        if (nCauda < MAX_CAUDA) nCauda++;
                        
                        // Aumentar dificuldade
                        if (delay > 30) delay -= 5;
                    }
                    
                    Sleep(delay);
                }
                
                // Tela de Game Over
                // Limpar tela de forma mais portável
                for (int i = 0; i < 50; i++) printf("\n");
                printf("\n    ____    _    ___    ___ _____    _____     _______ ____ ____        \n");
                printf(" / ___|  / \\  |   \\__/ | | ____|  / _ \\ \\   / / ____|  _ \\          \n");
                printf("| |  _  / _ \\ | |\\__/_/| |  _|   | | | \\ \\ / /|  _| | |_) |       \n");
                printf("| |_| |/ ___ \\| |      | | |___  | |_| |\\ V / | |___|  _ <            \n");
                printf(" \\____/_/   \\ \\_|      |_|_____|  \\___/  \\_/  |_____|_| \\_\\           \n\n");
                printf("Pontuacao: %d\n", pontuacao);
                
                // Efeitos sonoros de game over
                Beep(659, 120); Beep(622, 120); Beep(587, 120); 
                Beep(554, 120); Beep(523, 250); Beep(392, 350); Beep(330, 400);
                
                // Atualizar ranking
                atual.pontuacao = pontuacao;
                if (totalRanking < MAX_RANKING || pontuacao > ranking[MAX_RANKING-1].pontuacao) {
                    if (totalRanking < MAX_RANKING) {
                        ranking[totalRanking++] = atual;
                    } else {
                        ranking[MAX_RANKING-1] = atual;
                    }
                    
                    // Ordenar ranking
                    for (int i = 0; i < totalRanking-1; i++) {
                        for (int j = i+1; j < totalRanking; j++) {
                            if (ranking[j].pontuacao > ranking[i].pontuacao) {
                                Jogador temp = ranking[i];
                                ranking[i] = ranking[j];
                                ranking[j] = temp;
                            }
                        }
                    }
                    
                    // Salvar ranking
                    arquivo = fopen(ARQUIVO_RANKING, "wb");
                    if (arquivo) {
                        fwrite(&totalRanking, sizeof(int), 1, arquivo);
                        fwrite(ranking, sizeof(Jogador), totalRanking, arquivo);
                        fclose(arquivo);
                    }
                    
                    printf("\nNovo recorde! Voce esta no ranking!\n");
                }
                
                printf("\nPressione qualquer tecla...");
                _getch();
                break;
            }
            
            case 2: { // Ver Ranking
                system("cls");
                printf("\n=== TOP %d JOGADORES ===\n\n", MAX_RANKING);
                
                if (totalRanking == 0) {
                    printf("Nenhum registro encontrado.\n");
                } else {
                    for (int i = 0; i < totalRanking; i++) {
                        printf("%d. %-30s %5d pts\n", i+1, ranking[i].nome, ranking[i].pontuacao);
                    }
                }
                
                printf("\nPressione qualquer tecla...");
                _getch();
                break;
            }
            
            case 3: { // Sobre
                system("cls");
                printf("\n=== SNAKE GAME ===\n\n");
                printf("Versao consolidada\n");
                printf("Desenvolvido em C por um programador raiz\n");
                printf("Recursos:\n");
                printf("- Sistema de ranking persistente\n");
                printf("- Multiplas dificuldades\n");
                printf("- Efeitos sonoros\n");
                printf("- Rotacao de direcao\n");
                printf("\nPressione ENTER...");
                getchar();
                break;
            }
            
            case 4: { // Comandos
                system("cls");
                printf("\n=== CONTROLES ===\n\n");
                printf("W - Cima\n");
                printf("A - Esquerda\n");
                printf("S - Baixo\n");
                printf("D - Direita\n");
                printf("R - Rotacionar direcao\n");
                printf("X - Sair do jogo\n");
                printf("\nPressione ENTER...");
                getchar();
                break;
            }
            
            case 5: // Sair
                printf("\nSaindo...\n");
                Beep(523, 200); Beep(392, 400); // Efeito sonoro de saída
                break;
                
            default:
                printf("\nOpcao invalida!\n");
                Beep(200, 300); // Som de erro
                Sleep(1000);
        }
    }
    
    return 0;
}