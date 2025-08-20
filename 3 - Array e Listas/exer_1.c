#include "../0 - Headers/header.h"

typedef struct aluno{
  char nome[25];
  int idade;
} aluno;

// percorre array e conta menores de idade:
int conta_menores(aluno a[], int qtd){
  int menores = 0;
  for (int x=0; x<qtd; x++){
    if (a[x].idade < 18){
      menores++;
    }
  }
  return menores;
}

int main()
{
  char nome[50];
  int idade;
  // cria um array com 10 alunos
  aluno a[10];
  FILE *input = fopen("./alunos.txt", "r");
  if (input == NULL){
    printf("erro abrindo arquivo\n");
    return 0;
  }

  // lê e imprime cada linha do arquivo
  int i = 0;
  while (fscanf(input, "%s %i", nome, &idade) != EOF){
    // preencher cada elemento da struct
    printf("nome: %s, idade: %d\n", nome, idade);
    a[i].idade = idade;
    strcpy(a[i].nome, nome);
    i++;
  }

  // imprime resultado
  int n_menores = conta_menores(a, i);
  printf("numero de menores: %d\n", n_menores);
  fclose(input);
  return 0;
}
