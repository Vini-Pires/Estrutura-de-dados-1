#include <stdio.h>
#include <string.h>
#include "lista.h"

typedef struct {
    int id;
    char nome[50];
} Jogador;

// Adiciona um jogador ao ranking
void adicionarJogador(Lista* ranking, int id, char* nome, int posicao) {
    printf("Adicionando jogador: %s (ID %d) na posição %d...\n", nome, id, posicao);
    inserirNaLista(ranking, id);
}

// Remove um jogador do ranking
void removerJogador(Lista* ranking, int id) {
    printf("Removendo jogador com ID %d...\n", id);
    removerNoLista(ranking, id);
}

// Exibe o ranking atualizado
void exibirRanking(Lista* ranking) {
    printf("Ranking Atual:\n");
    exibirLista(ranking);
}

int main() {
    Lista ranking;
    inicializarLista(&ranking);

    printf("BEM-VINDO AO SIMULADOR DE RANKING DE eSPORTS!\n\n");

    adicionarJogador(&ranking, 101, "Lucas Killer", 0);
    adicionarJogador(&ranking, 102, "Ana Sniper", 1);
    adicionarJogador(&ranking, 103, "Rafa Rush", 2);
    adicionarJogador(&ranking, 104, "Duda Destroyer", 3);

    exibirRanking(&ranking);

    printf("\nProcurando jogador com ID 102...\n");
    No* encontrado = encontrarNo(&ranking, 102);
    if (encontrado) {
        printf("Jogador encontrado: ID %d\n", encontrado->dado);
    }
    else {
        printf("Jogador não encontrado!\n");
    }

    printf("\nAna Sniper perdeu a posição! Removendo do ranking...\n");
    removerJogador(&ranking, 102);
    exibirRanking(&ranking);

    printf("\nNovo desafiante entra no top 3!\n");
    adicionarJogador(&ranking, 105, "Bruno Beast", 2);
    exibirRanking(&ranking);

    printf("\nRANKING FINAL APÓS AJUSTES:\n");
    exibirRanking(&ranking);

    liberarLista(&ranking);
    printf("FIM DO TORNEIO!\n");

    return 0;
}
