#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct para armazenar informações de um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio* mapa, int quantidade) {
    printf("========================================\n");
    printf("    SISTEMA DE CADASTRO DE TERRITÓRIOS\n");
    printf("         Jogo War - Nível Aventureiro\n");
    printf("========================================\n\n");
    
    printf("Preencha os dados dos %d territórios:\n\n", quantidade);
    
    for (int i = 0; i < quantidade; i++) {
        printf("--- TERRITÓRIO %d ---\n", i + 1);
        
        printf("Digite o nome do território: ");
        scanf("%29s", mapa[i].nome);
        
        printf("Digite a cor do exército: ");
        scanf("%9s", mapa[i].cor);
        
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        
        printf("\n");
    }
}

// Função para exibir todos os territórios
void exibirTerritorios(Territorio* mapa, int quantidade) {
    printf("\n========================================\n");
    printf("         ESTADO DOS TERRITÓRIOS\n");
    printf("========================================\n\n");
    
    for (int i = 0; i < quantidade; i++) {
        printf("TERRITÓRIO %d:\n", i + 1);
        printf("  Nome:    %s\n", mapa[i].nome);
        printf("  Cor:     %s\n", mapa[i].cor);
        printf("  Tropas:  %d\n", mapa[i].tropas);
        printf("----------------------------------------\n");
    }
}

// Função para simular um ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n========================================\n");
    printf("           SIMULAÇÃO DE BATALHA\n");
    printf("========================================\n");
    printf("ATACANTE: %s (%s) com %d tropas\n", atacante->nome, atacante->cor, atacante->tropas);
    printf("DEFENSOR: %s (%s) com %d tropas\n", defensor->nome, defensor->cor, defensor->tropas);
    printf("----------------------------------------\n\n");
    
    // Simula dados de ataque (1 a 6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;
    
    printf("Dado do Atacante: %d\n", dadoAtacante);
    printf("Dado do Defensor: %d\n\n", dadoDefensor);
    
    if (dadoAtacante > dadoDefensor) {
        printf(">>> VITÓRIA DO ATACANTE! <<<\n\n");
        
        // Atacante vence: defensor muda de cor e perde tropas
        printf("O território %s foi conquistado!\n", defensor->nome);
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;
        
        printf("Nova cor de %s: %s\n", defensor->nome, defensor->cor);
        printf("Tropas em %s: %d\n", defensor->nome, defensor->tropas);
        printf("Tropas restantes em %s: %d\n", atacante->nome, atacante->tropas);
    } else if (dadoDefensor > dadoAtacante) {
        printf(">>> VITÓRIA DO DEFENSOR! <<<\n\n");
        
        // Defensor vence: atacante perde uma tropa
        printf("%s conseguiu repelir o ataque!\n", defensor->nome);
        atacante->tropas--;
        
        printf("Tropas perdidas por %s: 1\n", atacante->nome);
        printf("Tropas restantes em %s: %d\n", atacante->nome, atacante->tropas);
    } else {
        printf(">>> EMPATE! <<<\n\n");
        printf("A batalha não teve vencedor. Ambos recuam.\n");
    }
    
    printf("========================================\n");
}

// Função para liberar a memória alocada
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

// Função principal
int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    
    int quantidade;
    
    // Solicita a quantidade de territórios
    printf("========================================\n");
    printf("    JOGO WAR - NÍVEL AVENTUREIRO\n");
    printf("========================================\n\n");
    
    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &quantidade);
    
    if (quantidade <= 0) {
        printf("Erro: Quantidade de territórios deve ser positiva!\n");
        return 1;
    }
    
    // Aloca memória dinamicamente para o vetor de territórios
    Territorio* mapa = (Territorio*) calloc(quantidade, sizeof(Territorio));
    
    if (mapa == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        return 1;
    }
    
    // Fase 1: Cadastro de territórios
    cadastrarTerritorios(mapa, quantidade);
    
    // Fase 2: Exibição inicial
    exibirTerritorios(mapa, quantidade);
    
    // Fase 3: Sistema de ataques
    int continuar = 1;
    
    while (continuar) {
        printf("\n========================================\n");
        printf("          SISTEMA DE ATAQUES\n");
        printf("========================================\n\n");
        
        printf("Territórios disponíveis:\n");
        for (int i = 0; i < quantidade; i++) {
            printf("%d. %s (%s) - %d tropas\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
        }
        
        int idAtacante, idDefensor;
        
        // Seleciona o território atacante
        printf("\nQual território ataca? (1-%d): ", quantidade);
        scanf("%d", &idAtacante);
        idAtacante--;
        
        if (idAtacante < 0 || idAtacante >= quantidade) {
            printf("Opção inválida!\n");
            continue;
        }
        
        if (mapa[idAtacante].tropas <= 0) {
            printf("Erro: Este território não possui tropas para atacar!\n");
            continue;
        }
        
        // Seleciona o território defensor
        printf("Qual território é defendido? (1-%d): ", quantidade);
        scanf("%d", &idDefensor);
        idDefensor--;
        
        if (idDefensor < 0 || idDefensor >= quantidade) {
            printf("Opção inválida!\n");
            continue;
        }
        
        if (idAtacante == idDefensor) {
            printf("Erro: Um território não pode atacar a si mesmo!\n");
            continue;
        }
        
        if (strcmp(mapa[idAtacante].cor, mapa[idDefensor].cor) == 0) {
            printf("Erro: Não é possível atacar um território aliado!\n");
            continue;
        }
        
        // Realiza o ataque
        atacar(&mapa[idAtacante], &mapa[idDefensor]);
        
        // Exibe o estado dos territórios após o ataque
        exibirTerritorios(mapa, quantidade);
        
        // Pergunta se deseja continuar
        printf("\nDeseja continuar atacando? (1=Sim, 0=Não): ");
        scanf("%d", &continuar);
    }
    
    printf("\n========================================\n");
    printf("   Obrigado por jogar War em C!\n");
    printf("========================================\n\n");
    
    // Libera a memória alocada
    liberarMemoria(mapa);
    
    return 0;
}
