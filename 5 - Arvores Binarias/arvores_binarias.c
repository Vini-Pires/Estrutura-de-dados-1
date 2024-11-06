#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noArvore {
  int chave;
  // demais infos para representar o objeto
  struct noArvore *esq;
  struct noArvore *dir;
} NO_ARVORE;

typedef struct arvore {
  NO_ARVORE *raiz;
} ARVORE;

/*
[Tarefa]
  Faça os elementos abaixo
    - inicializar = {Feito}
    - estaVazio = {Feito}
*/
void inicializar();
bool estaVazio();

int main (void) {
  ARVORE *a;
  inicializar(a);

  return EXIT_SUCCESS;
}

void inicializar(ARVORE **raiz) { (*raiz) = NULL; }

bool estaVazio(ARVORE **raiz) { return ((*raiz) == NULL); }
