// FilmAnimasi.java - Kelas turunan (child) dari Film
// Merupakan bagian dari Hierarchical Inheritance: Film -> FilmAnimasi
// Menambahkan atribut studioAnimasi dan teknikAnimasi

public class FilmAnimasi extends Film {
    private String studioAnimasi;
    private String teknikAnimasi;

    // Constructor memanggil constructor parent (Film) via super()
    public FilmAnimasi(String id, String judul, String genre, String studioAnimasi, String teknikAnimasi) {
        super(id, judul, genre);
        this.studioAnimasi = studioAnimasi;
        this.teknikAnimasi = teknikAnimasi;
    }

    // Getter
    public String getStudioAnimasi() { return studioAnimasi; }
    public String getTeknikAnimasi() { return teknikAnimasi; }

    // Setter
    public void setStudioAnimasi(String studioAnimasi) { this.studioAnimasi = studioAnimasi; }
    public void setTeknikAnimasi(String teknikAnimasi) { this.teknikAnimasi = teknikAnimasi; }

    // Override info() untuk menampilkan informasi lengkap
    @Override
    public String info() {
        return super.info() + ", Studio: " + studioAnimasi + ", Teknik: " + teknikAnimasi;
    }
}
