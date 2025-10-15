#include "../0 - Headers/header.h"

typedef struct NO{
  int info;
  int bf;
  struct NO *esq;
  struct NO *dir;
} NO;


void print_posOrdem(NO *raiz){
  if(raiz == NULL)
  return;
  if(raiz != NULL){
    print_posOrdem(raiz->esq);
    print_posOrdem(raiz->dir);
    printf("info: %d, bf: %d \n", raiz->info, raiz->bf);
  }
}

int altura(NO *raiz) {
  // se a raiz for nula
  if (raiz == NULL) {
    return 0;
  }

  // altura das sub-arvores
  int hd = altura(raiz->dir);
  int he = altura(raiz->esq);
  raiz->bf = hd - he;


  // retorna a altura mais 1
  if (hd > he) {
    return hd + 1;
  } else {
    return he + 1;
  }

}

NO* rot_esq (NO *raiz) {
  NO *p = raiz;
  NO *u = raiz->dir;
  NO *beta = u->esq;

  u->esq = p;
  p->dir = beta;

  return u;
}

NO* rot_dir(NO* raiz) {

  NO *p = raiz;
  NO *u = raiz->esq;
  NO *alfa = u->dir;

  u->dir = p;
  p->esq = alfa;

  return u;
}

int main(){
  NO x[3] = {{1, 0, NULL, NULL},
  {2, 0, NULL, NULL},
  {3, 0, NULL, NULL}};

  x[0].dir = &x[1];
  x[1].dir = &x[2];
  NO *r = &x[0];


  printf("\n");
  printf("Calcula fator de balanceamento");
  printf("\n");

  altura(r);

  print_posOrdem(r);

  printf("Rotaciona para esquerda:\n");
  r = rot_esq(r);

  printf("\n");
  printf("Calcula fator de balanceamento");
  printf("\n");
  altura(r);
  print_posOrdem(r);



  return 0;
}
