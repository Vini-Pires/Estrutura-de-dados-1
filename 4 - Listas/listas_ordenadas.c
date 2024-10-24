#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 40;

typedef struct objeto {
  char nome[40];
  int idade;
  int cpf;
  int ordem;
  struct objeto *prox;
} OBJETO;

typedef struct {
  OBJETO *topo;
  int qntd_objts;
} LISTA_ORDENADA;

void inicializa();
int tamanho();
bool estaVazia();
void inserir();
void remover();
OBJETO *pesquisar();
void destruir();
void imprimeLista();

int main() {
  LISTA_ORDENADA l;

  inicializa(&l);

  return EXIT_SUCCESS;
}

void inicializa(LISTA_ORDENADA *lista) {
  lista->topo == NULL;
  lista->qntd_objts == 0;
}

int tamanho(LISTA_ORDENADA *lista) { return (lista->qntd_objts); }

bool estaVazia(LISTA_ORDENADA *lista) { return (lista->topo == NULL); }

void imprimeLista(LISTA_ORDENADA lista) {
  if (estaVazia(&lista) == true) {
    perror("Não é possivel imprimir, lista vazia\n");
    return;
  }

  OBJETO *aux = (OBJETO*) malloc(sizeof(OBJETO));
  if (aux == NULL) {
    perror("Erro de alocação de memoria (ImprimeLista):");
    exit(1);
  }

  free(aux);

}

void inserir(LISTA_ORDENADA *lista, char nome[], int idade, int cpf) {
  OBJETO *aux = (OBJETO*) malloc(sizeof(OBJETO));
  if (aux == NULL) {
    perror("Erro de alocação de memoria (Inserir):");
    exit(1);
  }

  if (estaVazia(lista) == true) {
    aux->cpf = cpf;
    aux->idade = idade;
    strcpy(aux->nome, nome);

    aux->prox = lista->topo;
  } else {
    // Usar função pesquisar para inserir ordenadamente
  }

  free(aux);
}
