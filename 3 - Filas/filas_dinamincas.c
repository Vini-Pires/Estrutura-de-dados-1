#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct objeto {
  int cpf;
  int idade;
  char nome[30];
  struct objeto *prox;
} OBJETO;

typedef struct {
  OBJETO *fim_da_fila;
  OBJETO *topo_da_fila;
  int qntd_elementos;
} FILA_DINAMICA;

// ----------------------------------------------------------------------

void inicializarFila();
bool estaVazia();
int tamanhoFila();
void inserirFila();
void imprimeInicio();
void excluirObjeto();
// fazer imprimeUltimo
void destruirFila();

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

int main () {

  FILA_DINAMICA fila;
  inicializarFila(&fila);
  inserirFila(&fila, 5555, 16, "John Doe");
  imprimeInicio(&fila);

  destruirFila(&fila);
  return EXIT_SUCCESS;
}

// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------

void inicializarFila(FILA_DINAMICA *f) {
  f->qntd_elementos = 0;
  f->fim_da_fila = NULL;
  f->topo_da_fila = NULL;
}

// ----------------------------------------------------------------------

bool estaVazia(FILA_DINAMICA *f) {
  return f->qntd_elementos == 0;
}

// ----------------------------------------------------------------------

int tamanhoFila(FILA_DINAMICA *f) {
  return f->qntd_elementos;
}

void inserirFila(FILA_DINAMICA *f, int cpf, int idade, char nome[]) {
  // Preciso alocar memoria pra esse novo objeto
  // do contrario ao sair da função ira apagar todos os dados desse novo objeto
  OBJETO *novo = (OBJETO*) malloc(sizeof(OBJETO));
  if(novo == NULL){
    perror("Erro de alocação de memória\n");
    return;
  }

  novo->cpf = cpf;
  novo->idade = idade;
  strcpy(novo->nome, nome);
  novo->prox = NULL;

  // verifica se a fila esta vazia
  if (estaVazia(f) == false) {
    // se estiver adiciona as novas informações no topo da fila
    f->topo_da_fila = novo;
  } else {
    // caso não vazio, o fim da fila ira adicionar a direção do novo objeto
    f->fim_da_fila->prox = novo;
  }

  f->qntd_elementos++;
  f->fim_da_fila = novo;
}

void imprimeInicio(FILA_DINAMICA *f) {
  if (estaVazia(f) == true) {
    printf("Esta vazia\n");
    return;
  }

  printf("| Nome: %s | CPF: %d | Idade: %d |\n",
    f->topo_da_fila->nome,
    f->topo_da_fila->cpf,
    f->topo_da_fila->idade
  );
}

void excluirObjeto(FILA_DINAMICA *f) {
  if (estaVazia(f) == true) {
    printf("Não há oque excluir\n");
    return;
  }

  OBJETO *aux = f->topo_da_fila;

  f->topo_da_fila = aux->prox;
  f->qntd_elementos--;
  // caso precise imprima as info do objeto q ira sair (aux)
  free(aux);
  if(f->topo_da_fila==NULL) f->fim_da_fila=NULL; //analisar
}

void destruirFila(FILA_DINAMICA *f) {
  while (estaVazia(f) == false) {
    excluirObjeto(f);
  }
  inicializarFila(f);
}
