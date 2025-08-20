#include "lista.h"

// Inicializa a lista
void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
}

// Verifica se a lista está vazia
int isListaVazia(Lista* lista) {
    return lista->cabeca == NULL;
}

// Insere um novo nó no final da lista
void inserirNaLista(Lista* lista, int valor) {
    adicionarEm(lista, valor, -1); // -1 indica inserção no final
}

// Adiciona um nó em uma posição específica da lista
void adicionarEm(Lista* lista, int valor, int posicao) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->dado = valor;
    novo->prox = NULL;

    // Inserção no início
    if (posicao == 0 || isListaVazia(lista)) {
        novo->prox = lista->cabeca;
        lista->cabeca = novo;
        return;
    }

    No* atual = lista->cabeca;
    No* anterior = NULL;
    int indice = 0;

    // Percorre a lista até a posição desejada ou o final da lista
    while (atual != NULL && (posicao < 0 || indice < posicao)) {
        anterior = atual;
        atual = atual->prox;
        indice++;
    }

    // Inserção no meio ou no final
    novo->prox = atual;
    anterior->prox = novo;
}

// Remove um nó da lista pelo valor
void removerNoLista(Lista* lista, int valor) {
    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    if (anterior == NULL) {  // Remover o primeiro nó
        lista->cabeca = atual->prox;
    }
    else {  // Remover nó intermediário ou final
        anterior->prox = atual->prox;
    }

    free(atual);
}

// Busca um nó pelo valor e retorna um ponteiro para ele
No* encontrarNo(Lista* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Exibe os elementos da lista
void exibirLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Libera toda a memória alocada pela lista
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->cabeca = NULL;
}
