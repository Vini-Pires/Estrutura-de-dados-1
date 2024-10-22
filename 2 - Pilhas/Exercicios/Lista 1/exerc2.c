/*
  [Pilha Dinâmica]

  Elabore um programa em C implementando uma Pilha Dinâmica que armazene N numeros
  da sequência de Fibonacci, onde N sera um valor recebido pelo usuario e devera estar contido entre:
    5 < N < 20.

    •Usuario fornece um valor (entre 5 < N < 20), por exemplo, N = 10

    •Elementos da Pilha (nesta ordem) { 34, 21, 13, 8, 5, 3, 2, 1, 1, 0 }

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct objeto{
  int fibonacci_num;
  struct objeto *anterior;
}OBJETO;

typedef struct {
  OBJETO *topo;
  int qntd_objetos;
} PILHA_DINAMICA;

void inicializarPilha();
bool estaVazia();
int tamanhoPilha();
void inserirTopo();
void removerTopo();
OBJETO *topoPilha();
void imprimirTopo();
void destruirPilha();
int coletaNumero();
void fibonacci();

int main() {
  PILHA_DINAMICA p;

  inicializarPilha(&p);
  // fibonacci(&p, 3);
  inserirTopo(&p, 555);

  destruirPilha(&p);

  return EXIT_SUCCESS;
}

void inicializarPilha(PILHA_DINAMICA *pilha) {
  pilha->topo = NULL;
  pilha->qntd_objetos = 0;
}

bool estaVazia(PILHA_DINAMICA *pilha) { return pilha->qntd_objetos == 0; }

int tamanhoPilha(PILHA_DINAMICA *pilha) { return pilha->qntd_objetos; }

void inserirTopo(PILHA_DINAMICA *pilha, int numero_recebido) {
  OBJETO *aux = (OBJETO*) malloc(sizeof(OBJETO));
  if(aux == NULL) {
    perror("Não foi possivel alocar memoria (inserirPilha)");
    return;
  }

  aux->fibonacci_num = numero_recebido;

  aux->anterior = pilha->topo;
  pilha->topo = aux;

  pilha->qntd_objetos++;

  free(aux);
}

void removerTopo(PILHA_DINAMICA *pilha) {
  OBJETO *aux = pilha->topo;
  if (aux == NULL) {
    perror("Pilha aux vazia (removerPilha)");
    exit(1);
  }

  pilha->topo = aux->anterior;
  pilha->qntd_objetos--;
  free(aux);
}

void destruirPilha(PILHA_DINAMICA *pilha) {
  while (!estaVazia(pilha)) {
    removerTopo(pilha);
  }
}

OBJETO *topoPilha(PILHA_DINAMICA *pilha) {
  return pilha->topo;
}

void imprimeTopo (PILHA_DINAMICA *pilha) {
  if (estaVazia(pilha) == true) {
    printf("\nA pilha estah vazia");
    return;
  }

  printf("\n==============================\n");
  printf("num: %d", pilha->topo->fibonacci_num);
  printf("\n==============================\n");
}

int coletaNumero() {
  int qnt_elementos;
  do {
    printf("Quantos elementos na sua sequencia de fibonacci? [4, 20): ");
    scanf("%d", &qnt_elementos);
  } while (qnt_elementos < 5 || qnt_elementos > 20);
  return qnt_elementos;
}

void fibonacci (PILHA_DINAMICA *pilha, int numeros_de_termos) {
  PILHA_DINAMICA aux;
  inicializarPilha(&aux);

  // Calcular a sequência de Fibonacci e inserir na pilha auxiliar
  int primeiroTermo = 0, segundoTermo = 1, proximoTermo;
  imprimeTopo(&aux);
  inserirTopo(&aux, primeiroTermo);
  imprimeTopo(&aux);
  inserirTopo(&aux, segundoTermo);
  for (int i = 2; i < numeros_de_termos; i++) {
    proximoTermo = primeiroTermo + segundoTermo;
    inserirTopo(&aux, proximoTermo);
    primeiroTermo = segundoTermo;
    segundoTermo = proximoTermo;
  }

  // Inverter a pilha auxiliar para a pilha principal
  while (!estaVazia(&aux)) {
    inserirTopo(pilha, topoPilha(&aux)->fibonacci_num);
    removerTopo(&aux);
  }

  destruirPilha(&aux);
}
