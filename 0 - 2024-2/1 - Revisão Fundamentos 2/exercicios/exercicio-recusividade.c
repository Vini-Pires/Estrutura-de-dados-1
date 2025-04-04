#include <stdlib.h>
#include <stdio.h>

long int Fatorial (int fator) {
    if (fator == 1) {
        return 1;
    } else {
        return fator * Fatorial(fator - 1);
    }
}

int main () {
    int fator = 19;

    printf("Fatorial de %d! = %ld\n", fator, Fatorial(fator));

    return 0;
}