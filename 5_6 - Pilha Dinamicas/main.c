#include "pilha.h"

int main(){
    Pilha p;

    inicializar(&p);

    inserir(&p, 0);
    inserir(&p, 1);
    inserir(&p, 2);

    if (estaVazia(&p)){
        printf("vazia\n");
    } else {
        printf("não vazia\n");
    }

    exibir(&p);

    int removido = remover(&p);
    printf("Valor removido: %d\n", removido);

    exibir(&p);

    remover(&p); // 1
    remover(&p); // 0
    
    removido = remover(&p); // -9999
    printf("Valor removido: %d\n", removido);
    exibir(&p);

    return 0;
}