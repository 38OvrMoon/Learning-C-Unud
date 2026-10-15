/*
 * BUILDNET GAMING CENTER
 * Program pencatatan penggunaan komputer (Tugas Tim BUILD IT 2026)
 * Bahasa: C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PELANGGAN 100
#define MAX_KOMPUTER  50
#define MAX_TRANSAKSI 200

#define TARIF_REGULER 5000
#define TARIF_GAMING  10000

typedef struct {
    char id[16];
    char nama[50];
    char telepon[20];
    char jenis[20];
} Pelanggan;

typedef struct {
    char id[16];
    int  nomor;
    char jenis[10];      /* "Reguler" atau "Gaming" */
    char status[15];
} Komputer;

typedef struct {
    char id[16];
    char idPelanggan[16];
    char idKomputer[16];
    int  durasi;         /* jam */
    long total;          /* rupiah */
} Transaksi;

Pelanggan dataPelanggan[MAX_PELANGGAN];
Komputer  dataKomputer[MAX_KOMPUTER];
Transaksi dataTransaksi[MAX_TRANSAKSI];
int jmlPelanggan = 0, jmlKomputer = 0, jmlTransaksi = 0;

/* ---------- Fungsi bantu ---------- */
void bacaString(const char *prompt, char *dest, int ukuran) {
    printf("%s", prompt);
    if (fgets(dest, ukuran, stdin) == NULL) { dest[0] = '\0'; return; }
    dest[strcspn(dest, "\r\n")] = '\0';
}

int bacaInt(const char *prompt) {
    char buf[32];
    bacaString(prompt, buf, sizeof(buf));
    return atoi(buf);
}

void toUpper(char *s) {
    for (; *s; s++) if (*s >= 'a' && *s <= 'z') *s -= 32;
}

void garis(char c, int n) {
    int i;
    for (i = 0; i < n; i++) putchar(c);
    putchar('\n');
}

void tekanEnter(void) {
    char buf[8];
    bacaString("\nTekan ENTER untuk kembali ke menu...", buf, sizeof(buf));
}

void formatRupiah(long angka, char *hasil) {
    char tmp[32], out[40];
    int len, i, j = 0, hitung = 0;
    sprintf(tmp, "%ld", angka);
    len = (int)strlen(tmp);
    for (i = len - 1; i >= 0; i--) {
        if (hitung == 3) { out[j++] = '.'; hitung = 0; }
        out[j++] = tmp[i];
        hitung++;
    }
    out[j] = '\0';
    for (i = 0; i < j / 2; i++) { char t = out[i]; out[i] = out[j-1-i]; out[j-1-i] = t; }
    sprintf(hasil, "Rp%s", out);
}

/* ---------- Pencarian ---------- */
int cariPelanggan(const char *id) {
    int i;
    for (i = 0; i < jmlPelanggan; i++)
        if (strcmp(dataPelanggan[i].id, id) == 0) return i;
    return -1;
}

int cariKomputer(const char *id) {
    int i;
    for (i = 0; i < jmlKomputer; i++)
        if (strcmp(dataKomputer[i].id, id) == 0) return i;
    return -1;
}

int cariTransaksi(const char *id) {
    int i;
    for (i = 0; i < jmlTransaksi; i++)
        if (strcmp(dataTransaksi[i].id, id) == 0) return i;
    return -1;
}

/* ---------- Tarif & biaya ---------- */
int tentukanTarif(const char *jenisKomputer) {
    if (strcmp(jenisKomputer, "Gaming") == 0) return TARIF_GAMING;
    return TARIF_REGULER;
}

long hitungTotalBiaya(int durasi, int tarif) {
    return (long)durasi * tarif;
}

/* ---------- Data awal ---------- */
void tambahPelangganAwal(const char *nama, const char *telp, const char *jenis) {
    Pelanggan *p = &dataPelanggan[jmlPelanggan];
    sprintf(p->id, "P%03d", jmlPelanggan + 1);
    strcpy(p->nama, nama);
    strcpy(p->telepon, telp);
    strcpy(p->jenis, jenis);
    jmlPelanggan++;
}

void tambahKomputerAwal(int nomor, const char *jenis) {
    Komputer *k = &dataKomputer[jmlKomputer];
    sprintf(k->id, "K%03d", jmlKomputer + 1);
    k->nomor = nomor;
    strcpy(k->jenis, jenis);
    strcpy(k->status, "Tersedia");
    jmlKomputer++;
}

