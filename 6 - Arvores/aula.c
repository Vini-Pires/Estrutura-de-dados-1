#include "../0 - Headers/header.h"

typedef struct no {
  char info;
  struct no *esq;
  struct no *dir;
} NO;

void preOrdem();
void emOrdem();
void posOrdem();
int qntdElementos();

/*

       A
      / \
     B   C
    / \
   D   E

*/

// --------------------------------------------------------------

int main(void){
  NO A = {'A', NULL, NULL};
  NO B = {'B', NULL, NULL};
  NO C = {'C', NULL, NULL};
  NO D = {'D', NULL, NULL};
  NO E = {'E', NULL, NULL};
  A.esq = &B;
  A.dir = &C;
  B.esq = &D;
  B.dir = &E;

  // printf("Pre Ordem:\n");
  // preOrdem(&A);
  // printf("-----------------\n");
  // printf("Em Ordem:\n");
  // emOrdem(&A);
  // printf("-----------------\n");
  // printf("Pos Ordem:\n");
  // posOrdem(&A);
  // printf("-----------------\n");

  printf("Quantidade de Nos: %d\n", qntdElementos(&A));

  return 0;
}

// --------------------------------------------------------------

int qntdElementos(NO *r){

  if(r == NULL) {
    return 0;
  } else {
    int nos_esq = qntdElementos(r->esq);
    int nos_dir = qntdElementos(r->dir);
    return nos_dir + nos_esq + 1;
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
