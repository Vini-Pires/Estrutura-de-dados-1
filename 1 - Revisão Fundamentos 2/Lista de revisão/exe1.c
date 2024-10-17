/*
{Concluído}

[Recursão]
  Escreva e programe uma função recursiva para calcular o valor de um número inteiro de base x elevada a um expoente inteiro y, sendo os valores de x>0 e y>0 fornecidos pelo usuário.

*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Calcula recursivamente uma base x elevada num expoente y
 *
 * @param base
 * @param expoente
 * @return int
 */
int Potencia(int base, int expoente) {
  // Caso base retorna o valor da variavel base para continuar a multiplicação recursiva
  if (expoente == 1) {
    return base;
  }

  return base *= Potencia(base, expoente - 1);

}

/**
 * @brief coleta os valores da base e seu expoente
 *
 * @param base
 * @param expoente
 */
void ColetaPotencia (int * base, int * expoente) {
  // Garante que a base nunca é menor doq 0
  do {

    printf("Digite sua base: ");
    scanf("%d", base);

  } while(base <= 0);

  // Garante que o expoente nunca é menor doq 0
  do {

    printf("Digite seu expoente: ");
    scanf("%d", expoente);

  } while (expoente <= 0);
}


int main () {
  int base;
  int expoente;
  ColetaPotencia(&base, &expoente);

  printf("Base: %d, Expoente: %d, Resultado: %d\n", base, expoente, Potencia(base, expoente));

  return 0;
}
