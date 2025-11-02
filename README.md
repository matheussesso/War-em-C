# War em Linguagem C

Um jogo estratégico implementado em C com sistema de territórios, batalhas e missões.

Este é um projeto educacional que desenvolve o jogo **War** em três níveis de dificuldade:

- **Nível Novato**: Cadastro e exibição de territórios com structs
- **Nível Aventureiro**: Sistema de ataques com alocação dinâmica de memória
- **Nível Mestre**: Missões estratégicas com ponteiros e modularização completa

## Requisitos

- Compilador GCC
- Linux/Unix ou Windows (com MinGW)

## Compilação

```bash
gcc -o war_territorios war_territorios.c
```

## Execução

```bash
./war_territorios
```

## Como Jogar

1. **Defina a quantidade de territórios** a cadastrar
2. **Preencha os dados** de cada território:
   - Nome do território
   - Cor do exército
   - Quantidade de tropas
3. **Receba sua missão estratégica** aleatoriamente
4. **Realize ataques** escolhendo:
   - Qual território ataca
   - Qual território é defendido
5. **Ganhe o jogo** cumprindo sua missão!

## Missões Disponíveis

- Conquistar 3 territórios inimigos
- Eliminar todas as tropas da cor vermelha
- Dominar 50% dos territórios
- Acumular 100 tropas em um único território
- Conquistar o território com mais tropas

## Sistema de Batalha

As batalhas são resolvidas por:
- **Dados de Ataque**: Valor de 1 a 6 para atacante e defensor
- **Vitória do Atacante**: Conquistador assume o território e recebe metade das tropas do atacante
- **Vitória do Defensor**: Atacante perde 1 tropa
- **Empate**: Nenhum efeito, ambos recuam

## Estrutura de Dados

### Struct Territorio
```c
typedef struct {
    char nome[30];      // Nome do território
    char cor[10];       // Cor do exército
    int tropas;         // Quantidade de tropas
} Territorio;
```

## Funções Principais

- `cadastrarTerritorios()` - Entrada de dados dos territórios
- `exibirTerritorios()` - Exibe o estado do mapa
- `atacar()` - Simula uma batalha entre dois territórios
- `atribuirMissao()` - Sorteia uma missão para o jogador
- `verificarMissao()` - Verifica se a missão foi cumprida
- `liberarMemoria()` - Libera memória alocada dinamicamente

## Gerenciamento de Memória

O programa usa:
- `calloc()` para alocar vetores de territórios
- `malloc()` para alocar strings de missões
- `free()` para liberar toda a memória ao final

## 📝 Notas

- Todos os ataques são validados (não é possível atacar territórios aliados)
- As missões são escolhidas aleatoriamente e são únicas para cada jogo
- O programa é modularizado com funções específicas para cada tarefa
- Código comentado e bem estruturado para fins educacionais
