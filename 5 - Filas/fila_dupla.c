#include "./0 - Headers/header.h"

typedef struct{
  int matricula;
  char nome[30];
  float n1,n2,n3;
} aluno;

typedef struct elemento{
  aluno dados;
  struct elemento *prox;
  struct elemento *ant;
} elemento;

typedef struct{
  elemento *inicio;
  elemento *final;
  int qtd;
} deque;

// insere novo elemento
int insere_inicio(deque* d, aluno al){

  // se deque nulo ou não consegue alocar
  if(d == NULL)
  return 0;
  elemento *no = (elemento*) malloc(sizeof(elemento));
  if(no == NULL)
  return 0;
  no->dados = al;
  no->prox = NULL;
  no->ant = NULL;

  // se deque vazio inicio e fim apontam pro novo
  if (d->qtd == 0){
    d->inicio = no;
    d->final = no;
  }
  // senão:
  else{
    no->prox = d->inicio;
    d->inicio->ant = no;
    d->inicio = no;
  }
  d->qtd++;
  return 1;
}

// remove elemento do final do deque
void remove_final(deque *d){
  if(d == NULL || d->qtd == 0)
  return;

  elemento *temp = d->final;
  printf("removendo: %s\n", temp->dados.nome);

  // destroi o único elemento e atuliza ponteiros
  if (d->qtd == 1){
    free(temp);
    d->inicio = NULL;
    d->final = NULL;
  }
  else{
    d->final = d->final->ant;
    d->final->prox = NULL;
    free(temp);
  }
  d->qtd--;
}

// exercicio: adiciona elemento na segunda posição
int adiciona_segunda(deque *d, aluno a){

  // se deque nulo ou não consegue alocar
  if(d == NULL || d->qtd < 1)
  return 0;
  elemento *no = (elemento*) malloc(sizeof(elemento));
  if(no == NULL)
  return 0;
  no->dados = a;

  // adiciona na última posição
  if (d->qtd == 1){

  }
  else{

  }
}


int main(){
  char nomes[5][20] = {"ana", "bia", "caio", "ze", "ju"};
  aluno a;
  deque d;
  d.final = NULL;
  d.inicio = NULL;
  d.qtd = 0;

  for (int i=0; i<5; i++){
    strcpy(a.nome, nomes[i]);
    insere_inicio(&d, a);
  }

  strcpy(a.nome, "val");
  adiciona_segunda(&d, a);

  while(d.inicio != NULL){
    remove_final(&d);
  }

}
