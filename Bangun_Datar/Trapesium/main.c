#include <stdio.h>
#include "trapesium.h"

int main() {
    float a, b, c, d, tinggi;

    printf("=== HITUNG LUAS & KELILING TRAPESIUM ===\n");
    printf("Masukkan sisi sejajar A   : ");
    scanf("%f", &a);
    printf("Masukkan sisi sejajar B   : ");
    scanf("%f", &b);
    printf("Masukkan sisi miring C    : ");
    scanf("%f", &c);
    printf("Masukkan sisi miring D    : ");
    scanf("%f", &d);
    printf("Masukkan tinggi trapesium : ");
    scanf("%f", &tinggi);

    tampilkanHasilTrapesium(a, b, c, d, tinggi);

    return 0;
}