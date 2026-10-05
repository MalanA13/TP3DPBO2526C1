# Tiket.py - Kelas yang memiliki relasi Composition (HAS-A) dengan Film
# Tiket memiliki objek Film sebagai atribut (Composition)
# Film yang disimpan bisa berupa FilmBerdurasi atau FilmAnimasi

from FilmBerdurasi import FilmBerdurasi
from FilmAnimasi import FilmAnimasi

class Tiket:
    def __init__(self, kode_tiket, studio, jam, harga, film):
        self.__kode_tiket = kode_tiket  # Private attribute
        self.__studio = studio          # Private attribute
        self.__jam = jam                # Private attribute
        self.__harga = harga            # Private attribute (integer)
        self.__film = film              # Composition: Tiket HAS-A Film

    # Getter
    def get_kode_tiket(self):
        return self.__kode_tiket

    def get_studio(self):
        return self.__studio

    def get_jam(self):
        return self.__jam

    def get_harga(self):
        return self.__harga

    def get_film(self):
        return self.__film

    # Setter
    def set_kode_tiket(self, kode_tiket):
        self.__kode_tiket = kode_tiket

    def set_studio(self, studio):
        self.__studio = studio

    def set_jam(self, jam):
        self.__jam = jam

    def set_harga(self, harga):
        self.__harga = harga

    def set_film(self, film):
        self.__film = film

    # Method info() menampilkan info tiket beserta info film (composition)
    def info(self):
        return (f"Kode: {self.__kode_tiket}, Studio: {self.__studio}, "
                f"Jam: {self.__jam}, Harga: Rp{self.__harga} | Film -> {self.__film.info()}")
