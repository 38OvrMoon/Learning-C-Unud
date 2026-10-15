#include <stdio.h>
#include "lingkaran.h"

int main() {
    float jariJari;

    printf("=== HITUNG LUAS & KELILING LINGKARAN ===\n");
    printf("Masukkan jari-jari lingkaran : ");
    scanf("%f", &jariJari);

    tampilkanHasilLingkaran(jariJari);

    return 0;
}