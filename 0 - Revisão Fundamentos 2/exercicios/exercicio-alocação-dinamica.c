#include <stdlib.h>
#include <stdio.h>

typedef struct ponto {
  int x, y, z;
}PONTO;

int digitaPontos () {
  int num = NULL;
  printf("\n");
  printf("Digite a quantidade de pontos: ");
  scanf("%d", &num);
  printf("\n\n");

  return num;
}

void preencherPontos (PONTO *p, int qntd) {
  for (int i=0; i < qntd; i++) {
    p[i].x = i;
    p[i].y = i + 1;
    p[i].z = i + 2;
  }
}

void exibePontos (PONTO *p, int qntd) {
  for (int i = 0; i < qntd; i++) {
    printf("Ponto %d:\nx: %d\ny:%d\nz: %d\n", i+1, p[i].x, p[i].y, p[i].z);
  }
}

int main () {
  int qntdPontos = 0;
  PONTO *p = NULL;

  qntdPontos = digitaPontos();

  p = (PONTO *) malloc(qntdPontos * sizeof(PONTO));

  preencherPontos(p, qntdPontos);

  exibePontos(p, qntdPontos);

  free(p);

  return EXIT_SUCCESS;
}
