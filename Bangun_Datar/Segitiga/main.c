#include <stdio.h>
#include "segitiga.h"

int main() {
    float alas, tinggi, sA, sB, sC;

    printf("=== HITUNG LUAS & KELILING SEGITIGA ===\n");
    printf("Masukkan alas segitiga   : ");
    scanf("%f", &alas);
    printf("Masukkan tinggi segitiga : ");
    scanf("%f", &tinggi);
    printf("Masukkan sisi A          : ");
    scanf("%f", &sA);
    printf("Masukkan sisi B          : ");
    scanf("%f", &sB);
    printf("Masukkan sisi C          : ");
    scanf("%f", &sC);

    tampilkanHasilSegitiga(alas, tinggi, sA, sB, sC);

    return 0;
}