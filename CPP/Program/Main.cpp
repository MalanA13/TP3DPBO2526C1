// Main.cpp - Program utama Sistem Manajemen Bioskop
// Mendemonstrasikan inheritance, composition, dan vector objek.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "Tiket.cpp"
using namespace std;

using Rows = vector<vector<string>>;

void printTable(const vector<string>& headers, const Rows& rows) {
    vector<size_t> widths;
    for (size_t i = 0; i < headers.size(); ++i) {
        size_t width = headers[i].size();
        for (const auto& row : rows) width = max(width, row[i].size());
        widths.push_back(width);
    }
    auto border = [&]() { cout << "+"; for (size_t width : widths) cout << string(width + 2, '-') << "+"; cout << '\n'; };
    auto line = [&](const vector<string>& row) { cout << "|"; for (size_t i = 0; i < row.size(); ++i) cout << " " << row[i] << string(widths[i] - row[i].size() + 1, ' ') << "|"; cout << '\n'; };
    border(); line(headers); border();
    for (const auto& row : rows) line(row);
    border();
}

Rows filmRows(const vector<Film*>& films) {
    Rows rows;
    for (size_t i = 0; i < films.size(); ++i) {
        string detail1, detail2;
        if (auto fb = dynamic_cast<FilmBerdurasi*>(films[i])) { detail1 = "Durasi: " + fb->getDurasi(); detail2 = "Sutradara: " + fb->getSutradara(); }
        else if (auto fa = dynamic_cast<FilmAnimasi*>(films[i])) { detail1 = "Studio: " + fa->getStudioAnimasi(); detail2 = "Teknik: " + fa->getTeknikAnimasi(); }
        rows.push_back({to_string(i + 1), films[i]->getId(), films[i]->getJudul(), films[i]->getGenre(), detail1, detail2});
    }
    return rows;
}

void printFilm(const vector<Film*>& films) { printTable({"No", "ID", "Judul", "Genre", "Detail 1", "Detail 2"}, filmRows(films)); cout << "Total: " << films.size() << " film\n"; }
void printTiket(vector<Tiket>& tikets) {
    Rows rows;
    for (size_t i = 0; i < tikets.size(); ++i) rows.push_back({to_string(i + 1), tikets[i].getKodeTiket(), tikets[i].getStudio(), tikets[i].getJam(), "Rp" + to_string(tikets[i].getHarga()), tikets[i].getFilm()->getJudul(), tikets[i].getFilm()->getGenre()});
    printTable({"No", "Kode", "Studio", "Jam", "Harga", "Film", "Genre"}, rows); cout << "Total: " << tikets.size() << " tiket\n";
}

bool readText(const string& prompt, string& value) {
    while (true) { cout << prompt; if (!getline(cin, value)) return false; if (!value.empty()) return true; cout << "Input tidak boleh kosong.\n"; }
}
bool hasFilmId(const vector<Film*>& films, const string& id) { for (Film* film : films) if (film->getId() == id) return true; return false; }
bool hasTicketCode(vector<Tiket>& tikets, const string& code) { for (auto& tiket : tikets) if (tiket.getKodeTiket() == code) return true; return false; }
bool readUniqueFilmId(const vector<Film*>& films, string& id) { while (readText("ID film: ", id)) { if (!hasFilmId(films, id)) return true; cout << "ID film sudah digunakan.\n"; } return false; }
bool readUniqueTicketCode(vector<Tiket>& tikets, string& code) { while (readText("Kode tiket: ", code)) { if (!hasTicketCode(tikets, code)) return true; cout << "Kode tiket sudah digunakan.\n"; } return false; }
bool readPositiveInt(const string& prompt, int& result) {
    string text;
    while (readText(prompt, text)) { try { size_t used; int value = stoi(text, &used); if (used == text.size() && value > 0) { result = value; return true; } } catch (...) {} cout << "Masukkan angka positif yang valid.\n"; }
    return false;
}

bool tambahFilmBerdurasi(vector<Film*>& films) { string id, judul, genre, durasi, sutradara; return readUniqueFilmId(films, id) && readText("Judul: ", judul) && readText("Genre: ", genre) && readText("Durasi: ", durasi) && readText("Sutradara: ", sutradara) ? (films.push_back(new FilmBerdurasi(id, judul, genre, durasi, sutradara)), true) : false; }
bool tambahFilmAnimasi(vector<Film*>& films) { string id, judul, genre, studio, teknik; return readUniqueFilmId(films, id) && readText("Judul: ", judul) && readText("Genre: ", genre) && readText("Studio animasi: ", studio) && readText("Teknik animasi: ", teknik) ? (films.push_back(new FilmAnimasi(id, judul, genre, studio, teknik)), true) : false; }
bool tambahTiket(vector<Tiket>& tikets, const vector<Film*>& films) {
    string kode, studio, jam; int harga, nomor;
    if (!readUniqueTicketCode(tikets, kode) || !readText("Studio: ", studio) || !readText("Jam: ", jam) || !readPositiveInt("Harga: ", harga)) return false;
    printFilm(films);
    while (readPositiveInt("Pilih nomor film: ", nomor)) { if (nomor <= static_cast<int>(films.size())) { tikets.emplace_back(kode, studio, jam, harga, films[nomor - 1]); return true; } cout << "Nomor film tidak tersedia.\n"; }
    return false;
}

int main() {
    vector<Film*> films = {new FilmBerdurasi("F01", "The Dark Knight", "Action", "152 menit", "Christopher Nolan"), new FilmBerdurasi("F02", "Parasite", "Thriller", "132 menit", "Bong Joon-ho"), new FilmBerdurasi("F03", "Interstellar", "Sci-Fi", "169 menit", "Christopher Nolan"), new FilmAnimasi("F04", "Spirited Away", "Fantasy", "Studio Ghibli", "2D Hand-drawn"), new FilmAnimasi("F05", "Inside Out 2", "Comedy", "Pixar", "3D CGI"), new FilmAnimasi("F06", "Spider-Verse", "Action", "Sony Pictures", "3D Stylized")};
    vector<Tiket> tikets = {Tiket("T001", "Studio 1", "13:00", 50000, films[0]), Tiket("T002", "Studio 2", "15:30", 45000, films[1]), Tiket("T003", "Studio 3", "18:00", 60000, films[3]), Tiket("T004", "Studio 1", "20:00", 75000, films[4])};
    cout << "===== DATA FILM SEBELUM PENAMBAHAN =====\n"; printFilm(films); cout << "\n===== DATA TIKET SEBELUM PENAMBAHAN =====\n"; printTiket(tikets);
    string choice;
    while (true) { cout << "\n1. Tambah film berdurasi\n2. Tambah film animasi\n3. Tambah tiket\n4. Tampilkan semua data\n5. Selesai\nPilihan: "; if (!getline(cin, choice) || choice == "5") break; if (choice == "1") tambahFilmBerdurasi(films); else if (choice == "2") tambahFilmAnimasi(films); else if (choice == "3") tambahTiket(tikets, films); else if (choice == "4") { printFilm(films); printTiket(tikets); } else cout << "Pilihan tidak valid.\n"; }
    cout << "\n===== DATA FILM SETELAH PENAMBAHAN =====\n"; printFilm(films); cout << "\n===== DATA TIKET SETELAH PENAMBAHAN =====\n"; printTiket(tikets); for (Film* film : films) delete film;
}