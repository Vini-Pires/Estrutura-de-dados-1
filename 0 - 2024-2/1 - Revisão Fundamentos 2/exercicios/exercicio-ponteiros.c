#include <stdio.h>
#include <stdlib.h>

void converta(int milhas, int* kmh, int* metro) {
    *kmh = milhas * 1.609;
    *metro = *kmh / 3.6;  
}

int main () {

    int milhasParaConverter = 1000;
    int kmh;
    int metros;

    converta(milhasParaConverter, &kmh, &metros);
    printf("*************************\n");
    printf("Milhas/h: %d\n", milhasParaConverter);
    printf("*************************\n");
    printf("Km/h: %d\n", kmh);
    printf("*************************\n");
    printf("m/s: %d\n", metros);
    printf("*************************\n");

    return 0;
}