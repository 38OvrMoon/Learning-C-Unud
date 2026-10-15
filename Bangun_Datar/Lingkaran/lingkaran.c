#include <stdio.h>
#include "lingkaran.h"

#define PHI 3.14159265

float luasLingkaran(float jariJari) {
    return PHI * jariJari * jariJari;
}

float kelilingLingkaran(float jariJari) {
    return 2 * PHI * jariJari;
}

void tampilkanHasilLingkaran(float jariJari) {
    float luas = luasLingkaran(jariJari);
    float keliling = kelilingLingkaran(jariJari);
    printf("\n--- LINGKARAN ---\n");
    printf("Luas     = %.2f\n", luas);
    printf("Keliling = %.2f\n", keliling);
}