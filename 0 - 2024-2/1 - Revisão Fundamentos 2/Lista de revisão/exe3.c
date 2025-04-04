/*
{Semi Concluído}
{Falta usar o argC e argV que não sei como funciona}

[Alocação Dinâmica, Arquivos]
  Faça um programa que leia um valor N digitado pelo usuário e crie dinamicamente um vetor com essa quantidade de elementos.
  Em seguida:
    • passe esse vetor para um procedimento que vai preencher os elementos desse vetor com números aleatórios de 0 até N ;

    • depois, passe esse vetor preenchido para outro procedimento e armazene as informações deste vetor em um arquivo binário, cujo nome será fornecido como argumento na main utilizando argv;

    • implemente um procedimento para ler e armazenar em um novo vetor as informações do arquivo.

  OBS1: antes de finalizar o programa, lembre-se de liberar a área de memória alocada.

  OBS2: utilizar a main apenas para fazer chamadas de funções/procedimentos, ou seja, nada de códigos gigantescos na main.

  OBS3: Utilizar passagem de parâmetros (argC e argV) para receber o nome do arquivo.dat.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int fornecaQuantidade();
int *alocaMemoria();
void erroDeMemoria();
void preencheVetorComNumerosAleatorios();
void guardaVetorEmBinario();
void erroDeAberturaDeArquivo();
void leVetorEmBinario();

int main () {
  int qntd = fornecaQuantidade();
  int *valorN = alocaMemoria(qntd);
  int *novoVetor = alocaMemoria(qntd);
  erroDeMemoria(valorN);
  preencheVetorComNumerosAleatorios(valorN, qntd);
  guardaVetorEmBinario(valorN, qntd);
  leVetorEmBinario(novoVetor, qntd);

  for (int i = 0; i < qntd; i++) {
    // printf("%2d --- %d\n", i+1, valorN[i]);
    printf("%2d --- %d\n", i+1, novoVetor[i]);
  }

  free(valorN);
  free(novoVetor);
  return 0;
}

int fornecaQuantidade (void) {
  int qntd;

  do {
    printf("Digite o valor N (>1) para alocar memória: ");
    scanf("%d", &qntd);
  } while (qntd < 1);

  return qntd;
}

int *alocaMemoria(int qntd) {
  return (int *) malloc (qntd * sizeof(int));
}

void erroDeMemoria(void *ptr) {
  if (ptr == NULL){
    perror("Erro de alocação de memória\n");
    exit(1);
  }
}

void preencheVetorComNumerosAleatorios (int *ptr, int qntd) {
  srand(time(NULL));

  for (int i = 0; i < qntd; i++) {
    ptr[i] = rand() % 100;
  }
}

void guardaVetorEmBinario(int *ptr, int qntd) {
  // FILE *arq = fopen("../arquivos_de_testes/vetor_binario.dat", "ab");
  // if (arq == NULL) {
    FILE *arq = fopen("vetor_binario.dat", "wb");
    erroDeAberturaDeArquivo(arq);
  // }

  fwrite(ptr, sizeof(int), qntd, arq);

  fclose(arq);
}

void erroDeAberturaDeArquivo(FILE *arq) {
  if (arq == NULL) {
    perror("Error na abertura de arquivo\n");
    exit(1);
  }
}

void leVetorEmBinario(int *ptr, int qntd) {
  FILE *arq = fopen("vetor_binario.dat", "rb");
  erroDeAberturaDeArquivo(arq);

  fread(ptr, sizeof(int), qntd, arq);
}