void tambahTransaksiAwal(int idxPel, int idxKom, int durasi) {
    Transaksi *t = &dataTransaksi[jmlTransaksi];
    sprintf(t->id, "T%03d", jmlTransaksi + 1);
    strcpy(t->idPelanggan, dataPelanggan[idxPel].id);
    strcpy(t->idKomputer, dataKomputer[idxKom].id);
    t->durasi = durasi;
    t->total = hitungTotalBiaya(durasi, tentukanTarif(dataKomputer[idxKom].jenis));
    jmlTransaksi++;
}

void inisialisasiData(void) {
    /* 10 data pelanggan */
    tambahPelangganAwal("Andi Pratama",     "081234567801", "Member");
    tambahPelangganAwal("Budi Santoso",     "081234567802", "Umum");
    tambahPelangganAwal("Citra Dewi",       "081234567803", "Member");
    tambahPelangganAwal("Dewa Made",        "081234567804", "Umum");
    tambahPelangganAwal("Eka Putri",        "081234567805", "VIP");
    tambahPelangganAwal("Feri Ananda",      "081234567806", "Umum");
    tambahPelangganAwal("Gita Lestari",     "081234567807", "Member");
    tambahPelangganAwal("Hendra Wijaya",    "081234567808", "VIP");
    tambahPelangganAwal("Indah Sari",       "081234567809", "Umum");
    tambahPelangganAwal("Joko Saputra",     "081234567810", "Member");

    /* 10 data komputer: 4 Reguler, 6 Gaming */
    tambahKomputerAwal(1,  "Reguler");
    tambahKomputerAwal(2,  "Reguler");
    tambahKomputerAwal(3,  "Reguler");
    tambahKomputerAwal(4,  "Reguler");
    tambahKomputerAwal(5,  "Gaming");
    tambahKomputerAwal(6,  "Gaming");
    tambahKomputerAwal(7,  "Gaming");
    tambahKomputerAwal(8,  "Gaming");
    tambahKomputerAwal(9,  "Gaming");
    tambahKomputerAwal(10, "Gaming");

    /* 20 data transaksi (indeks pelanggan, indeks komputer, durasi) */
    tambahTransaksiAwal(0, 4, 3);
    tambahTransaksiAwal(1, 0, 2);
    tambahTransaksiAwal(2, 5, 4);
    tambahTransaksiAwal(3, 1, 1);
    tambahTransaksiAwal(4, 6, 5);
    tambahTransaksiAwal(5, 2, 3);
    tambahTransaksiAwal(6, 7, 2);
    tambahTransaksiAwal(7, 8, 6);
    tambahTransaksiAwal(8, 3, 4);
    tambahTransaksiAwal(9, 9, 3);
    tambahTransaksiAwal(0, 5, 2);
    tambahTransaksiAwal(1, 6, 1);
    tambahTransaksiAwal(2, 0, 3);
    tambahTransaksiAwal(3, 7, 4);
    tambahTransaksiAwal(4, 8, 2);
    tambahTransaksiAwal(5, 9, 5);
    tambahTransaksiAwal(6, 1, 2);
    tambahTransaksiAwal(7, 4, 3);
    tambahTransaksiAwal(8, 6, 1);
    tambahTransaksiAwal(9, 2, 4);
}

/* ---------- Tampilan ---------- */
void tampilkanMenu(void) {
    printf("\n");
    garis('=', 40);
    printf(" BUILDNET GAMING CENTER\n");
    garis('=', 40);
    printf("1. Tambah Data Pelanggan\n");
    printf("2. Tambah Data Transaksi\n");
    printf("3. Tampilkan Data Transaksi\n");
    printf("4. Cari Data Transaksi\n");
    printf("5. Hitung Total Pendapatan\n");
    printf("6. Keluar\n");
    garis('=', 40);
    printf("Pilih menu: ");
}

void tampilkanDaftarPelanggan(void) {
    int i;
    printf("\n%-6s %-18s %-14s %-8s\n", "ID", "Nama", "Telepon", "Jenis");
    garis('-', 50);
    for (i = 0; i < jmlPelanggan; i++)
        printf("%-6s %-18s %-14s %-8s\n", dataPelanggan[i].id, dataPelanggan[i].nama,
               dataPelanggan[i].telepon, dataPelanggan[i].jenis);
}

