// Tiket.cpp - Kelas yang memiliki relasi Composition (HAS-A) dengan Film
// Tiket memiliki objek Film sebagai atribut (Composition)
// Film yang disimpan bisa berupa FilmBerdurasi atau FilmAnimasi (polimorfisme)
#ifndef TIKET_CPP
#define TIKET_CPP

#include "FilmBerdurasi.cpp"
#include "FilmAnimasi.cpp"

class Tiket {
private:
    string kodeTiket;
    string studio;
    string jam;
    int harga;
    Film* film; // Composition: Tiket HAS-A Film (menggunakan pointer untuk polimorfisme)

public:
    // Constructor menerima pointer Film (bisa FilmBerdurasi atau FilmAnimasi)
    Tiket(string kodeTiket, string studio, string jam, int harga, Film* film)
        : kodeTiket(kodeTiket), studio(studio), jam(jam), harga(harga), film(film) {}

    // Getter
    string getKodeTiket() { return kodeTiket; }
    string getStudio() { return studio; }
    string getJam() { return jam; }
    int getHarga() { return harga; }
    Film* getFilm() { return film; }

    // Setter
    void setKodeTiket(string kodeTiket) { this->kodeTiket = kodeTiket; }
    void setStudio(string studio) { this->studio = studio; }
    void setJam(string jam) { this->jam = jam; }
    void setHarga(int harga) { this->harga = harga; }
    void setFilm(Film* film) { this->film = film; }

    // Method info() menampilkan info tiket beserta info film (composition)
    string info() {
        stringstream ss;
        ss << "Kode: " << kodeTiket << ", Studio: " << studio
           << ", Jam: " << jam << ", Harga: Rp" << harga
           << " | Film -> " << film->info();
        return ss.str();
    }
};

#endif
