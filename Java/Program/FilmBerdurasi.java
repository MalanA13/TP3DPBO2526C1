// FilmBerdurasi.java - Kelas turunan (child) dari Film
// Merupakan bagian dari Hierarchical Inheritance: Film -> FilmBerdurasi
// Menambahkan atribut durasi dan sutradara

public class FilmBerdurasi extends Film {
    private String durasi;
    private String sutradara;

    // Constructor memanggil constructor parent (Film) via super()
    public FilmBerdurasi(String id, String judul, String genre, String durasi, String sutradara) {
        super(id, judul, genre);
        this.durasi = durasi;
        this.sutradara = sutradara;
    }

    // Getter
    public String getDurasi() { return durasi; }
    public String getSutradara() { return sutradara; }

    // Setter
    public void setDurasi(String durasi) { this.durasi = durasi; }
    public void setSutradara(String sutradara) { this.sutradara = sutradara; }

    // Override info() untuk menampilkan informasi lengkap
    @Override
    public String info() {
        return super.info() + ", Durasi: " + durasi + ", Sutradara: " + sutradara;
    }
}
