#include "../0 - Headers/header.h"

#define MAX 4

/* Tarefa:

Qual a linha com maior numero de vizinhos?

*/

typedef struct _no {
  int vertice;
  struct _no* prox;
} NO;

void criar_aresta();
int existe_conexao();
void imprime_vizinhos();

int main(void) {
  NO *grafo[MAX] = {0};

  criar_aresta(grafo, 0, 1);
  criar_aresta(grafo, 1, 0);
  criar_aresta(grafo, 1, 3);
  criar_aresta(grafo, 2, 1);
  criar_aresta(grafo, 2, 2);
  criar_aresta(grafo, 2, 3);
  criar_aresta(grafo, 3, 2);

  printf("Conexão 2->1: %d\n", existe_conexao(grafo, 2, 1));
  printf("Conexão 2->0: %d\n", existe_conexao(grafo, 2, 0));

  imprime_vizinhos(grafo);

  return 0;
}

// ---------------------------------------------------------
// ---------------------------------------------------------
// ---------------------------------------------------------

/**
* @brief cria as conexões entre os nós
*
* @param g     lista com o grafo
* @param org   origem da conexão
* @param dest  destino da conexão
* @return int
*/
void criar_aresta(NO* g[MAX], int org, int dest) {

  NO* novo = (NO *)malloc(sizeof(NO));
  novo->vertice = dest;

  novo->prox = g[org]; // novo nó aponta para origem
  g[org] = novo; // origem agora eh o nó novo

  return;
}

/**
* @brief verifica se existe conexão entre um par de nó
*
* @param g     lista de grafos
* @param org   origem da conexão
* @param dest  destino da conexão
* @return int  retorna 1 se existe conexão e -1 caso não exista
*/
int existe_conexao(NO* g[MAX], int org, int dest) {
  NO* temp = g[org];

  while(temp != NULL) {
    if (temp->vertice == dest) {
      return 1;
    }

    temp = temp->prox;
  }

  return 0;
}

void imprime_vizinhos(NO* g[MAX]){
  printf("\nvizinhos\n");
  for(int origem = 0; origem < MAX; origem++){
    printf("No %d:", origem);

    NO* temp = g[origem];
    while(temp != NULL){
      printf(" %d", temp->vertice);
      temp = temp->prox;
    }
    printf("\n");
  }

  //printf("No 0: 1");
  //printf("No 1: 3 0");
  //printf("No 2: 3 2 1");
  //printf("No 3: 2");
}

