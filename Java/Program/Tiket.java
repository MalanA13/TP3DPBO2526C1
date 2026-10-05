// Tiket.java - Kelas yang memiliki relasi Composition (HAS-A) dengan Film
// Tiket memiliki objek Film sebagai atribut (Composition)
// Film yang disimpan bisa berupa FilmBerdurasi atau FilmAnimasi

public class Tiket {
    private String kodeTiket;
    private String studio;
    private String jam;
    private int harga;
    private Film film; // Composition: Tiket HAS-A Film

    // Constructor menerima objek Film (bisa FilmBerdurasi atau FilmAnimasi)
    public Tiket(String kodeTiket, String studio, String jam, int harga, Film film) {
        this.kodeTiket = kodeTiket;
        this.studio = studio;
        this.jam = jam;
        this.harga = harga;
        this.film = film;
    }

    // Getter
    public String getKodeTiket() { return kodeTiket; }
    public String getStudio() { return studio; }
    public String getJam() { return jam; }
    public int getHarga() { return harga; }
    public Film getFilm() { return film; }

    // Setter
    public void setKodeTiket(String kodeTiket) { this.kodeTiket = kodeTiket; }
    public void setStudio(String studio) { this.studio = studio; }
    public void setJam(String jam) { this.jam = jam; }
    public void setHarga(int harga) { this.harga = harga; }
    public void setFilm(Film film) { this.film = film; }

    // Method info() menampilkan info tiket beserta info film (composition)
    public String info() {
        return "Kode: " + kodeTiket + ", Studio: " + studio
             + ", Jam: " + jam + ", Harga: Rp" + harga
             + " | Film -> " + film.info();
    }
}
