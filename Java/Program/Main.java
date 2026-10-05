// Main.java - Program utama Sistem Manajemen Bioskop
// Mendemonstrasikan inheritance, composition, dan ArrayList objek.
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static void printTable(String[] headers, ArrayList<String[]> rows) {
        int[] widths = new int[headers.length];
        for (int i = 0; i < headers.length; i++) { widths[i] = headers[i].length(); for (String[] row : rows) widths[i] = Math.max(widths[i], row[i].length()); }
        StringBuilder border = new StringBuilder("+");
        for (int width : widths) border.append("-".repeat(width + 2)).append("+");
        System.out.println(border);
        printLine(headers, widths); System.out.println(border);
        for (String[] row : rows) printLine(row, widths);
        System.out.println(border);
    }
    static void printLine(String[] row, int[] widths) { StringBuilder line = new StringBuilder("|"); for (int i = 0; i < row.length; i++) line.append(" ").append(String.format("%-" + widths[i] + "s", row[i])).append(" |"); System.out.println(line); }
    static ArrayList<String[]> filmRows(ArrayList<Film> films) {
        ArrayList<String[]> rows = new ArrayList<>();
        for (int i = 0; i < films.size(); i++) { Film film = films.get(i); String detail1, detail2; if (film instanceof FilmBerdurasi) { FilmBerdurasi fb = (FilmBerdurasi) film; detail1 = "Durasi: " + fb.getDurasi(); detail2 = "Sutradara: " + fb.getSutradara(); } else { FilmAnimasi fa = (FilmAnimasi) film; detail1 = "Studio: " + fa.getStudioAnimasi(); detail2 = "Teknik: " + fa.getTeknikAnimasi(); } rows.add(new String[]{String.valueOf(i + 1), film.getId(), film.getJudul(), film.getGenre(), detail1, detail2}); }
        return rows;
    }
    static void printFilm(ArrayList<Film> films) { printTable(new String[]{"No", "ID", "Judul", "Genre", "Detail 1", "Detail 2"}, filmRows(films)); System.out.println("Total: " + films.size() + " film"); }
    static void printTiket(ArrayList<Tiket> tikets) { ArrayList<String[]> rows = new ArrayList<>(); for (int i = 0; i < tikets.size(); i++) { Tiket t = tikets.get(i); rows.add(new String[]{String.valueOf(i + 1), t.getKodeTiket(), t.getStudio(), t.getJam(), "Rp" + t.getHarga(), t.getFilm().getJudul(), t.getFilm().getGenre()}); } printTable(new String[]{"No", "Kode", "Studio", "Jam", "Harga", "Film", "Genre"}, rows); System.out.println("Total: " + tikets.size() + " tiket"); }
    static String readText(Scanner scanner, String prompt) { while (true) { System.out.print(prompt); if (!scanner.hasNextLine()) return null; String value = scanner.nextLine().trim(); if (!value.isEmpty()) return value; System.out.println("Input tidak boleh kosong."); } }
    static Integer readPositiveInt(Scanner scanner, String prompt) { while (true) { String text = readText(scanner, prompt); if (text == null) return null; try { int value = Integer.parseInt(text); if (value > 0) return value; } catch (NumberFormatException ignored) {} System.out.println("Masukkan angka positif yang valid."); } }
    static boolean hasFilmId(ArrayList<Film> films, String id) { for (Film film : films) if (film.getId().equals(id)) return true; return false; }
    static boolean hasTicketCode(ArrayList<Tiket> tikets, String code) { for (Tiket tiket : tikets) if (tiket.getKodeTiket().equals(code)) return true; return false; }
    static String readUniqueFilmId(Scanner s, ArrayList<Film> films) { while (true) { String id = readText(s, "ID film: "); if (id == null || !hasFilmId(films, id)) return id; System.out.println("ID film sudah digunakan."); } }
    static String readUniqueTicketCode(Scanner s, ArrayList<Tiket> tikets) { while (true) { String code = readText(s, "Kode tiket: "); if (code == null || !hasTicketCode(tikets, code)) return code; System.out.println("Kode tiket sudah digunakan."); } }
    static void tambahFilmBerdurasi(Scanner s, ArrayList<Film> films) { String id = readUniqueFilmId(s, films), judul = readText(s, "Judul: "), genre = readText(s, "Genre: "), durasi = readText(s, "Durasi: "), sutradara = readText(s, "Sutradara: "); if (id != null && judul != null && genre != null && durasi != null && sutradara != null) films.add(new FilmBerdurasi(id, judul, genre, durasi, sutradara)); }
    static void tambahFilmAnimasi(Scanner s, ArrayList<Film> films) { String id = readUniqueFilmId(s, films), judul = readText(s, "Judul: "), genre = readText(s, "Genre: "), studio = readText(s, "Studio animasi: "), teknik = readText(s, "Teknik animasi: "); if (id != null && judul != null && genre != null && studio != null && teknik != null) films.add(new FilmAnimasi(id, judul, genre, studio, teknik)); }
    static void tambahTiket(Scanner s, ArrayList<Tiket> tikets, ArrayList<Film> films) { String kode = readUniqueTicketCode(s, tikets), studio = readText(s, "Studio: "), jam = readText(s, "Jam: "); Integer harga = readPositiveInt(s, "Harga: "); if (kode == null || studio == null || jam == null || harga == null) return; printFilm(films); while (true) { Integer nomor = readPositiveInt(s, "Pilih nomor film: "); if (nomor == null) return; if (nomor <= films.size()) { tikets.add(new Tiket(kode, studio, jam, harga, films.get(nomor - 1))); return; } System.out.println("Nomor film tidak tersedia."); } }
    public static void main(String[] args) {
        ArrayList<Film> films = new ArrayList<>(Arrays.asList(new FilmBerdurasi("F01", "The Dark Knight", "Action", "152 menit", "Christopher Nolan"), new FilmBerdurasi("F02", "Parasite", "Thriller", "132 menit", "Bong Joon-ho"), new FilmBerdurasi("F03", "Interstellar", "Sci-Fi", "169 menit", "Christopher Nolan"), new FilmAnimasi("F04", "Spirited Away", "Fantasy", "Studio Ghibli", "2D Hand-drawn"), new FilmAnimasi("F05", "Inside Out 2", "Comedy", "Pixar", "3D CGI"), new FilmAnimasi("F06", "Spider-Verse", "Action", "Sony Pictures", "3D Stylized")));
        ArrayList<Tiket> tikets = new ArrayList<>(Arrays.asList(new Tiket("T001", "Studio 1", "13:00", 50000, films.get(0)), new Tiket("T002", "Studio 2", "15:30", 45000, films.get(1)), new Tiket("T003", "Studio 3", "18:00", 60000, films.get(3)), new Tiket("T004", "Studio 1", "20:00", 75000, films.get(4))));
        System.out.println("===== DATA FILM SEBELUM PENAMBAHAN ====="); printFilm(films); System.out.println("\n===== DATA TIKET SEBELUM PENAMBAHAN ====="); printTiket(tikets);
        Scanner scanner = new Scanner(System.in);
        while (true) { System.out.println("\n1. Tambah film berdurasi\n2. Tambah film animasi\n3. Tambah tiket\n4. Tampilkan semua data\n5. Selesai"); String choice = readText(scanner, "Pilihan: "); if (choice == null || choice.equals("5")) break; if (choice.equals("1")) tambahFilmBerdurasi(scanner, films); else if (choice.equals("2")) tambahFilmAnimasi(scanner, films); else if (choice.equals("3")) tambahTiket(scanner, tikets, films); else if (choice.equals("4")) { printFilm(films); printTiket(tikets); } else System.out.println("Pilihan tidak valid."); }
        System.out.println("\n===== DATA FILM SETELAH PENAMBAHAN ====="); printFilm(films); System.out.println("\n===== DATA TIKET SETELAH PENAMBAHAN ====="); printTiket(tikets);
    }
}