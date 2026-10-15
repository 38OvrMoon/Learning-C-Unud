#include <stdio.h>
#include "persegi_panjang.h"

int main() {
    float panjang, lebar;

    printf("=== HITUNG LUAS & KELILING PERSEGI PANJANG ===\n");
    printf("Masukkan panjang : ");
    scanf("%f", &panjang);
    printf("Masukkan lebar   : ");
    scanf("%f", &lebar);

    tampilkanHasilPersegiPanjang(panjang, lebar);

    return 0;
}