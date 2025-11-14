#include "../0 - Headers/header.h"

#define MAX 6  // número máximo de vértices

// ==============================
// Estruturas de dados
// ==============================

// Grafo representado por lista de adjacência
typedef struct {
  int lista[MAX][MAX];       // matriz de conexões
  int visitado[MAX];        // vetor de vértices visitados
} Grafo;

// Estrutura de pilha
typedef struct {
  int itens[MAX];
  int topo;
} Pilha;


// ==============================
// Funções da Pilha
// ==============================

void inicializaPilha(Pilha *p) {
  p->topo = 0;
}

int pihaVazia(Pilha *p) {
  return p->topo==0;
}

void empilha(Pilha *p, int valor) {
  if (p->topo < MAX){
    p->itens[p->topo] = valor;
    p->topo = p->topo+1;
  }
  else
  printf("Fila cheia!\n");
}

int desempilha(Pilha *p) {
  if (!pihaVazia(p)){
    p->topo = p->topo - 1;
    return p->itens[p->topo];
  }
  else {
    printf("Fila vazia!\n");
    return -1;
  }
}

// ==============================
// Busca em Profundidade
// ==============================

void DFS(Grafo* g, int inicio) {
  Pilha p;
  inicializaPilha(&p);

  empilha(&p, inicio);
  g->visitado[inicio] = 1;    // marca como visitado

  printf("DFS a partir do vértice %d: ", inicio);

  int atual;
  while(pilhaVazia(&p) == 0){
    atual = desempilha(&p);  //retira um elemento da pilha
    printf("%d ", atual);      // imprime o elemento

    // para cada vizinho do nó atual
    for(int i=0; i<MAX; i++){
      if(g->lista[atual][i] != 0 && g->visitado[i] == 0){
        g->visitado[i] = 1;
        empilha(&p, i);
      }
    }

  }
  return;
}


// ==============================
// Programa principal (exemplo)
// ==============================

int main() {
  Grafo g = {
    { //vizinhança
      {0, 0, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}
    },
    //visitados
    {0, 0, 0, 0, 0, 0}
  };

  //BFS(&g, 0);
  DFS(&g, 0);

  return 0;
}
