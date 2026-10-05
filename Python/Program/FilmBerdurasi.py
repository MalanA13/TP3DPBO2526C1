# FilmBerdurasi.py - Kelas turunan (child) dari Film
# Merupakan bagian dari Hierarchical Inheritance: Film -> FilmBerdurasi
# Menambahkan atribut durasi dan sutradara

from Film import Film

class FilmBerdurasi(Film):
    def __init__(self, id, judul, genre, durasi, sutradara):
        super().__init__(id, judul, genre)  # Memanggil constructor parent
        self.__durasi = durasi          # Private attribute tambahan
        self.__sutradara = sutradara    # Private attribute tambahan

    # Getter
    def get_durasi(self):
        return self.__durasi

    def get_sutradara(self):
        return self.__sutradara

    # Setter
    def set_durasi(self, durasi):
        self.__durasi = durasi

    def set_sutradara(self, sutradara):
        self.__sutradara = sutradara

    # Override info() untuk menampilkan informasi lengkap
    def info(self):
        return f"{super().info()}, Durasi: {self.__durasi}, Sutradara: {self.__sutradara}"
