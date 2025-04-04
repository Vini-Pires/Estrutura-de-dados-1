#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct objeto {
  int CPF;
  char nome[30];
  int idade;
  // ^-- demais infos --^
  struct objeto *prox;
} OBJETO;

typedef struct {
  OBJETO *topo;
  int qtde_elementos;
} PILHA_DINAMICA;

void inicializaPilha (PILHA_DINAMICA *pilha) {
  pilha->qtde_elementos = 0;
  pilha->topo = NULL;
}

bool estaVazia (PILHA_DINAMICA *pilha) {
  return pilha->qtde_elementos == 0;
  /*
    - pd ser usado caso n haja uma variável q armazena a qntd de elementos
    - verifica se o topo da pilha é vazio

    // return pilha->topo == NULL;
  */
}

int tamanhoPilha (PILHA_DINAMICA *pilha) {
  return pilha->qtde_elementos;
}

void empilha (PILHA_DINAMICA *pilha, int cpf, char nome[], int idade) {
  OBJETO *aux = (OBJETO*) malloc(sizeof(OBJETO));

  if (aux == NULL) {
    printf("\nNao foi possivel alocar memoria para o novo elemento\n");
    return;
  }

  aux->CPF = cpf;
  aux->idade = idade;
  strcpy(aux->nome, nome);

  aux->prox = pilha->topo;
  pilha->topo = aux;

  pilha->qtde_elementos++;

  free(aux);
}

OBJETO* topoPilha (PILHA_DINAMICA *pilha) {
  return pilha->topo;
}

void desempilha (PILHA_DINAMICA *pilha) {
  OBJETO *aux = pilha->topo;
  if (aux == NULL) {
    printf("A pilha está vazia");
    return;
  }

  pilha->topo = aux->prox;
  pilha->qtde_elementos--;
  free(aux);
}

void imprimeTopo (PILHA_DINAMICA *pilha) {
  if (estaVazia(pilha) == true) {
    printf("\nA pilha estah vazia");
    return;
  }

  printf("\n==============================\n");
  printf("Nome: %s  |  CPF: %d  |  idade: %d  ",
    pilha->topo->nome,
    pilha->topo->CPF,
    pilha->topo->idade
  );
  printf("\n==============================\n");
}

void destruirPilha (PILHA_DINAMICA *pilha) {
  while (estaVazia(pilha) == false) {
    desempilha(pilha);
  }
}

int main () {
  PILHA_DINAMICA p;

  inicializaPilha(&p);
  empilha(&p, 12345, "Maria do Carmo", 50);
  empilha(&p, 54321, "Joao Jose", 30);
  empilha(&p, 78945, "Luana da Silva", 21);
  empilha(&p, 65478, "Marcio Renato", 48);
  desempilha(&p);

  imprimeTopo(&p);

  destruirPilha(&p);

  return EXIT_SUCCESS;
}
