/*
1. Entrada e Saída Básica – Exibindo Tópicos de Estudo
● Exercício: Escreva um programa que imprima um conjunto predefinido (de
sua escolha) de tópicos de estudo utilizando printf.
● Objetivo: Introduzir a saída formatada e a funcionalidade básica do printf.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char disciplina[40] = "Estrutura de dados 1";

  printf("\n\nEstamos na disciplina: %s\n\n", disciplina);

  return 0;
}