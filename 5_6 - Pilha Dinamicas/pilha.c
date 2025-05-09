#include "pilha.h"

void inicializar(Pilha* p){
    p->topo = NULL;
    p->tamanho = 0;
}

bool estaVazia(Pilha* p){
    return p->tamanho == 0;
}

void inserir(Pilha* p, int d){
    // cria no auxiliar
    NoPilha* aux = (NoPilha*) malloc(sizeof(NoPilha));
    
    // atribui valor
    aux->dado = d;
    aux->proximo = p->topo;

    /// atualiza o topo
    p->topo = aux;
    p->tamanho = p->tamanho + 1;
}

int remover(Pilha* p){
    if (estaVazia(p)){
        printf("Pilha vazia!\n");
        return -9999;
    }

    // auxiliar salva topo atual
    NoPilha* aux = p->topo;
    int x = aux->dado;

    // atualizar o topo
    p->topo = aux->proximo;

    // liberar memória do aux
    free(aux);

    // decrementar tamanho
    p->tamanho = p->tamanho - 1;

    // retorna dado
    return x;
}

void exibir(Pilha* p){
    if (estaVazia(p)){
        printf("Pilha vazia!\n");
        return;
    }

    NoPilha* aux = p->topo;

    printf("Exibindo Pilha:\n");
    while(aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->proximo;
    }
}