# main.py - Program utama Sistem Manajemen Bioskop
# Mendemonstrasikan inheritance, composition, dan list objek.
from FilmBerdurasi import FilmBerdurasi
from FilmAnimasi import FilmAnimasi
from Tiket import Tiket


def print_table(headers, rows):
    widths = [max(len(header), *(len(row[i]) for row in rows)) for i, header in enumerate(headers)]
    border = "+" + "+".join("-" * (width + 2) for width in widths) + "+"
    def line(row):
        return "|" + "|".join(f" {value:<{widths[i]}} " for i, value in enumerate(row)) + "|"
    print(border); print(line(headers)); print(border)
    for row in rows: print(line(row))
    print(border)


def film_rows(films):
    rows = []
    for number, film in enumerate(films, 1):
        if isinstance(film, FilmBerdurasi): detail1, detail2 = f"Durasi: {film.get_durasi()}", f"Sutradara: {film.get_sutradara()}"
        else: detail1, detail2 = f"Studio: {film.get_studio_animasi()}", f"Teknik: {film.get_teknik_animasi()}"
        rows.append([str(number), film.get_id(), film.get_judul(), film.get_genre(), detail1, detail2])
    return rows


def print_film(films):
    print_table(["No", "ID", "Judul", "Genre", "Detail 1", "Detail 2"], film_rows(films)); print(f"Total: {len(films)} film")


def print_tiket(tikets):
    rows = [[str(i), t.get_kode_tiket(), t.get_studio(), t.get_jam(), f"Rp{t.get_harga()}", t.get_film().get_judul(), t.get_film().get_genre()] for i, t in enumerate(tikets, 1)]
    print_table(["No", "Kode", "Studio", "Jam", "Harga", "Film", "Genre"], rows); print(f"Total: {len(tikets)} tiket")


def read_text(prompt):
    while True:
        try: value = input(prompt).strip()
        except EOFError: return None
        if value: return value
        print("Input tidak boleh kosong.")


def read_positive_int(prompt):
    while True:
        text = read_text(prompt)
        if text is None: return None
        try:
            value = int(text)
            if value > 0: return value
        except ValueError: pass
        print("Masukkan angka positif yang valid.")


def read_unique(prompt, existing, duplicate_message):
    while True:
        value = read_text(prompt)
        if value is None or value not in existing: return value
        print(duplicate_message)


def tambah_film_berdurasi(films):
    film_id = read_unique("ID film: ", {film.get_id() for film in films}, "ID film sudah digunakan.")
    values = [film_id, read_text("Judul: "), read_text("Genre: "), read_text("Durasi: "), read_text("Sutradara: ")]
    if all(values): films.append(FilmBerdurasi(*values))


def tambah_film_animasi(films):
    film_id = read_unique("ID film: ", {film.get_id() for film in films}, "ID film sudah digunakan.")
    values = [film_id, read_text("Judul: "), read_text("Genre: "), read_text("Studio animasi: "), read_text("Teknik animasi: ")]
    if all(values): films.append(FilmAnimasi(*values))


def tambah_tiket(tikets, films):
    kode = read_unique("Kode tiket: ", {t.get_kode_tiket() for t in tikets}, "Kode tiket sudah digunakan.")
    studio, jam, harga = read_text("Studio: "), read_text("Jam: "), read_positive_int("Harga: ")
    if not all((kode, studio, jam, harga)): return
    print_film(films)
    while True:
        nomor = read_positive_int("Pilih nomor film: ")
        if nomor is None: return
        if nomor <= len(films): tikets.append(Tiket(kode, studio, jam, harga, films[nomor - 1])); return
        print("Nomor film tidak tersedia.")


def main():
    films = [FilmBerdurasi("F01", "The Dark Knight", "Action", "152 menit", "Christopher Nolan"), FilmBerdurasi("F02", "Parasite", "Thriller", "132 menit", "Bong Joon-ho"), FilmBerdurasi("F03", "Interstellar", "Sci-Fi", "169 menit", "Christopher Nolan"), FilmAnimasi("F04", "Spirited Away", "Fantasy", "Studio Ghibli", "2D Hand-drawn"), FilmAnimasi("F05", "Inside Out 2", "Comedy", "Pixar", "3D CGI"), FilmAnimasi("F06", "Spider-Verse", "Action", "Sony Pictures", "3D Stylized")]
    tikets = [Tiket("T001", "Studio 1", "13:00", 50000, films[0]), Tiket("T002", "Studio 2", "15:30", 45000, films[1]), Tiket("T003", "Studio 3", "18:00", 60000, films[3]), Tiket("T004", "Studio 1", "20:00", 75000, films[4])]
    print("===== DATA FILM SEBELUM PENAMBAHAN ====="); print_film(films); print("\n===== DATA TIKET SEBELUM PENAMBAHAN ====="); print_tiket(tikets)
    while True:
        print("\n1. Tambah film berdurasi\n2. Tambah film animasi\n3. Tambah tiket\n4. Tampilkan semua data\n5. Selesai")
        choice = read_text("Pilihan: ")
        if choice is None or choice == "5": break
        if choice == "1": tambah_film_berdurasi(films)
        elif choice == "2": tambah_film_animasi(films)
        elif choice == "3": tambah_tiket(tikets, films)
        elif choice == "4": print_film(films); print_tiket(tikets)
        else: print("Pilihan tidak valid.")
    print("\n===== DATA FILM SETELAH PENAMBAHAN ====="); print_film(films); print("\n===== DATA TIKET SETELAH PENAMBAHAN ====="); print_tiket(tikets)


if __name__ == "__main__": main()