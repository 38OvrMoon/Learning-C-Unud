#include <stdio.h>
#include "persegi_panjang.h"

float luasPersegiPanjang(float panjang, float lebar) {
    return panjang * lebar;
}

float kelilingPersegiPanjang(float panjang, float lebar) {
    return 2 * (panjang + lebar);
}

void tampilkanHasilPersegiPanjang(float panjang, float lebar) {
    float luas = luasPersegiPanjang(panjang, lebar);
    float keliling = kelilingPersegiPanjang(panjang, lebar);
    printf("\n--- PERSEGI PANJANG ---\n");
    printf("Luas     = %.2f\n", luas);
    printf("Keliling = %.2f\n", keliling);
}