/*

[Arquivos]
  Faça um programa que receba, por argumento na main, o nome de um arquivo texto.

  Crie outro arquivo texto de saída contendo o texto do arquivo de entrada original, porém substituindo todas as vogais ‘a’ pelo caractere ‘*’ e as demais vogais por ‘+’.

  Além disso, mostre na tela quantas linhas esse arquivo possui.

  Dentro do programa faça o controle de erros, isto é, insira comandos que mostre se os arquivos foram abertos com sucesso e, caso contrário, imprima uma mensagem de erro encerrando o programa.

  OBS: Utilizar passagem de parâmetros (argC e argV) para receber o nome do arquivo.txt.

*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Verifica abertura do arquivo
 *
 * @param arq
 */
void ArqAbriu(FILE *arq) {
  if (arq == NULL) {
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }
}

int main () {

  FILE * arq = fopen("../arquivos_de_testes/arq.txt", "r+");
  ArqAbriu(arq);

  // pegar uma string
  // encontrar os 'a'
  // trocar os 'a' por '*'
  // limpar os espaços vazios

  fclose(arq);

}
