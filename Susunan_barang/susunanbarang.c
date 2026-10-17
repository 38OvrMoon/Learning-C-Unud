#include <stdio.h>
#include <stdlib.h>

void nama_kelompok(void);
void input_user(void);
int  menu_utama(void);
void jalankan_program(void);
int  baca_angka(const char *pesan, int *nilai);
int  menu_ulang(void);
void bersihkan_buffer(void);
unsigned long long susunanIteratif(int n, int r);
unsigned long long susunanRekursif(int n, int r);

int main(void)
{
    nama_kelompok();
    input_user();
    return 0;
}

void nama_kelompok(void)
{
    system ("cls");
    printf("+=======================================================+\n");
    printf("|               PROGRAM SUSUNAN BARANG                  |\n");
    printf("|=======================================================|\n");
    printf("|        KELOMPOK 25 PRAKTIKUM PEMROGRAMAN 2026         |\n");
    printf("|=======================================================|\n");
    printf("| Keykadelio Soewardana (260530911036)                  |\n");
    printf("| I Komang Aditya Moreno Putra (260530911040)           |\n");
    printf("| Advensia Natalin Sihombing (260530911069)             |\n");
    printf("| Darrel Nathan Wibowo (260530911070)                   |\n");
    printf("| Anna Tasya Kartika (260530911071)                     |\n");
    printf("| Putu Dhrti Ayodhya Nugraha (260530911126)             |\n");
    printf("| Putu Agus Bayu Krishna Nanda (260530911136)           |\n");
    printf("+=======================================================+\n\n");
    system ("pause");
}

void input_user(void)
{
    int pilihan;
    int selesai = 0;

    while (!selesai) {
        pilihan = menu_utama();

        if (pilihan == 1) {
            jalankan_program();
            printf("\nProgram selesai. Terima kasih!\n");
            selesai = 1;
        } else if (pilihan == 2) {
            printf("\nKeluar dari program. Terima kasih!\n");
            selesai = 1;
        } else {
            printf("\nPilihan tidak valid, coba lagi.\n\n");
        }
    }
}

int menu_utama(void)
{
    int pilihan;
    system ("cls");
    printf("------------- MENU UTAMA -------------\n");
    printf("1. Lanjut ke program\n");
    printf("2. Keluar program\n");
    printf("Pilihan : ");

    if (scanf("%d", &pilihan) != 1) {
        bersihkan_buffer();
        return 0; 
    }
    bersihkan_buffer();
    return pilihan;
}

void jalankan_program(void)
{
    int n, r;
    int ulang = 1;

    while (ulang) {
        printf("\n=== Hitung Susunan Barang ===\n");

        if (!baca_angka("Masukkan jumlah barang : ", &n) ||
            !baca_angka("Masukkan jumlah posisi : ", &r)) {
            printf("Input harus berupa angka!\n");
        } else if (n <= 0 || r <= 0) {
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

        ulang = menu_ulang();
    }
}

int baca_angka(const char *pesan, int *nilai)
{
    printf("%s", pesan);
    if (scanf("%d", nilai) != 1) {
        bersihkan_buffer();
        return 0;
    }
    bersihkan_buffer();
    return 1;
}

int menu_ulang(void)
{
    int pilihan = 0;

    while (pilihan != 1 && pilihan != 2) {
        printf("\n1. Input lagi\n");
        printf("2. Akhiri program\n");
        printf("Pilihan : ");

        if (scanf("%d", &pilihan) != 1) {
            bersihkan_buffer();
            pilihan = 0;
        } else {
            bersihkan_buffer();
        }

        if (pilihan != 1 && pilihan != 2) {
            printf("Pilihan tidak valid, coba lagi.\n");
        }
    }

    return (pilihan == 1);
}

void bersihkan_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

unsigned long long susunanIteratif(int n, int r)
{
    unsigned long long hasil = 1;
    int i;

    for (i = 0; i < r; i++) {
        hasil *= (unsigned long long)(n - i);
    }
    return hasil;
}

unsigned long long susunanRekursif(int n, int r)
{
    if (r == 0) {
        return 1;
    }
    return (unsigned long long)n * susunanRekursif(n - 1, r - 1);
}
