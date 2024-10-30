#include <stdio.h>

typedef struct objeto {
  int cpf;
  int idade;
  char nome[30];
  // demais infos
  struct objeto *esq;
  struct objeto *dir;
} OBJETO;
