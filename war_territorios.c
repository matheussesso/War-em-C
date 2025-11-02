#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MISSAO 100
#define TOTAL_MISSOES 5

// Struct para armazenar informações de um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Vetor de missões estratégicas disponíveis
const char* missoes_disponiveis[TOTAL_MISSOES] = {
    "Conquistar 3 territórios inimigos",
    "Eliminar todas as tropas da cor vermelha",
    "Dominar 50% dos territórios",
    "Acumular 100 tropas em um único território",
    "Conquistar o território com mais tropas"
};

// Função para atribuir uma missão aleatória ao jogador
void atribuirMissao(char* destino, const char* missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

// Função para exibir a missão do jogador
void exibirMissao(char missao[MAX_MISSAO]) {
    printf("\n========================================\n");
    printf("         SUA MISSÃO ESTRATÉGICA\n");
    printf("========================================\n");
    printf("MISSÃO: %s\n", missao);
    printf("========================================\n\n");
}

// Função para contar territórios de uma cor específica
int contarTerritoriosPorCor(Territorio* mapa, int tamanho, char* cor) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mapa[i].cor, cor) == 0) {
            contador++;
        }
    }
    return contador;
}

// Função para verificar se a missão foi cumprida
int verificarMissao(char* missao, Territorio* mapa, int tamanho, char* cor_jogador) {
    // Missão 1: Conquistar 3 territórios inimigos
    if (strcmp(missao, "Conquistar 3 territórios inimigos") == 0) {
        int territorios_jogador = contarTerritoriosPorCor(mapa, tamanho, cor_jogador);
        return territorios_jogador >= 3;
    }
    
    // Missão 2: Eliminar todas as tropas da cor vermelha
    if (strcmp(missao, "Eliminar todas as tropas da cor vermelha") == 0) {
        int tropas_vermelhas = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelho") == 0) {
                tropas_vermelhas += mapa[i].tropas;
            }
        }
        return tropas_vermelhas == 0;
    }
    
    // Missão 3: Dominar 50% dos territórios
    if (strcmp(missao, "Dominar 50% dos territórios") == 0) {
        int territorios_jogador = contarTerritoriosPorCor(mapa, tamanho, cor_jogador);
        return territorios_jogador >= (tamanho / 2);
    }
    
    // Missão 4: Acumular 100 tropas em um único território
    if (strcmp(missao, "Acumular 100 tropas em um único território") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, cor_jogador) == 0 && mapa[i].tropas >= 100) {
                return 1;
            }
        }
        return 0;
    }
    
    // Missão 5: Conquistar o território com mais tropas
    if (strcmp(missao, "Conquistar o território com mais tropas") == 0) {
        int max_tropas = 0;
        int indice_max = 0;
        
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas > max_tropas) {
                max_tropas = mapa[i].tropas;
                indice_max = i;
            }
        }
        
        return strcmp(mapa[indice_max].cor, cor_jogador) == 0;
    }
    
    return 0;
}

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio* mapa, int quantidade) {
    printf("========================================\n");
    printf("    SISTEMA DE CADASTRO DE TERRITÓRIOS\n");
    printf("          Jogo War - Nível Mestre\n");
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

// Função para liberar a memória alocada (territórios e missões)
void liberarMemoria(Territorio* mapa, char** missoes_jogadores, int quantidade) {
    free(mapa);
    
    if (missoes_jogadores != NULL) {
        for (int i = 0; i < quantidade; i++) {
            free(missoes_jogadores[i]);
        }
        free(missoes_jogadores);
    }
}

// Função principal
int main() {
    srand(time(NULL));
    
    int quantidade;
    
    printf("========================================\n");
    printf("    JOGO WAR - NÍVEL MESTRE\n");
    printf("   Com Sistema de Missões Estratégicas\n");
    printf("========================================\n\n");
    
    printf("Quantos territórios deseja cadastrar? ");
    scanf("%d", &quantidade);
    
    if (quantidade <= 0) {
        printf("Erro: Quantidade deve ser positiva!\n");
        return 1;
    }
    
    // Aloca memória para territórios
    Territorio* mapa = (Territorio*) calloc(quantidade, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro: Falha na alocação de memória para territórios!\n");
        return 1;
    }
    
    // Aloca memória para as missões dos jogadores
    char** missoes_jogadores = (char**) malloc(quantidade * sizeof(char*));
    if (missoes_jogadores == NULL) {
        printf("Erro: Falha na alocação de memória para missões!\n");
        free(mapa);
        return 1;
    }
    
    for (int i = 0; i < quantidade; i++) {
        missoes_jogadores[i] = (char*) malloc(MAX_MISSAO * sizeof(char));
        if (missoes_jogadores[i] == NULL) {
            printf("Erro: Falha na alocação de memória!\n");
            liberarMemoria(mapa, missoes_jogadores, i);
            return 1;
        }
    }
    
    // Fase 1: Cadastro de territórios
    cadastrarTerritorios(mapa, quantidade);
    
    // Fase 2: Atribuição de missões
    printf("\n========================================\n");
    printf("      DISTRIBUINDO MISSÕES AOS JOGADORES\n");
    printf("========================================\n\n");
    
    for (int i = 0; i < quantidade; i++) {
        atribuirMissao(missoes_jogadores[i], missoes_disponiveis, TOTAL_MISSOES);
        printf("Jogador %d (%s): Missão atribuída!\n", i + 1, mapa[i].cor);
    }
    
    // Fase 3: Exibição inicial
    exibirTerritorios(mapa, quantidade);
    
    // Exibe a missão do primeiro jogador como exemplo
    printf("Seu turno de ver sua missão!");
    exibirMissao(missoes_jogadores[0]);
    
    // Fase 4: Sistema de ataques com verificação de missões
    int continuar = 1;
    int turno = 0;
    
    while (continuar) {
        printf("\n========================================\n");
        printf("        TURNO %d - SISTEMA DE ATAQUES\n", turno + 1);
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
        
        // Verifica se alguma missão foi cumprida
        printf("\n--- VERIFICANDO MISSÕES ---\n\n");
        int missao_cumprida = 0;
        
        for (int i = 0; i < quantidade; i++) {
            if (verificarMissao(missoes_jogadores[i], mapa, quantidade, mapa[i].cor)) {
                printf("🎉 MISSÃO CUMPRIDA! 🎉\n");
                printf("Jogador %d (%s) completou sua missão: \n", i + 1, mapa[i].cor);
                printf("'%s'\n\n", missoes_jogadores[i]);
                missao_cumprida = 1;
                continuar = 0;
                break;
            }
        }
        
        if (!missao_cumprida) {
            printf("Nenhuma missão foi cumprida ainda. Continuando...\n");
        }
        
        if (continuar) {
            printf("\nDeseja continuar atacando? (1=Sim, 0=Não): ");
            scanf("%d", &continuar);
            turno++;
        }
    }
    
    printf("\n========================================\n");
    printf("        JOGO FINALIZADO - VENCEDOR!\n");
    printf("========================================\n\n");
    
    printf("Obrigado por jogar War em C!\n");
    printf("Nível Mestre concluído com sucesso!\n\n");
    
    // Libera a memória alocada
    liberarMemoria(mapa, missoes_jogadores, quantidade);
    
    return 0;
}
