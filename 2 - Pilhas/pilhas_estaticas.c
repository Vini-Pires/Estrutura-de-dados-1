#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define n 10

typedef struct {
  int CPF;
  char nome[40];
  int idade;
} OBJETO;

typedef struct {
  int topo;
  OBJETO elementos[n];
  int qntd_elementos;
} PILHA_ESTATICA;

void inicializaPilha();
bool estaVazia();
bool estaCheia();
int tamanhoPilha();
void inserirPilha();
OBJETO topoPilha();
void imprimirTOPO();
void desempilhar();


// --------------------------------------------------------------------------------------

int main () {
  PILHA_ESTATICA p;

  inicializaPilha(&p);

  inserirPilha(&p, "Maria do Carmo", 50, 123456); // Empilhar elemento na pilha
  inserirPilha(&p, "John Doe", 15, 456456);
  inserirPilha(&p, "Donatann Sparrow", 15, 456456);
  inserirPilha(&p, "Dwanne Dantes", 55, 852132);
  inserirPilha(&p, "Katarina Blade", 34, 994613);
  inserirPilha(&p, "Hellen Pera", 42, 745413);

  imprimirTOPO(&p);

  desempilhar(&p);
  desempilhar(&p);

  imprimirTOPO(&p);

  return EXIT_SUCCESS;
}

// --------------------------------------------------------------------------------------

/**
 * @brief Construct a new inicializa Pilha object
 * Comando iniciar(Stack) do slide
 *
 * @param pilha
 */
void inicializaPilha(PILHA_ESTATICA *pilha) {
  pilha->topo = 0;
  pilha->qntd_elementos = 0;
}

/**
 * @brief Construct a new esta Vazia object
 * Comando estaVazia(Stack)
 * Não haveria modificação ent n precisaria mandar um ponteiro mas para manter uma padrão estamos passando esse ptr
 * @param pilha
 */
bool estaVazia(PILHA_ESTATICA *pilha) {
  return pilha->qntd_elementos == 0;
}

bool estaCheia(PILHA_ESTATICA *pilha) {
  return pilha->qntd_elementos == n;
}


int tamanhoPilha(PILHA_ESTATICA *pilha) {
  return pilha->qntd_elementos;
}

void inserirPilha(PILHA_ESTATICA *pilha, char nome[], int idade, int cpf) {
  if (estaCheia(pilha) == true) {
    printf("Não foi possivel fazer a inserção; Pilha cheia\n");
    return;
  }

  pilha->elementos[pilha->topo].CPF = cpf;
  pilha->elementos[pilha->topo].idade = idade;
  strcpy(pilha->elementos[pilha->topo].nome, nome);
  pilha->topo++;
  pilha->qntd_elementos++;

}

OBJETO topoPilha(PILHA_ESTATICA *pilha) {
  if (estaVazia(pilha) == true) {
    return pilha->elementos[0];
  }

  return pilha->elementos[pilha->topo - 1];
}

void imprimirTOPO(PILHA_ESTATICA *pilha) {
  OBJETO p = topoPilha(pilha);

  if (estaVazia(pilha) == true) return;

  printf("\n");
  printf("Nome: %s\n", p.nome);
  printf("Idade: %d\n", p.idade);
  printf("CPF: %d\n", p.CPF);
  printf("\n");

}

void desempilhar(PILHA_ESTATICA *pilha) {
  pilha->topo--;
  pilha->qntd_elementos--;
}
