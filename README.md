# TP3 DPBO - Sistem Manajemen Bioskop

## Janji

Saya Muhammad Alan Andika dengan NIM 2400353 mengerjakan Tugas Praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

## Desain Program

Diagram kelas Mermaid tersedia di [`design-diagram.svg`](desgin-diagram.svg).


- `Film` adalah kelas induk dengan atribut private `id`, `judul`, dan `genre`.
- `FilmBerdurasi` menambah `durasi` dan `sutradara`; `FilmAnimasi` menambah `studioAnimasi` dan `teknikAnimasi`.
- `Tiket` memiliki satu referensi `Film` (HAS-A/composition) sehingga tiket dapat menunjuk film dari list pusat.
- Semua kelas memakai atribut private, getter/setter, serta `info()` yang dapat dipakai untuk menampilkan data.

## Penjelasan Atribut dan Method Setiap Kelas

### 1. Kelas `Film`

`Film` adalah parent class. Kelas ini menampung informasi umum yang pasti dimiliki seluruh film, sehingga atribut tersebut tidak perlu ditulis ulang pada setiap jenis film.

| Atribut | Tipe | Keterangan |
|---|---|---|
| `id` | `string` / `String` | Identitas unik film, misalnya `F01`. |
| `judul` | `string` / `String` | Judul film. |
| `genre` | `string` / `String` | Genre film, misalnya Action atau Fantasy. |

| Method | Keterangan |
|---|---|
| `Film(id, judul, genre)` | Constructor untuk mengisi tiga atribut dasar film. |
| `getId()`, `getJudul()`, `getGenre()` | Mengambil nilai atribut film. |
| `setId()`, `setJudul()`, `setGenre()` | Mengubah nilai atribut film secara terkontrol. |
| `info()` | Mengembalikan informasi dasar film dalam bentuk teks. Method ini dapat dioverride oleh kelas turunan. |

### 2. Kelas `FilmBerdurasi`

`FilmBerdurasi` adalah child class dari `Film`. Kelas ini dipakai untuk film biasa atau live-action yang memiliki durasi dan sutradara.

| Atribut Tambahan | Tipe | Keterangan |
|---|---|---|
| `durasi` | `string` / `String` | Lama pemutaran film, misalnya `152 menit`. |
| `sutradara` | `string` / `String` | Nama sutradara film. |

| Method | Keterangan |
|---|---|
| `FilmBerdurasi(id, judul, genre, durasi, sutradara)` | Constructor. Memanggil constructor `Film` dengan `super()` pada Python/Java atau initializer parent pada C++. |
| `getDurasi()`, `getSutradara()` | Mengambil durasi dan nama sutradara. |
| `setDurasi()`, `setSutradara()` | Mengubah durasi dan nama sutradara. |
| `info()` | Override dari `Film.info()`. Menambah informasi durasi dan sutradara. |

### 3. Kelas `FilmAnimasi`

`FilmAnimasi` juga child class dari `Film`. Kelas ini menyimpan data khusus film animasi yang tidak relevan untuk film biasa.

| Atribut Tambahan | Tipe | Keterangan |
|---|---|---|
| `studioAnimasi` | `string` / `String` | Studio pembuat animasi, misalnya Pixar atau Studio Ghibli. |
| `teknikAnimasi` | `string` / `String` | Teknik animasi, misalnya `3D CGI` atau `2D Hand-drawn`. |

| Method | Keterangan |
|---|---|
| `FilmAnimasi(id, judul, genre, studioAnimasi, teknikAnimasi)` | Constructor. Memanggil constructor `Film`, lalu mengisi atribut khusus animasi. |
| `getStudioAnimasi()`, `getTeknikAnimasi()` | Mengambil studio dan teknik animasi. |
| `setStudioAnimasi()`, `setTeknikAnimasi()` | Mengubah studio dan teknik animasi. |
| `info()` | Override dari `Film.info()`. Menambah studio dan teknik animasi. |

### 4. Kelas `Tiket`

`Tiket` merepresentasikan tiket tayang bioskop. Tiket memiliki data transaksi sendiri dan menyimpan referensi ke satu objek `Film`.

| Atribut | Tipe | Keterangan |
|---|---|---|
| `kodeTiket` | `string` / `String` | Identitas unik tiket, misalnya `T001`. |
| `studio` | `string` / `String` | Studio tempat film ditayangkan. |
| `jam` | `string` / `String` | Jadwal jam tayang. |
| `harga` | `int` | Harga tiket dalam Rupiah. |
| `film` | `Film` | Objek film yang terkait dengan tiket. Dapat berisi `FilmBerdurasi` atau `FilmAnimasi`. |

