#include "../0 - Headers/header.h"

typedef struct aluno {
  char nome[25];
  int idade;
  struct aluno *prox;
} aluno;


// imprime todos os elementos da lista:
void imprime_lista(aluno *prim) {
  // ponteiro auxiliar começa no primeiro elemento
  aluno *aux = prim;
  while(aux != NULL){
    printf("nome: %s, idade: %d\n", aux->nome, aux->idade);
    aux = aux->prox;
  }

}

// inverte o segundo e terceiro elementos da lista:
// terceiro vira segundo e segundo vira terceiro

void inverte_seg_ter(aluno *prim) {
  // cria ponteiros para segundo e terceiro elementos
  aluno *seg = prim->prox;
  aluno *ter = seg->prox;

  // ana aponta pra jo
  seg->prox = ter->prox;

  // zeca aponta pra ana
  ter->prox = seg;

  // jose aponta pro zeca
  prim->prox = ter;

  return;
}


void adiciona_inicio(aluno **p_prim, aluno *novo){
  novo->prox = *p_prim;
  *p_prim = novo;

  return;
}


int main() {
  // cria 5 alunos
  aluno a0 = {"jose", 15, NULL};
  aluno a1 = {"zeca", 22, NULL};
  aluno a2 = {"caio", 15, NULL};
  aluno a3 = {"ana", 18, NULL};
  aluno a4 = {"jo", 21, NULL};
  aluno a5 = {"bob", 21, NULL};

  // cria as ligações da lista encadeada
  aluno *primeiro = &a0;  // ponteiro para o primeiro elemento
  a0.prox = &a3;  // jose aponta p ana
  a3.prox = &a1;  // ana aponta p zeca
  a1.prox = &a4;  // zeca aponta p jo
  a4.prox = &a2;  // jo aponta  p caio (e caio aponta para nulo)
  imprime_lista(primeiro);

  inverte_seg_ter(primeiro);
  printf("\n\nlista apos mudanca\n");
  imprime_lista(primeiro);



  adiciona_inicio(&primeiro, &a5);
  printf("\n\nlista apos add\n");
  imprime_lista(primeiro);


  return 0;
}

