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

[Metodo usado para destruir]
  usar metodo posOrdem de navegação


*/
void inicializar();
bool estaVazio();
void inserir();
void preOrdem();
void emOrdem();
void posOrdem();
void destruir();
void remover();


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
  inserir(&raiz, 34);

  // preOrdem(&raiz);
  // printf("\n");
  // emOrdem(&raiz);
  // printf("\n");
  // posOrdem(&raiz);
  // printf("\n");

  remover(&raiz, 92);
  remover(&raiz, 92);
  remover(&raiz, 90);
  remover(&raiz, 90);


  destruir(&raiz);

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

void destruir(NO_ARVORE **no) {
  if (estaVazio(&(*no))) { return; }

  destruir(&((*no)->esq));
  destruir(&((*no)->dir));
  free(*no);
  (*no) = NULL;
}

void remover(NO_ARVORE **no, int ch) {
  // Caso 0 : Elemtento não encontrado

  if (estaVazio(&(*no))) {
    printf("Elemento não esta na arvore (%d)\n\n", ch);
    return;
  }

  if ((*no)->chave == ch) {
    // Caso 1 : Elemtento é nó folha
    if ((*no)->esq == NULL && (*no)->dir == NULL) {
      free(*no);
      (*no) = NULL;
      printf("Elemento Removido %d\n", ch);
      return;
    }

    // Caso 2A: Elemtento só tem filho a esquerda
    if ((*no)->esq != NULL && (*no)->dir == NULL) {
      NO_ARVORE *aux = (*no)->esq;
      free(*no);
      (*no) = aux;
      printf("Elemento a esquerda removido %d, e novo ocupa seu lugar %d\n",
        ch,
        (*no)->chave
      );
      return;
    }

    // Case 2B: Elemtento só tem filho a direita
    if ((*no)->esq == NULL && (*no)->dir != NULL) {
      NO_ARVORE *aux = (*no)->dir;
      free(*no);
      (*no) = aux;
      printf("Elemento a direita removido (%d), e novo ocupa seu lugar (%d)",
        ch,
        (*no)->chave
      );
      return;
    }

    // Caso 3 : Elemento tem os dois filhos
    if ((*no)->esq != NULL && (*no)->dir != NULL) { // esse [if] é redundante
      // [O que fazer???]
      /*
        remover 42, ele possui 2 filhos
        possui o 38 como maior elemento da subarvore da esquerda
        possui o 51 como menor elemento da subarvore da direita
      */
      NO_ARVORE *subEsq = (*no)->esq;
      while (subEsq->dir != NULL) {
        subEsq = subEsq->dir;
      }
      (*no)->chave = subEsq->chave;
      remover((*no)->esq, subEsq->chave);
      return;
    }

  } else {
    // metodo de pesquisa
    if((*no)->chave > ch) {
      remover(&((*no)->esq), ch);
    } else {
      remover(&((*no)->dir), ch);
    }
  }

}
