#include "lista.h"

// Inicializa a lista
void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
}

// Verifica se a lista est� vazia
int isListaVazia(Lista* lista) {
    return lista->cabeca == NULL;
}

// Insere um novo n� no final da lista
void inserirNaLista(Lista* lista, int valor) {
    adicionarEm(lista, valor, -1); // -1 indica inser��o no final
}

// Adiciona um n� em uma posi��o espec�fica da lista
void adicionarEm(Lista* lista, int valor, int posicao) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar mem�ria!\n");
        return;
    }
    novo->dado = valor;
    novo->prox = NULL;

    // Inser��o no in�cio
    if (posicao == 0 || isListaVazia(lista)) {
        novo->prox = lista->cabeca;
        lista->cabeca = novo;
        return;
    }

    No* atual = lista->cabeca;
    No* anterior = NULL;
    int indice = 0;

    // Percorre a lista at� a posi��o desejada ou o final da lista
    while (atual != NULL && (posicao < 0 || indice < posicao)) {
        anterior = atual;
        atual = atual->prox;
        indice++;
    }

    // Inser��o no meio ou no final
    novo->prox = atual;
    anterior->prox = novo;
}

// Remove um n� da lista pelo valor
void removerNoLista(Lista* lista, int valor) {
    No* atual = lista->cabeca;
    No* anterior = NULL;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d n�o encontrado na lista.\n", valor);
        return;
    }

    if (anterior == NULL) {  // Remover o primeiro n�
        lista->cabeca = atual->prox;
    }
    else {  // Remover n� intermedi�rio ou final
        anterior->prox = atual->prox;
    }

    free(atual);
}

// Busca um n� pelo valor e retorna um ponteiro para ele
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

// Libera toda a mem�ria alocada pela lista
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->cabeca = NULL;
}
