/*
3. Operadores e Expressões – Calculando a Eficiência do Estudo
● Exercício: Dado o nível de dificuldade e o tempo estimado de um tópico de
estudo, estipule e calcule um "índice de eficiência de estudo" utilizando
operações aritméticas.
● Objetivo: Reforçar o uso de operadores (+, -, *, /) e expressões.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
  int dificuldade = 4;
  char disciplina[20] = "Calculo 1";
  float tempoEstimado = 3.4;
  float eficiencia;

  printf("Materia: %s\nTempo estimado: %.2f meses\nDificuldade: %d de 5\n",
          disciplina,
          tempoEstimado,
          dificuldade
        );

  eficiencia = dificuldade * tempoEstimado;
  eficiencia -= dificuldade;

  printf("\n%.2f\n", eficiencia);

  return 0;
}