/*
[Incompleto]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct objeto{
  int CPF;
  char nome[30];
  int idade;
  //demais infos
  struct objeto *prox;
} OBJETO;

typedef struct {
  OBJETO *inicio;
  int tamanho;
} LISTA_DINAMICA;

void inicializaLista(LISTA_DINAMICA *lista){
  lista->inicio = NULL;
  lista->tamanho = 0;
}

bool estahVazia(LISTA_DINAMICA *lista){
  return lista->tamanho == 0;
}

int tamanhoLista(LISTA_DINAMICA *lista){
  return lista->tamanho;
}

//obs1: a lista estah ordenada por idade (ordem crescente)
//OBS2: como posso ter mais de um objeto com a mesma idade,
//      pensar em como tratar isso!!!
void insereElementoLista(LISTA_DINAMICA *lista, int cpf, char nome[], int idade){
  OBJETO *novo= (OBJETO*) malloc(sizeof(OBJETO));

  if(novo==NULL){
    printf("\nErro de alocação");
    return;
  }
  novo->CPF=cpf;
  novo->idade=idade;
  strcpy(novo->nome, nome);
  novo->prox=NULL;

  if(estahVazia(lista)==true){
    lista->inicio=novo;
  }
  else{
    if(lista->inicio->idade > idade){
      novo->prox=lista->inicio;
      lista->inicio=novo;
    }
    else{
      OBJETO* aux=lista->inicio;
      while(aux->prox!=NULL && aux->prox->idade > idade){
        aux=aux->prox;
      }
      novo->prox=aux->prox;
      aux->prox=novo;
    }
  }

  lista->tamanho++;
}

int main(void){
  LISTA_DINAMICA lista;

  inicializaLista(&lista);
  insereElementoLista(&lista, 12345, "Maria do Carmo", 50);


  return EXIT_SUCCESS;
}
