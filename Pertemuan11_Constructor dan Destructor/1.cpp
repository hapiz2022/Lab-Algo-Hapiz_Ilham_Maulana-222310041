#include <iostream> // Header
using namespace std; // kita dapat menggunakan objek dan fungsi dari namespace std tanpa harus menuliskan std::.

class Latihan { // class name
	private: // access modifier private
		int nilai; // attribut private bernama nilai dengan tipe data int
	
	public: // access modifier public
		// constructor
		Latihan(int n) { // Ini adalah konstruktor class Latihan yang menerima satu parameter bertipe int dengan nama "n".
			nilai = n; // Mengatur nilai variabel pribadi "nilai" dengan nilai yang diterima melalui parameter konstruktor
		}
		
		// getter
		int getNum() {
			return nilai; //  Mengembalikan nilai dari variabel pribadi "nilai"
		}
};

int main() { // fungsi utama yang akan dieksekusi saat program dimulai
	Latihan lat(10); // Membuat objek bernama "lat" dari class Latihan dengan menggunakan konstruktor class yang menerima argumen 10

	cout << "Nilai yang diinputkan: " << lat.getNum() << endl; // Menampilkan teks "Nilai yang diinputkan: " diikuti dengan nilai yang dikembalikan oleh fungsi getNum() yang dipanggil pada objek "lat"
	
	return 0; //  Mengakhiri program dan mengembalikan nilai 0
}