/*
{Concluído}
{Falta usar o argC e argV que não sei como funciona}

[Structs, Alocação Dinâmica e Ponteiros]

  A empresa onde você trabalha está desenvolvendo um programa que calcula a área de vários losangos e imprime os resultados em tela.

  Porém, seu colega que estava encarregado desta tarefa ficou doente e este trabalho foi repassado a você.

  A sua missão  é dar continuidade ao código desenvolvido até o momento e que está compartilhado abaixo.

  Seu chefe disse que você NÃO DEVE alterar o que já está pronto e enfatizou que sua missão é dar continuidade ao código.

  Até o momento, já encontra-se implementada uma função para que o usuário digite a quantidade de losangos que serão calculadas as respectivas  áreas (função fornecaQuantidade).

  Na sequência, o programa aloca memória para uma variável do tipo LOSANGO, de acordo com a quantidade digitada pelo usuário, para armazenar as informações relacionadas as diagonais de cada retângulo.

  Considerando isso, você como programador deve continuar o código fazendo os procedimentos:

    • digiteDiagonalLosangos: este procedimento tem o intuito de solicitar ao usuário as medidas das diagonais e cada um dos losangos e armazenar tais informações na variável LOSANGO *l;

    • calculeAreaLosangos: este procedimento calcula a área de cada dos losangos e armazenar atualiza a respectiva informação na variável LOSANGO *l;

    • imprimeAreaLosangos: por fim, este procedimento imprime as dimensões de cada um dos losango e, também, as respectivas áreas de cada um deles.

  Area Losango = (DiagonalMaior * DiagonalMenor)/2

*/

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Inclusão das bibliotecas
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include <stdio.h>
#include <stdlib.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Definição do Registro : LOSANGO
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct losango {
  float diagonal1 ;
  float diagonal2 ;
  float area ;
} LOSANGO ;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// LOSANGO * aloca ( int quantidade )
// reserva espaço de memoria para ‘ quantidade ’ de losango
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

LOSANGO * aloca ( int quantidade ){
  return ( LOSANGO *) malloc ( sizeof ( LOSANGO )* quantidade );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// int fornecaQuantidade ( void )
// pede ao usuário digitar a quantidade de losango e devolve este numero
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int fornecaQuantidade ( void ){
  int qtde ;

  do{
    printf ("\nQuantos losangos voce deseja calcular a área (> 2) ? ");
    scanf ("%d" , & qtde );
  } while (qtde <=2) ;

  return qtde ;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// void digiteDiagonalLosangos (?????????)
// pede ao usuário digitar a medida das diagonais de cada um dos losangos
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void digiteDiagonalLosangos (LOSANGO **ptr, int qntd) {
  // Preciso coletar as diagonais do losango
  for (int i = 0; i < qntd; i++) {
    printf("%d - digite a diagonal 1: ", i + 1);
    scanf("%f", &(*ptr)[i].diagonal1);
    printf("%d - digite a diagonal 2: ", i + 1);
    scanf("%f", &(*ptr)[i].diagonal2);

    // Garante que as diagonais não possuam valores menores que zero
    if ((*ptr)[i].diagonal1 <= 0 || (*ptr)[i].diagonal2 <= 0) {
      printf("Losango: (%d)\n", i + 1);
      printf("Erro: valores de pelo menos 1 das diagonais menores que 0\n");
      i--;
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// void calculeAreaLosangos (?????????)
// calcula a area dos losangos
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void calculeAreaLosangos (LOSANGO **ptr, int qntd) {
  // Usar formula e resultado fica na struct
  for (int i = 0; i < qntd; i++) {
    (*ptr)[i].area = ((*ptr)[i].diagonal1 * (*ptr)[i].diagonal2) / 2;
  }

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// void imprimeAreaLosangos (?????????)
// imprime os valores das diagonais e da area de cada um dos losangos
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void imprimeAreaLosangos (LOSANGO **ptr, int qntd) {
  // pega as areas da struct e exibe no terminal
  for (int i = 0; i < qntd; i++) {
    printf("\nLosango %d\n", i+1);
    printf("Diagonal 1: %.2f | Digonal 2: %.2f\n", (*ptr)[i].diagonal1, (*ptr)[i].diagonal2);
    printf("Area: %.2f\n", (*ptr)[i].area);
  }

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main ( void ){
  LOSANGO *l;
  int qtde = fornecaQuantidade () ; // quantidade de losangos a serem trabalhados

  if( (l = aloca ( qtde )) == NULL ){ // alocando memoria para a quantidade de losangos
    printf ("Erro de alocação de memória\n");
    return EXIT_FAILURE ;
  }

  digiteDiagonalLosangos (&l, qtde ); // implementar
  calculeAreaLosangos (&l, qtde ); // implementar
  imprimeAreaLosangos (&l, qtde ); // implementar

  free (l);
  return EXIT_SUCCESS ;
}
