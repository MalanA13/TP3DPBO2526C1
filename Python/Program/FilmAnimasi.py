# FilmAnimasi.py - Kelas turunan (child) dari Film
# Merupakan bagian dari Hierarchical Inheritance: Film -> FilmAnimasi
# Menambahkan atribut studio_animasi dan teknik_animasi

from Film import Film

class FilmAnimasi(Film):
    def __init__(self, id, judul, genre, studio_animasi, teknik_animasi):
        super().__init__(id, judul, genre)  # Memanggil constructor parent
        self.__studio_animasi = studio_animasi  # Private attribute tambahan
        self.__teknik_animasi = teknik_animasi  # Private attribute tambahan

    # Getter
    def get_studio_animasi(self):
        return self.__studio_animasi

    def get_teknik_animasi(self):
        return self.__teknik_animasi

    # Setter
    def set_studio_animasi(self, studio_animasi):
        self.__studio_animasi = studio_animasi

    def set_teknik_animasi(self, teknik_animasi):
        self.__teknik_animasi = teknik_animasi

    # Override info() untuk menampilkan informasi lengkap
    def info(self):
        return f"{super().info()}, Studio: {self.__studio_animasi}, Teknik: {self.__teknik_animasi}"
