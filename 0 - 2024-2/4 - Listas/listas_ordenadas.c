/*
  [Incompleto ??]
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

void inicializaLista();
bool estahVazia();
int tamanhoLista();
void insereElementoLista();
void imprimeElementosLista();

int main(void){
  LISTA_DINAMICA lista;
  inicializaLista(&lista);

  insereElementoLista(&lista, 12345, "Maria do Carmo", 50);
  insereElementoLista(&lista, 54321, "Joao Jose", 38);
  insereElementoLista(&lista, 56789, "Laura Silva", 62);
  insereElementoLista(&lista, 98563, "Karina Tavares", 55);
  insereElementoLista(&lista, 25852, "Oswaldo Cruz", 70);

  imprimeElementosLista(&lista);

  destroiLista(&lista);
  return EXIT_SUCCESS;
}

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

//obs: a lista estah ordenada por idade (ordem crescente)
//OBS2: como posso ter mais de um objeto com a mesma idade, pensar em como tratar isso!!!
void insereElementoLista(LISTA_DINAMICA* lista, int cpf, char nome[], int idade){
  OBJETO* novo=(OBJETO*) malloc(sizeof(OBJETO));
  if(novo==NULL){
    printf("\nNao foi possivel alocar memoria para o novo elemento");
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
      while(aux->prox!=NULL && aux->prox->idade < idade){
        aux=aux->prox;
      }
      novo->prox=aux->prox;
      aux->prox=novo;
    }
  }

  lista->tamanho++;
}

void imprimeElementosLista(LISTA_DINAMICA *lista){
  OBJETO *aux=lista->inicio;
  printf("\n=================================\n");
  printf("\nOs elementos da lista sao (idade-nome-CPF):");
  while(aux!=NULL){
    printf("\n %d %s %d", aux->idade, aux->nome, aux->CPF);
    aux=aux->prox;
  }
  printf("\n=================================\n");
}

void destroiLista(LISTA_DINAMICA *lista){
  OBJETO *aux=NULL;
  while(lista->inicio !=NULL){
    aux=lista->inicio;
    lista->inicio=aux->prox;
    free(aux);
  }
  inicializaLista(lista);
}

void removeElementoLista(LISTA_DINAMICA *lista, int idade){
  // Situação A dos slides
  if(estahVazia(lista)==true){
    printf("\nLista vazia: tchau!");
    return;
  }

  // Situação B dos slides
  if(lista->inicio->idade > idade){
    printf("\n\nEsta idade %d nao estah na lista", idade);
    return;
  }

  // Situação C dos slides
  if (lista->inicio->idade == idade){
    OBJETO *aux = lista->inicio;
    lista->inicio = aux->prox;
    free(aux);
    printf("Elemento excluido com sucesso\n");
    lista->tamanho--;

  } else { // Situação D dos slides
    OBJETO *aux = lista->inicio;
    while(aux->prox != NULL && aux->prox->idade < idade){
      aux = aux->prox;
    }

    if (aux->prox == NULL || aux->prox->idade != idade) {
      printf("\n\nEsta idade \"%d\" nao estah na lista", idade);
      return;
    } else {
      OBJETO *tchau = aux->prox;
      aux->prox = tchau->prox;
      free(tchau);
      printf("Elemento excluido com sucesso\n");
      lista->tamanho--;
    }

  }

}

/*
  [Terminar o codigo] ----------------------------
    pesquisarElemento
    maximoElemento
    minimoElemento
    encontrarProximoElemento
    encontrarAnteriorElemento
  -------------------------------------------------
*/
