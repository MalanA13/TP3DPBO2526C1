// FilmBerdurasi.cpp - Kelas turunan (child) dari Film
// Merupakan bagian dari Hierarchical Inheritance: Film -> FilmBerdurasi
// Menambahkan atribut durasi dan sutradara
#ifndef FILMBERDURASI_CPP
#define FILMBERDURASI_CPP

#include "Film.cpp"

class FilmBerdurasi : public Film {
private:
    string durasi;
    string sutradara;

public:
    // Constructor memanggil constructor parent (Film)
    FilmBerdurasi(string id, string judul, string genre, string durasi, string sutradara)
        : Film(id, judul, genre), durasi(durasi), sutradara(sutradara) {}

    // Getter
    string getDurasi() { return durasi; }
    string getSutradara() { return sutradara; }

    // Setter
    void setDurasi(string durasi) { this->durasi = durasi; }
    void setSutradara(string sutradara) { this->sutradara = sutradara; }

    // Override info() untuk menampilkan informasi lengkap termasuk atribut tambahan
    string info() override {
        stringstream ss;
        ss << Film::info() << ", Durasi: " << durasi << ", Sutradara: " << sutradara;
        return ss.str();
    }
};

#endif
