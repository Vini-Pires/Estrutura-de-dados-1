#include "../0 - Headers/header.h"

#define MAX 10

typedef struct aluno_t {
  char nome[30];
  int idade;
}ALUNO;

int hash();
void push();

int main (void) {
  ALUNO tabela[MAX];
  memset(tabela, 0, sizeof(tabela));

  char nomes[10][20] = {"ana", "bia", "julia", "caio", "ze", "ju", "otavio", "caca", "mario", "borre"};
  int idades[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ALUNO novo;
  for(int i = 0; i < 20; i++) {
    strcpy(novo.nome, nomes[i]);
    novo.idade = idades[i];
    push(novo, tabela);
  }

  return 0;
}

int hash(char *str, int tamanho) {
  int soma = 0;
  for(int i = 0; str[i] != '\0'; i++)
    soma += str[i];

  return soma % tamanho;
}

void push(ALUNO novo, ALUNO tabela[]) {
  int pos = hash(novo.nome, MAX);
  printf("Pre: %d ", pos);
  printf("Nome %s\nIdade: %d\n", novo.nome, novo.idade);

  while (tabela[pos].nome[0] != '\0'){
    pos++;
    if (pos == MAX)
      pos = 0;
  }

  tabela[pos] = novo;
  printf("Pos: %d ", pos);
  printf("Nome %s\nIdade: %d\n", novo.nome, novo.idade);

}
