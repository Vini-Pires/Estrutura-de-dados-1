#include <stdlib.h>
#include <stdio.h>

int main () {
    int n = 14;
    int *p = &n;

    printf("Endereço de n: %p, e o valor:%d\n", p, *p);

    return 0;
}
