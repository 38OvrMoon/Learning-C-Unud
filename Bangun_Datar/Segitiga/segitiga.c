#include <stdio.h>
#include "segitiga.h"

float luasSegitiga(float alas, float tinggi) {
    return 0.5f * alas * tinggi;
}

float kelilingSegitiga(float sisiA, float sisiB, float sisiC) {
    return sisiA + sisiB + sisiC;
}

void tampilkanHasilSegitiga(float alas, float tinggi, float sA, float sB, float sC) {
    float luas = luasSegitiga(alas, tinggi);
    float keliling = kelilingSegitiga(sA, sB, sC);
    printf("\n--- SEGITIGA ---\n");
    printf("Luas     = %.2f\n", luas);
    printf("Keliling = %.2f\n", keliling);
}