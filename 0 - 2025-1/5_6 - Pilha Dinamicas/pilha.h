#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilha {
    int dado;
    struct NoPilha* proximo;
} NoPilha;

typedef struct {
    NoPilha* topo;
    int tamanho;
} Pilha;

void inicializar(Pilha* p);
bool estaVazia(Pilha* p);
void inserir(Pilha* p, int d);
int remover(Pilha* p);
void exibir(Pilha* p);

#endif