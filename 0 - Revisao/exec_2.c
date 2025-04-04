/*
2. Variáveis e Tipos de Dados – Armazenando Tópicos de Estudo
● Exercício: Declare variáveis (int, float, char) para armazenar o nome de
um tópico de estudo, a dificuldade (escala de 1 a 5) e o tempo estimado.
Atribua e imprima os valores.
● Objetivo: Utilizar os tipos de variáveis e o armazenamento básico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
  int dificuldade = 4;
  char disciplina[20] = "Calculo 1";
  float tempoEstimado = 3.4;

  printf("Materia: %s\nTempo estimado: %.2f meses\nDificuldade: %d de 5\n",
          disciplina,
          tempoEstimado,
          dificuldade
        );

  return 0;
}