// Film.cpp - Kelas induk (parent) dalam hierarki pewarisan Film
// Kelas ini menjadi base class untuk FilmBerdurasi dan FilmAnimasi (Hierarchical Inheritance)
#ifndef FILM_CPP
#define FILM_CPP

#include <string>
#include <sstream>
using namespace std;

class Film {
private:
    string id;
    string judul;
    string genre;

public:
    // Constructor
    Film(string id, string judul, string genre)
        : id(id), judul(judul), genre(genre) {}

    // Getter
    string getId() { return id; }
    string getJudul() { return judul; }
    string getGenre() { return genre; }

    // Setter
    void setId(string id) { this->id = id; }
    void setJudul(string judul) { this->judul = judul; }
    void setGenre(string genre) { this->genre = genre; }

    // Method info() - virtual agar bisa di-override oleh kelas turunan
    virtual string info() {
        stringstream ss;
        ss << "ID: " << id << ", Judul: " << judul << ", Genre: " << genre;
        return ss.str();
    }

    // Virtual destructor untuk hierarki pewarisan
    virtual ~Film() {}
};

#endif
