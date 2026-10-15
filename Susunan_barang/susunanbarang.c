#include <stdio.h>

/*
 * Program: Menghitung jumlah kemungkinan susunan barang di rak
 * Rumus   : P(n, r) = n! / (n - r)!
 *           n = jumlah barang, r = jumlah posisi yang tersedia
 * Pendekatan: iteratif dan rekursif
 */

/* Pendekatan iteratif: n * (n-1) * ... * (n-r+1) */
unsigned long long susunanIteratif(int n, int r)
{
    unsigned long long hasil = 1;
    int i;

    for (i = 0; i < r; i++) {
        hasil *= (unsigned long long)(n - i);
    }
    return hasil;
}

/* Pendekatan rekursif: P(n, r) = n * P(n-1, r-1), basis: r == 0 -> 1 */
unsigned long long susunanRekursif(int n, int r)
{
    if (r == 0) {
        return 1;
    }
    return (unsigned long long)n * susunanRekursif(n - 1, r - 1);
}

int main(void)
{
    int n, r;

    printf("=== Penyusunan Barang di Rak Toko ===\n");
    printf("Masukkan jumlah barang  : ");
    if (scanf("%d", &n) != 1) {
        printf("Input tidak valid!\n");
        return 1;
    }
    printf("Masukkan jumlah posisi  : ");
    if (scanf("%d", &r) != 1) {
        printf("Input tidak valid!\n");
        return 1;
    }

    /* Struktur kontrol percabangan: validasi input */
    if (n <= 0 || r <= 0) {
        printf("Jumlah barang dan posisi harus lebih dari 0.\n");
    } else if (r > n) {
        printf("Jumlah posisi (%d) tidak boleh melebihi jumlah barang (%d).\n", r, n);
    } else if (n > 20) {
        printf("Jumlah barang maksimal 20 agar hasil tidak overflow.\n");
    } else {
        unsigned long long hasilIter = susunanIteratif(n, r);
        unsigned long long hasilRek  = susunanRekursif(n, r);

        printf("\nHasil perhitungan P(%d, %d):\n", n, r);
        printf("Pendekatan iteratif : %llu susunan\n", hasilIter);
        printf("Pendekatan rekursif : %llu susunan\n", hasilRek);

        if (hasilIter == hasilRek) {
            printf("Kedua pendekatan menghasilkan nilai yang sama.\n");
        } else {
            printf("Hasil kedua pendekatan berbeda!\n");
        }
    }

    return 0;
}