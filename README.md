# Learning-C-Unud
Code Aku Dari Pembelajaran Di Unud

## 🚀 Cara Menggunakan

### Clone Repository

```bash
git clone https://github.com/...
cd (file-name)
```

### Sebelum Mengubah Kode

Ambil perubahan terbaru dari repository sebelum mulai bekerja:

```bash
git pull --rebase origin main
```

### Setelah Mengubah Kode

Tambahkan perubahan, buat commit dengan tipe pesan yang sesuai, lalu kirim ke repository:

```bash
git status
git add .
git commit -m "feat: tambah program baru"
git push origin main
```

### Compile dan Jalankan Program C

```bash
gcc nama_file.c -o output
./output
```

## 📝 Tipe Pesan Commit

Gunakan format berikut agar pesan commit konsisten:

| Tipe       | Kegunaan                                             | Contoh                                     |
| ---------- | ---------------------------------------------------- | ------------------------------------------ |
| `feat`     | Menambahkan fitur baru                               | `feat: tambah fungsi konversi suhu`        |
| `fix`      | Memperbaiki bug                                      | `fix: perbaiki perhitungan luas lingkaran` |
| `docs`     | Mengubah dokumentasi                                 | `docs: update panduan instalasi`           |
| `style`    | Merapikan format kode tanpa mengubah logika          | `style: rapikan indentasi kode`            |
| `refactor` | Merestrukturisasi kode tanpa mengubah fungsionalitas | `refactor: pisahkan fungsi perhitungan`    |
