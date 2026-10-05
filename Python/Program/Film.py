# Film.py - Kelas induk (parent) dalam hierarki pewarisan Film
# Kelas ini menjadi base class untuk FilmBerdurasi dan FilmAnimasi (Hierarchical Inheritance)

class Film:
    def __init__(self, id, judul, genre):
        self.__id = id          # Private attribute
        self.__judul = judul    # Private attribute
        self.__genre = genre    # Private attribute

    # Getter
    def get_id(self):
        return self.__id

    def get_judul(self):
        return self.__judul

    def get_genre(self):
        return self.__genre

    # Setter
    def set_id(self, id):
        self.__id = id

    def set_judul(self, judul):
        self.__judul = judul

    def set_genre(self, genre):
        self.__genre = genre

    # Method info() - akan di-override oleh kelas turunan
    def info(self):
        return f"ID: {self.__id}, Judul: {self.__judul}, Genre: {self.__genre}"
