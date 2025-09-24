#include "../0 - Headers/header.h"

typedef struct no {
  int info;
  struct no *esq;
  struct no *dir;
} NO;

void preOrdem();
void emOrdem();
void posOrdem();
int qtdElementos();
int qtdFolhas();
int somaMenores();

/*
        15
       / \
     25  20
    / \    \
  12  18   27
*/


// --------------------------------------------------------------

int main(void){
  NO x[6] = {
    {15, NULL, NULL},
    {25, NULL, NULL},
    {20, NULL, NULL},
    {12, NULL, NULL},
    {18, NULL, NULL},
    {27, NULL, NULL}
  };

  x[0].esq = &x[1];
  x[0].dir = &x[2];
  x[1].esq = &x[3];
  x[1].dir = &x[4];
  x[2].dir = &x[5];

  // printf("Pre Ordem:\n");
  // preOrdem(&A);
  // printf("-----------------\n");
  // printf("Em Ordem:\n");
  // emOrdem(&A);
  // printf("-----------------\n");
  // printf("Pos Ordem:\n");
  // posOrdem(&A);
  // printf("-----------------\n");

  // printf("Quantidade de Nos: %d\n", qtdElementos(&A));

  printf("Quantidade de folhas: %d\n", qtdFolhas(&x[0]));

  int valorArbitrario = 18;
  printf("Menores que %d: %d\n",
    valorArbitrario,
    somaMenores(&x[0], valorArbitrario)
  );

  return 0;
}

// --------------------------------------------------------------

int qtdElementos(NO *r){

  if(r == NULL) {
    return 0;
  } else {
    int nos_esq = qtdElementos(r->esq);
    int nos_dir = qtdElementos(r->dir);
    return nos_dir + nos_esq + 1;
  }
}

int qtdFolhas(NO *r) {
  if (r == NULL)
    return 0;

  if (r->dir == NULL && r->esq == NULL) {
    return 1;
  } else {
    int folha_esq = qtdFolhas(r->esq);
    int folha_dir = qtdFolhas(r->dir);
    return folha_dir + folha_esq;
  }
}

// soma elementos menores que x
int somaMenores (NO *r, int x) {
  if (r == NULL)
    return 0;

  int tot_esq = somaMenores(r->esq, x);
  int tot_dir = somaMenores(r->dir, x);

  if(r->info < x) {
    return tot_dir + tot_esq;
  } else {
    return tot_dir + tot_esq + r->info;
  }

}

void preOrdem (NO *r) {
  if(r == NULL)
    return;

  if (r != NULL) {
    printf("%c\n", r->info);
    preOrdem(r->esq);
    preOrdem(r->dir);
  }
}

void emOrdem (NO *r) {
  if(r == NULL)
    return;

  if (r != NULL) {
    emOrdem(r->esq);
    printf("%c\n", r->info);
    emOrdem(r->dir);
  }
}

void posOrdem (NO *r) {
  if(r == NULL)
    return;

  if (r != NULL) {
    posOrdem(r->esq);
    posOrdem(r->dir);
    printf("%c\n", r->info);
  }
}
