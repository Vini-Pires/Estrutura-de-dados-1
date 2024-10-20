/*
  [Pilha Estática]

  Implemente um programa com duas Pilhas Estáticas, uma que tera apenas numeros pares, e a outra apenas com numeros impares.
  O programa devera ler um arquivo de entrada contendo 10 numeros, e empilha-los corretamente.
  Ao final, imprima cada pilha em um arquivo de saida proprio.

    • Modelo de arquivo de entrada:
      https://drive.google.com/file/d/1HxLT30br5sAJ9CD-nRDK3cmas-KTe2yw/view?usp=sharing

    • Modelo de arquivos de saida:
      – Pilha com numeros pares:
        https://drive.google.com/file/d/1eqCzuvaOkHcdZCRV5AGZ66voOfQbxLCO/view?usp=sharing

      – Pilha com numeros impares:
        https://drive.google.com/file/d/1EmC74KtdgiP5bp18C0w_iSTUxw1yZu-F/view?usp=sharing

    • Usar passsagem por argumento (argc e argv) para fornecer os nomes dos arquivos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ELEMENTOS 10

// -------------------------------------------------------------------------------------

// typedef struct {
//   int numero;
// } OBJETO;

typedef struct {
  int topo;
  int qntd_elementos;
  int elementos[MAX_ELEMENTOS];
} PILHA_ESTATICA;

// -------------------------------------------------------------------------------------

void inicializaPilha();
bool estaVazio();
bool estaCheia();
int tamanhoPilha();
void empilhar();
void desempilhar();
void seperarPilhas();
void imprimePilhaPar();
void imprimePilhaImpar();

// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------

int main () {
  PILHA_ESTATICA pares;
  PILHA_ESTATICA impares;

  inicializaPilha(&pares);
  inicializaPilha(&impares);

  seperarPilhas(&pares, &impares);

  imprimePilhaPar(&pares);
  imprimePilhaImpar(&impares);

  return EXIT_SUCCESS;
}

// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------


void inicializaPilha(PILHA_ESTATICA* p) {
  p->topo = -1;
  p->qntd_elementos = 0;
}

// -------------------------------------------------------------------------------------

bool estaVazio(PILHA_ESTATICA *p) {
  return p->qntd_elementos == 0;
}

// -------------------------------------------------------------------------------------

bool estaCheia(PILHA_ESTATICA *p) {
  return p->qntd_elementos == MAX_ELEMENTOS;
}

// -------------------------------------------------------------------------------------

int tamanhoPilha(PILHA_ESTATICA *p) {
  return p->qntd_elementos;
}

// -------------------------------------------------------------------------------------

void empilhar(PILHA_ESTATICA *p, int num) {
  if (estaCheia(p) == true) {
    printf("Não foi possivel inserir item na pilha\n");
    return;
  }

  p->elementos[p->qntd_elementos] = num;
  p->qntd_elementos++;
  p->topo++;
}

// -------------------------------------------------------------------------------------

void desempilhar(PILHA_ESTATICA *p) {
  if (estaVazio(p) == true) {
    printf("Pilha vazia\n");
    return;
  }

  p->topo--;
  p->qntd_elementos--;
}

// -------------------------------------------------------------------------------------

void verificarArquivo(FILE *arq) {
  if (arq == NULL) {
    perror("Erro na abertura do arquivo");
    exit(1);
  } else {
    printf("Arquivo OK\n");
  }
}

// -------------------------------------------------------------------------------------

void seperarPilhas(PILHA_ESTATICA *par, PILHA_ESTATICA *impar) {
  int num = 0;
  if (estaCheia(par) == true || estaCheia(impar) == true) {
    printf("Uma das pilhas não esta vazia");
    exit(1);
  }

  FILE *arq = fopen("../modelos/numeros_a_empilhar.txt", "r");
  verificarArquivo(arq);

  for (int i = 0; i < MAX_ELEMENTOS; i++) {
    fscanf(arq, "%i\n", &num);
    // if (num == 0) {
    //   perror("erro ao coletar um numero");
    //   exit(1);
    // }
    if (num % 2 == 0) {
      empilhar(par, num);
    } else if (num % 2 == 1){
      empilhar(impar, num);
    } else {
      return;
    }
  }

  fclose(arq);
}

void imprimePilhaPar(PILHA_ESTATICA *p) {
  FILE *arq = fopen("pilha_par.txt", "w");
  verificarArquivo(arq);

  while (estaVazio(p) == false) {
    fprintf(arq, "%d\n", p->elementos[p->topo]);
    desempilhar(p);
  }

  fclose(arq);
}

void imprimePilhaImpar(PILHA_ESTATICA *p) {
  FILE *arq = fopen("pilha_impar.txt", "w");
  verificarArquivo(arq);

  while (estaVazio(p) == false) {
    fprintf(arq, "%d\n", p->elementos[p->topo]);
    desempilhar(p);
  }

  fclose(arq);
}
