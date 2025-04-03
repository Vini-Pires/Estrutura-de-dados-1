#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void colacaEndereco();

int main (void) {
  int num = 10;
  int *ptrNum = NULL;

  colacaEndereco(&num, &ptrNum);

  // Imprima o conteudo do endereço de ptrNum
  printf("===================\n");
  printf("Valor armazenado: %d\n", *ptrNum);
  printf("Endereço ponteiro: %p\n", &ptrNum);
  printf("Endereço armazenado: %p\n", ptrNum);
  printf("Endereço var num: %p\n", &num);
  printf("===================\n");
  return EXIT_SUCCESS;
}

void colacaEndereco(int *num, int **ptr) {
  *ptr = num;
}

