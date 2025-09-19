#include "./0 - Headers/header.h"

typedef struct {
  int matricula;
  char nome[31];
  int idade;

} Aluno;

typedef struct elemento {
  Aluno dados;
  struct elemento *prox;

} Elemento;

typedef struct{
  Elemento *inicio;
  Elemento *final;
  int qtd;

} Fila;

void init(Fila *f) {
  f->inicio = NULL;
  f->final = NULL;
  f->qtd = 0;

}

void is_null (Elemento *a) {
  if (a == NULL) {
    perror("No Nulo\n");
    exit(1);
  }
}

void push (Fila *f, Aluno al) {
  if (f == NULL) return 0;

  Elemento *no = (Elemento*) malloc(sizeof(Elemento));

  if(no == NULL) {
    return 0;

  }

  no->dados = al;
  no->prox = NULL;

  if(f->qtd == 0){
    f->inicio = no;

  } else {
    f->final->prox = no;

  }

  f->final = no;
  f->qtd++;

  return;
}

void destruct(Fila *f) {
  if (f == NULL || f->qtd == 0) return 0;

  Elemento *temp = f->inicio;

  while (temp != NULL) {
    f->inicio = temp->prox;
    free(temp);
    temp = f->inicio;

    f->qtd--;

  }

  init(f);

}

/* Exercícios sugeridos:
   1 - Percorre fila e calcula a média das idades dos alunos com mais de 15 anos
   2 - Remove ou adiciona elemento com idade específica.
   3 - Remove ou adiciona elemento em posição específica.
*/

// calcula a média das idades maiores do que 15
float avg_older (Fila *f) {

  // se fila nula ou vazia, não faz nada
  if(f == NULL || f->qtd == 0)
      return -1;

  // percorre a fila
  Elemento *temp = f->inicio;
  float cont = 0;
  float acum = 0;
  while(temp != NULL){
    // se idade maior do que 15
    if(temp->dados.idade > 15){
      cont = cont + 1;
      acum = acum + temp->dados.idade;

    }
    temp = temp->prox;

  }

  if(cont == 0){
    return 0;
  }

  return acum/cont;

}

int push_before_last (Fila *f, Aluno a) {
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));
  is_null(no);

  no->dados = a;

  if (f->qtd == 1) {
    no->prox = f->inicio;
    f->inicio = no;
  } else {
    Elemento *temp = f->inicio;
    while(temp->prox != f->final) {
      temp = temp->prox;
    }

    no->prox = f->final;
    temp->prox = no;

  }

  f->qtd++;
}

int main(void){

  // nomes para teste
  char nomes[5][20] = {"ana", "bia", "caio", "ze", "ju"};
  int idades[5] = {10, 12, 19, 13, 20};
  Aluno a;

  // cria e inicializa fila
  Fila f;
  init(&f);

  // insere alguns alunos na fila
  for (int i = 0; i < 5; i++){
    strcpy(a.nome, nomes[i]);
    a.idade = idades[i];
    insere_Fila(&f, a);

  }

  destruct(&f);

  return 0;
}
