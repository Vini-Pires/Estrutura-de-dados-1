#include "../0 - Headers/header.h"

#define MAX 100
struct aluno {
  int idade;
  char nome[30];
};

typedef struct pilha {
  int qtd;
  struct aluno dados[MAX];
} Pilha;


// adiciona elemento à pilha
int push(Pilha *p, struct aluno al) {
  // se não pode adicionar retorna zero
  if (p==NULL || p->qtd>=MAX){
    return 0;
  }

  // copia o dado para o array e atualiza qtd
  p->dados[p->qtd] = al;
  p->qtd++;
  return 1;
}

// lê elemento do topo da pilha
int top(Pilha *p, struct aluno *al) {
  // se não pode ler retorna zero
  if (p==NULL || p->qtd<=0){
    return 0;
  }

  // copia o dado para o array e atualiza qtd
  *al = p->dados[p->qtd-1];
  return 1;

}

// lê e remove o elemento do topo da pilha
int pop(Pilha *p, struct aluno *al) {
  // se não pode ler retorna zero
  if (p==NULL || p->qtd<=0){
    return 0;
  }

  // copia o dado para o array e atualiza qtd
  *al = p->dados[p->qtd-1];
  p->qtd--;
  return 1;
}

// exercício 1: adiciona 5 pessoas e remove uma da pilha
void estado_inicial(Pilha *p) {
  // cria uma struct do tipo aluno
  struct aluno a0;
  int idades[5] = {12, 15, 17, 19, 25};
  char nomes[5][15] = {"pedro", "caio", "ze", "ju", "bia"};

  // adiciona 5 elementos
  for(int i=0; i < 5; i++) {
    a0.idade = idades[i];
    strcpy(a0.nome, nomes[i]);
    push(p, a0);
  }

  // remove um elemento:
  pop(p, &a0);
  printf("nome: %s idade: %d\n", a0.nome, a0.idade);
}


// exercício 2: calcular a média das idades dos
// alunos menores de idade

float media_menores(Pilha *p) {
    printf("quantidade: %d\n", p->qtd);
    float media;
    float qtd = 0;
    int soma = 0;
    for (int i=0; i<p->qtd; i++){
        if(p->dados[i].idade < 18){
            qtd = qtd + 1;
            soma = soma + p->dados[i].idade;
        }
    }
    media = soma/qtd;
    return media;
}




// exercício 3 remover o primeiro elememento pelo campo idade

int remove_por_idade(Pilha *p, int idade) {
  // encontra posição do elemento a ser removido

  bool encontrado = false;

  // elemento não encontrado

  // remove elemento
  for(int i = 0; i<p->qtd; i++) {
    if(p->dados[i].idade == idade) {
      encontrado = true;
      p->qtd--;
    }

    if(!encontrado) {
      p->dados[i] = p->dados[i+1];
    }

  }

}

void imprimir(Pilha *p) {
  for(int i = 0; i < p->qtd; i++) {
    printf("Nome: %s ", p->dados[i].nome);
    printf("Idade: %d\n", p->dados[i].idade);
  }
}

int main(){
  // cria uma pilha estática
  Pilha minha_pilha;
  minha_pilha.qtd = 0;

  // preenche a pilha
  estado_inicial(&minha_pilha);

  // mostra media
  printf("media: %.2f\n", media_menores(&minha_pilha));

  // remove e mostra media
  remove_por_idade(&minha_pilha, 15);
  imprimir(&minha_pilha);
  printf("media apos rem: %.2f\n", media_menores(&minha_pilha));
  imprimir(&minha_pilha);

}