| Method | Keterangan |
|---|---|
| `Tiket(kodeTiket, studio, jam, harga, film)` | Constructor untuk membentuk tiket dan menghubungkannya dengan satu film. |
| `getKodeTiket()`, `getStudio()`, `getJam()`, `getHarga()`, `getFilm()` | Mengambil seluruh data tiket, termasuk objek film yang dipilih. |
| `setKodeTiket()`, `setStudio()`, `setJam()`, `setHarga()`, `setFilm()` | Mengubah data tiket atau film yang terhubung. |
| `info()` | Mengembalikan informasi tiket beserta informasi film terkait. |

## Penjelasan Inheritance dan Composition

### Hierarchical Inheritance

Program memakai hierarchical inheritance karena satu parent class, yaitu `Film`, mempunyai dua child class pada tingkat yang sama:

```text
Film
├── FilmBerdurasi
└── FilmAnimasi
```

- `FilmBerdurasi` IS-A `Film`. Artinya, setiap FilmBerdurasi adalah Film dan otomatis mempunyai `id`, `judul`, serta `genre` dari parent class.
- `FilmAnimasi` IS-A `Film`. Artinya, setiap FilmAnimasi juga Film dan mewarisi tiga atribut dasar tersebut.
- Kedua child class menambah atribut spesifik masing-masing. Karena itu, atribut umum tidak diduplikasi, tetapi data khusus tiap jenis film tetap tersimpan dengan jelas.
- Objek film disimpan dalam satu list/array bertipe `Film`. List ini dapat menyimpan objek dari dua child class. Saat tabel dicetak, program mengecek jenis objek untuk menampilkan detail yang sesuai.

### Composition

Program memakai hubungan HAS-A antara `Tiket` dan `Film`:

```text
Tiket HAS-A Film
```

Setiap objek `Tiket` menyimpan satu referensi objek `Film`. Tiket tidak cukup hanya menyimpan judul film sebagai teks, karena program perlu mengambil data film seperti judul dan genre langsung dari objek yang dipilih. Saat pengguna menambah tiket, program menampilkan daftar film, lalu pengguna memilih nomor film. Objek film terpilih disimpan pada atribut `film` milik Tiket.

Dengan desain ini, satu film dapat memiliki banyak tiket untuk studio atau jam tayang yang berbeda, sedangkan satu tiket hanya terkait dengan satu film. Tiket dapat terhubung ke `FilmBerdurasi` maupun `FilmAnimasi` karena keduanya merupakan turunan `Film`.

## Alur Program

1. Program membuat tepat 6 data film awal: 3 `FilmBerdurasi` dan 3 `FilmAnimasi`.
2. Program membuat tepat 4 tiket awal yang mereferensikan film awal.
3. Tabel film dan tiket awal dicetak sebelum input pengguna.
4. Menu berulang menyediakan tambah film berdurasi, tambah film animasi, tambah tiket, tampilkan semua data, dan selesai.
5. ID film serta kode tiket wajib tidak kosong dan unik. Harga harus angka positif. Saat tambah tiket, pengguna memilih nomor film yang tersedia.
6. Saat memilih `Selesai`, seluruh tabel film dan tiket dicetak lagi setelah penambahan.

Lebar tiap kolom tabel dihitung dari panjang header dan seluruh nilai pada kolom saat tabel dicetak. Border dan baris memakai format `+---+` serta `| nilai |`, sehingga nilai string panjang tidak meluber atau membuat kolom berantakan.

## Struktur Koleksi

- C++: `vector<Film*>` dan `vector<Tiket>`; semua pointer `Film` dibersihkan sebelum program selesai.
- Python: `list` untuk film dan tiket.
- Java: `ArrayList<Film>` dan `ArrayList<Tiket>`.

## Menjalankan Program

```bash
cd CPP/Program && g++ -std=c++17 Main.cpp -o main && ./main
cd Python/Program && python3 main.py
cd Java/Program && javac *.java && java Main
```

## Dokumentasi

- C++: [`CPP/Dokumentasi/`](CPP/Dokumentasi/)
- Python: [`Python/Dokumentasi/`](Python/Dokumentasi/)
- Java: [`Java/Dokumentasi/`](Java/Dokumentasi/)