void tampilkanDaftarKomputer(void) {
    int i;
    char tarif[20];
    printf("\n%-6s %-8s %-10s %-12s\n", "ID", "No. PC", "Jenis", "Tarif/jam");
    garis('-', 40);
    for (i = 0; i < jmlKomputer; i++) {
        formatRupiah(tentukanTarif(dataKomputer[i].jenis), tarif);
        printf("%-6s %-8d %-10s %-12s\n", dataKomputer[i].id, dataKomputer[i].nomor,
               dataKomputer[i].jenis, tarif);
    }
}

void tampilkanSatuTransaksi(const Transaksi *t) {
    int ip = cariPelanggan(t->idPelanggan);
    int ik = cariKomputer(t->idKomputer);
    char tarif[20], total[20];
    formatRupiah(tentukanTarif(dataKomputer[ik].jenis), tarif);
    formatRupiah(t->total, total);
    printf("ID Transaksi : %s\n", t->id);
    printf("Pelanggan    : %s (%s)\n", dataPelanggan[ip].nama, t->idPelanggan);
    printf("Komputer     : PC-%d (%s) [%s]\n", dataKomputer[ik].nomor, dataKomputer[ik].jenis, t->idKomputer);
    printf("Tarif/jam    : %s\n", tarif);
    printf("Lama pakai   : %d jam\n", t->durasi);
    printf("Total Biaya  : %s\n", total);
}

/* ---------- Menu 1 ---------- */
void tambahPelanggan(void) {
    Pelanggan *p;
    int pilih;
    printf("\n--- TAMBAH DATA PELANGGAN ---\n");
    if (jmlPelanggan >= MAX_PELANGGAN) {
        printf("Data pelanggan penuh!\n");
        return;
    }
    p = &dataPelanggan[jmlPelanggan];
    sprintf(p->id, "P%03d", jmlPelanggan + 1);
    printf("ID Pelanggan     : %s (otomatis)\n", p->id);
    do {
        bacaString("Nama Pelanggan   : ", p->nama, sizeof(p->nama));
        if (strlen(p->nama) == 0) printf("Nama tidak boleh kosong!\n");
    } while (strlen(p->nama) == 0);
    bacaString("Nomor Telepon    : ", p->telepon, sizeof(p->telepon));
    do {
        printf("Jenis Pelanggan  : 1. Umum  2. Member  3. VIP\n");
        pilih = bacaInt("Pilih (1-3)      : ");
    } while (pilih < 1 || pilih > 3);
    if (pilih == 1) strcpy(p->jenis, "Umum");
    else if (pilih == 2) strcpy(p->jenis, "Member");
    else strcpy(p->jenis, "VIP");
    jmlPelanggan++;
    printf("\n>> Data pelanggan %s berhasil ditambahkan.\n", p->id);
}

/* ---------- Menu 2 ---------- */
void tambahTransaksi(void) {
    char idPel[16], idKom[16];
    int ip, ik, durasi, tarif;
    Transaksi *t;
    char total[20], tarifStr[20];

    printf("\n--- TAMBAH DATA TRANSAKSI ---\n");
    if (jmlTransaksi >= MAX_TRANSAKSI) {
        printf("Data transaksi penuh!\n");
        return;
    }
    tampilkanDaftarPelanggan();
    bacaString("\nMasukkan ID Pelanggan (mis. P001): ", idPel, sizeof(idPel));
    toUpper(idPel);
    ip = cariPelanggan(idPel);
    if (ip == -1) {
        printf(">> ID Pelanggan tidak ditemukan!\n");
        return;
    }
    tampilkanDaftarKomputer();
    bacaString("\nMasukkan ID Komputer (mis. K001): ", idKom, sizeof(idKom));
    toUpper(idKom);
    ik = cariKomputer(idKom);
    if (ik == -1) {
        printf(">> ID Komputer tidak ditemukan!\n");
        return;
    }
    durasi = bacaInt("Lama penggunaan (jam): ");
    if (durasi <= 0) {
        printf(">> Lama penggunaan harus lebih dari 0 jam!\n");
        return;
    }
    tarif = tentukanTarif(dataKomputer[ik].jenis);
    t = &dataTransaksi[jmlTransaksi];
    sprintf(t->id, "T%03d", jmlTransaksi + 1);
    strcpy(t->idPelanggan, idPel);
    strcpy(t->idKomputer, idKom);
    t->durasi = durasi;
    t->total = hitungTotalBiaya(durasi, tarif);
    jmlTransaksi++;

    formatRupiah(t->total, total);
    printf("\n>> Transaksi %s berhasil ditambahkan.\n", t->id);
    formatRupiah(tarif, tarifStr);
    printf("   %s | PC-%d (%s) | %d jam x %s = %s\n", dataPelanggan[ip].nama,
           dataKomputer[ik].nomor, dataKomputer[ik].jenis, durasi, tarifStr, total);
}

