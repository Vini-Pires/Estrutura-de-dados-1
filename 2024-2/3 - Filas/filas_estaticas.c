#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define M 5

typedef struct{
  int CPF;
  char nome[30];
  int idade;
  //demais informações
} OBJETO;

typedef struct {
  int tamanho;
  int inicio;
  int fim;
  OBJETO elementos[M];
} FILA_ESTATICA;

void incializaFila();
bool estahVazia();
bool estahCheia();
void insereElementoFila();
void excluiElementoFila();
int tamanhoFila();
void imprimePrimeiroFila();

int main(){
  FILA_ESTATICA fila;

  incializaFila(&fila);
  insereElementoFila(&fila, 12345, "Maria do Carmo", 50);
  insereElementoFila(&fila, 54321, "Joao Jose", 27);
  insereElementoFila(&fila, 45678, "Marcio Renato", 45);
  insereElementoFila(&fila, 45678, "Luana Santos", 18);

  excluiElementoFila(&fila);

  imprimePrimeiroFila(&fila);
  //tarefa: imprimir o ultimo elemento

  return EXIT_SUCCESS;
}

void incializaFila(FILA_ESTATICA *fila){
  fila->tamanho = 0;
  fila->fim = fila->inicio = -1;
}

bool estahVazia(FILA_ESTATICA *fila){
  return fila->tamanho == 0;
}

bool estahCheia(FILA_ESTATICA *fila){
  return fila->tamanho==M;
}

void insereElementoFila(FILA_ESTATICA *fila, int cpf, char nome[], int idade){
  if(estahCheia(fila)==true){
    printf("\nFila cheia! Nao foi possivel add o novo elemento");
    return;
  }

  if(estahVazia(fila) == true){
    fila->inicio = (fila->inicio+1) % M;
  }

  fila->tamanho++;
  fila->fim = (fila->fim+1) % M;

  fila->elementos[fila->fim].CPF = cpf;
  fila->elementos[fila->fim].idade = idade;
  strcpy(fila->elementos[fila->fim].nome, nome);

}

void excluiElementoFila(FILA_ESTATICA *fila){
  if(estahVazia(fila) == true){
    printf("\nFila estah vazia, nao consigo excluir elemento");
    return;
  }

  fila->tamanho--;

  if(estahVazia(fila) == true){
    incializaFila(fila);
    return;
  }

  fila->inicio = (fila->inicio+1) % M;

}

int tamanhoFila(FILA_ESTATICA *fila){
  return fila->tamanho;
}

void imprimePrimeiroFila(FILA_ESTATICA *fila){
  if(estahVazia(fila) == true){
      printf("\nFila Vazia!");
      return;
  }

  printf("\n\n=============\nO primeiro elemento eh:");
  printf(" CPF=%d Nome=%s ",
    fila->elementos[fila->inicio].CPF,
    fila->elementos[fila->inicio].nome
  );
}
