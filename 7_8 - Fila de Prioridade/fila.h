#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct NoFila{
  int prioridade;
  char nome[30];
  struct NoFila* prox;
  struct NoFila* anterior;
} Nofila;

typedef struct Fila{
  
} Fila;

#endif