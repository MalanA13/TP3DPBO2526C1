// Film.java - Kelas induk (parent) dalam hierarki pewarisan Film
// Kelas ini menjadi base class untuk FilmBerdurasi dan FilmAnimasi (Hierarchical Inheritance)

public class Film {
    private String id;
    private String judul;
    private String genre;

    // Constructor
    public Film(String id, String judul, String genre) {
        this.id = id;
        this.judul = judul;
        this.genre = genre;
    }

    // Getter
    public String getId() { return id; }
    public String getJudul() { return judul; }
    public String getGenre() { return genre; }

    // Setter
    public void setId(String id) { this.id = id; }
    public void setJudul(String judul) { this.judul = judul; }
    public void setGenre(String genre) { this.genre = genre; }

    // Method info() - di-override oleh kelas turunan
    public String info() {
        return "ID: " + id + ", Judul: " + judul + ", Genre: " + genre;
    }
}