/* ---------- Menu 3 ---------- */
void tampilkanTransaksi(void) {
    int i, ip, ik;
    char total[20];
    printf("\n--- DATA TRANSAKSI ---\n");
    if (jmlTransaksi == 0) {
        printf("Belum ada data transaksi.\n");
        return;
    }
    printf("%-4s %-6s %-16s %-6s %-9s %-5s %-12s\n", "No", "ID", "Pelanggan", "PC", "Jenis", "Jam", "Total");
    garis('-', 66);
    for (i = 0; i < jmlTransaksi; i++) {
        ip = cariPelanggan(dataTransaksi[i].idPelanggan);
        ik = cariKomputer(dataTransaksi[i].idKomputer);
        formatRupiah(dataTransaksi[i].total, total);
        printf("%-4d %-6s %-16s PC-%-3d %-9s %-5d %-12s\n", i + 1, dataTransaksi[i].id,
               dataPelanggan[ip].nama, dataKomputer[ik].nomor, dataKomputer[ik].jenis,
               dataTransaksi[i].durasi, total);
    }
    garis('-', 66);
    printf("Total data transaksi: %d\n", jmlTransaksi);
}

/* ---------- Menu 4 ---------- */
void cariDataTransaksi(void) {
    char id[16];
    int idx;
    printf("\n--- CARI DATA TRANSAKSI ---\n");
    bacaString("Masukkan ID Transaksi (mis. T001): ", id, sizeof(id));
    toUpper(id);
    idx = cariTransaksi(id);
    if (idx == -1) {
        printf("\n>> Transaksi dengan ID %s tidak ditemukan.\n", id);
    } else {
        printf("\n>> Transaksi ditemukan:\n");
        garis('-', 40);
        tampilkanSatuTransaksi(&dataTransaksi[idx]);
        garis('-', 40);
    }
}

/* ---------- Menu 5 ---------- */
long hitungTotalPendapatan(void) {
    long total = 0;
    int i;
    for (i = 0; i < jmlTransaksi; i++) total += dataTransaksi[i].total;
    return total;
}

void tampilkanTotalPendapatan(void) {
    long reguler = 0, gaming = 0;
    int i, ik;
    char s[20];
    printf("\n--- TOTAL PENDAPATAN BUILDNET ---\n");
    for (i = 0; i < jmlTransaksi; i++) {
        ik = cariKomputer(dataTransaksi[i].idKomputer);
        if (strcmp(dataKomputer[ik].jenis, "Gaming") == 0) gaming += dataTransaksi[i].total;
        else reguler += dataTransaksi[i].total;
    }
    formatRupiah(reguler, s);
    printf("Pendapatan Komputer Reguler : %s\n", s);
    formatRupiah(gaming, s);
    printf("Pendapatan Komputer Gaming  : %s\n", s);
    garis('-', 42);
    formatRupiah(hitungTotalPendapatan(), s);
    printf("TOTAL PENDAPATAN            : %s\n", s);
    printf("Jumlah transaksi            : %d\n", jmlTransaksi);
}

/* ---------- Program utama ---------- */
int main(void) {
    int pilihan;
    inisialisasiData();
    do {
        tampilkanMenu();
        pilihan = bacaInt("");
        switch (pilihan) {
            case 1: tambahPelanggan();         tekanEnter(); break;
            case 2: tambahTransaksi();         tekanEnter(); break;
            case 3: tampilkanTransaksi();      tekanEnter(); break;
            case 4: cariDataTransaksi();       tekanEnter(); break;
            case 5: tampilkanTotalPendapatan(); tekanEnter(); break;
            case 6: printf("\nTerima kasih telah menggunakan program BuildNet Gaming Center!\n"); break;
            default: printf("\n>> Pilihan tidak valid, silakan pilih 1-6.\n");
        }
    } while (pilihan != 6);
    return 0;
}