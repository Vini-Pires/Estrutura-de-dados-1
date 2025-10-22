#include "../0 - Headers/header.h"

// número de ponteiros na tabela
#define MAX 6

struct aluno_t{
  char nome[30];
  int idade;
  struct aluno_t *prox;
};
typedef struct aluno_t aluno;

// função hash (espalhamento)
/**
* @brief cria um indice para os elementos que recebe
*
* @param str
* @param tamanho
* @return o resto da divisão da soma pelo seu tamanho
*/
int hash(char *str, int tamanho) {
  int soma = 0;
  for (int i = 0; str[i] != '\0'; i++)
  soma += str[i];
  return soma % tamanho;
}

/**
* @brief adiciona um elemento de forma encadeada
* para encadear ele verifica pela func hash se eh o primeiro elemento, caso n seja ele
* adiciona no prox do elemento mais distante naquele ponto da tabela
*
* @param novo
* @param tabela
*/
void adiciona_elemento(aluno *novo, aluno *tabela[]){
  int idx = hash(novo->nome, MAX);
  printf("nome: %s, idx: %d\n", novo->nome, idx);

  // testa se posição está vazia
  if(tabela[idx] == NULL){
    // se estiver vazia, só adiciona
    tabela[idx] = novo;
  }
  else{
    // caso contrário, adiciona antes do primeiro
    novo->prox = tabela[idx];
    tabela[idx] = novo;
  }
}


/**
* @brief busca pela idade com base no nome
*
* @param nome
* @param tabela
* @return int
*/
int busca_idade(char *nome, aluno *tabela[]){
  int idx = hash(nome, MAX);
  printf("IDX: %d - ", idx);

  aluno *aux = tabela[idx];
  int idade = -1;

  while(aux != NULL) {
    if (strcmp(nome, aux->nome) == 0) {
      idade = aux->idade;
      break;
    }

    aux = aux->prox;

  }

  return idade;
}


/**
* @brief busca pelo mais velho na tabela
*
* @param tabela
*/
void imprime_mais_velho(aluno *tabela[]){

  int mais_velho = -1;
  aluno *temp;

  for (int i = 0; i < MAX; i++) {
    temp = tabela[i];
    while(temp != NULL) {
      if (mais_velho == -1 || temp->idade > mais_velho) {
        mais_velho = temp->idade;
      }
      temp = temp->prox;
    }
  }

  printf("maior idade: %d\n", mais_velho);
}


/**
* @brief  posição na tabela com mais elementos
*
* @param tabela
*/
void posicao_mais_elementos(aluno *tabela[]){

  int max_pos = -1;
  int max_el = -1;
  int cont = 0;
  aluno *temp;
  for(int i=0; i<MAX; i++){
    temp = tabela[i];
    cont = 0;
    while(temp != NULL){
      cont = cont + 1;
      temp = temp->prox;
    }

    if(cont > max_el){
      max_pos = i;
      max_el = cont;
    }
  }
  printf("posicao: %d\n", max_pos);
}


int main(void) {
  aluno *tabela[10] =  {NULL};
  char nomes[10][20] = {
    "ana", "bia", "julia", "caio", "ze",
    "ju", "otavio", "caca", "mario", "borre"
  };
  int idades[20] = {17, 22, 31, 25, 21, 23, 27, 28, 29, 19};

  for (int i=0; i<10; i++){
    aluno *novo = malloc(sizeof(aluno));
    strcpy(novo->nome, nomes[i]);
    novo->idade = idades[i];
    novo->prox = NULL;
    adiciona_elemento(novo, tabela);
  }

  printf("idade ana: %d\n", busca_idade("ana", tabela));
  printf("idade julia: %d\n", busca_idade("julia", tabela));
  printf("idade ze: %d\n", busca_idade("ze", tabela));
  printf("idade robesvaldo: %d\n", busca_idade("robesvaldo", tabela)); // retorna -1 como sinal de erro, pois não existe esse nome na tabela

  imprime_mais_velho(tabela);
  posicao_mais_mais_elementos(tabela);

  return 0;
}
