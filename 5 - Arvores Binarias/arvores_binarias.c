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

[2]
  implementar
    buscarElemento(&raiz, 38)

[Tipos de pergunta de prova]
  quantos nos filhos tem essa arvore
  quantos no com um unico filho tem na arvore
*/
void inicializar();
bool estaVazio();
void inserir();
void preOrdem();
void emOrdem();
void posOrdem();

int main (void) {
  ARVORE *raiz;
  inicializar(&raiz);

  inserir(&raiz, 65);
  inserir(&raiz, 42);
  inserir(&raiz, 51);
  inserir(&raiz, 32);
  inserir(&raiz, 12);
  inserir(&raiz, 38);
  inserir(&raiz, 80);
  inserir(&raiz, 92);
  inserir(&raiz, 71);
  inserir(&raiz, 42);
  inserir(&raiz, 69);
  inserir(&raiz, 90);

  preOrdem(&raiz);
  printf("\n");
  emOrdem(&raiz);
  printf("\n");
  posOrdem(&raiz);
  printf("\n");

  return EXIT_SUCCESS;
}

void inicializar(NO_ARVORE **no) { (*no) = NULL; }

bool estaVazio(NO_ARVORE **no) { return ((*no) == NULL); }

void inserir(NO_ARVORE **no, int ch) {

  if (estaVazio(no)) {
    (*no) = (NO_ARVORE*) malloc(sizeof(NO_ARVORE));

    if ((*no) == NULL){
      perror("Erro de alocação de memoria (Inserir)");
      exit(1);
    }

    (*no)->chave = ch;
    (*no)->esq = NULL;
    (*no)->dir = NULL;
    return;
  }

  // Neste exemplo
  // Não podera ter uma chave repitida
  if ((*no)->chave == ch) { return; }
  if ((*no)->chave < ch) { inserir( &( (*no)->dir ), ch); }
  else if ((*no)->chave > ch) { inserir( &( (*no)->esq ), ch); }
}

void preOrdem(NO_ARVORE **no) {
  if (estaVazio(no)) { return;}
  printf(" %d ", (*no)->chave);
  preOrdem(&(*no)->esq);
  preOrdem(&(*no)->dir);
}

void emOrdem(NO_ARVORE **no) {
  if (estaVazio(no)) { return; }
  emOrdem(&((*no)->esq));
  printf(" %d ", (*no)->chave);
  emOrdem(&((*no)->dir));
}

void posOrdem(NO_ARVORE **no) {
  if (estaVazio(no)) { return; }
  posOrdem(&((*no)->esq));
  posOrdem(&((*no)->dir));
  printf(" %d ", (*no)->chave);
}
