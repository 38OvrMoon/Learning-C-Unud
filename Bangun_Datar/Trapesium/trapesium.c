#include <stdio.h>
#include "trapesium.h"

float luasTrapesium(float sisiSejajarA, float sisiSejajarB, float tinggi) {
    return 0.5f * (sisiSejajarA + sisiSejajarB) * tinggi;
}

float kelilingTrapesium(float sisiA, float sisiB, float sisiC, float sisiD) {
    return sisiA + sisiB + sisiC + sisiD;
}

void tampilkanHasilTrapesium(float a, float b, float c, float d, float tinggi) {
    float luas = luasTrapesium(a, b, tinggi);
    float keliling = kelilingTrapesium(a, b, c, d);
    printf("\n--- TRAPESIUM ---\n");
    printf("Luas     = %.2f\n", luas);
    printf("Keliling = %.2f\n", keliling);
}