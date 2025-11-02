#include <stdio.h>
#include <string.h>

// DEFINIÇÃO DA STRUCT TERRITORIO
typedef struct {
    char nome[30];      // Nome do território
    char cor[10];       // Cor do exército (ex: Vermelho, Azul, Verde)
    int tropas;         // Quantidade de tropas estacionadas
} Territorio;

// FUNÇÃO PRINCIPAL
int main() {
    // Declaração de um vetor com capacidade para armazenar 5 territórios
    Territorio territorios[5];
    
    // Constante que define a quantidade de territórios
    const int QUANTIDADE_TERRITORIOS = 5;
    
    // ========================================================
    // FASE 1: CADASTRO DOS TERRITÓRIOS
    // ========================================================
    printf("========================================\n");
    printf("    SISTEMA DE CADASTRO DE TERRITÓRIOS\n");
    printf("              Jogo War - Nível Novato\n");
    printf("========================================\n\n");
    
    printf("Por favor, preencha os dados dos 5 territórios:\n\n");
    
    // Laço para preencher os dados de cada território
    for (int i = 0; i < QUANTIDADE_TERRITORIOS; i++) {
        printf("--- TERRITÓRIO %d ---\n", i + 1);
        
        // Entrada do nome do território
        printf("Digite o nome do território: ");
        scanf("%29s", territorios[i].nome);  // %29s para evitar overflow (máximo 29 caracteres)
        
        // Entrada da cor do exército
        printf("Digite a cor do exército: ");
        scanf("%9s", territorios[i].cor);    // %9s para evitar overflow (máximo 9 caracteres)
        
        // Entrada da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        printf("\n");
    }
    
    // FASE 2: EXIBIÇÃO DOS DADOS CADASTRADOS
    printf("\n========================================\n");
    printf("      TERRITÓRIOS CADASTRADOS COM SUCESSO\n");
    printf("========================================\n\n");
    
    // Laço para exibir os dados de cada território
    for (int i = 0; i < QUANTIDADE_TERRITORIOS; i++) {
        printf("TERRITÓRIO %d:\n", i + 1);
        printf("  Nome:    %s\n", territorios[i].nome);
        printf("  Cor:     %s\n", territorios[i].cor);
        printf("  Tropas:  %d\n", territorios[i].tropas);
        printf("----------------------------------------\n");
    }
    
    printf("\nPrograma finalizado com sucesso!\n");
    
    return 0;
}
