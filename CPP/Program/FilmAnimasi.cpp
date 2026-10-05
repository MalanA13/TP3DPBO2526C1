// FilmAnimasi.cpp - Kelas turunan (child) dari Film
// Merupakan bagian dari Hierarchical Inheritance: Film -> FilmAnimasi
// Menambahkan atribut studioAnimasi dan teknikAnimasi
#ifndef FILMANIMASI_CPP
#define FILMANIMASI_CPP

#include "Film.cpp"

class FilmAnimasi : public Film {
private:
    string studioAnimasi;
    string teknikAnimasi;

public:
    // Constructor memanggil constructor parent (Film)
    FilmAnimasi(string id, string judul, string genre, string studioAnimasi, string teknikAnimasi)
        : Film(id, judul, genre), studioAnimasi(studioAnimasi), teknikAnimasi(teknikAnimasi) {}

    // Getter
    string getStudioAnimasi() { return studioAnimasi; }
    string getTeknikAnimasi() { return teknikAnimasi; }

    // Setter
    void setStudioAnimasi(string studioAnimasi) { this->studioAnimasi = studioAnimasi; }
    void setTeknikAnimasi(string teknikAnimasi) { this->teknikAnimasi = teknikAnimasi; }

    // Override info() untuk menampilkan informasi lengkap termasuk atribut tambahan
    string info() override {
        stringstream ss;
        ss << Film::info() << ", Studio: " << studioAnimasi << ", Teknik: " << teknikAnimasi;
        return ss.str();
    }
};

#endif
