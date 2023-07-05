#include <iostream> // standard library input output
#include <string> // optional
using namespace std; // kita dapat menggunakan objek dan fungsi dari namespace std tanpa harus menuliskan std::.


class Hewan { // parent class yang dideklarasikan dengan value Hewan
	public: // access modifier public
		virtual void bersuara() { // Dalam C++ polymorphism ditandai dengan keyword "virtual"
			cout << "...";
		}
};


class Kucing: public Hewan { // Child Class turunan dari class Hewan yang dideklarasikan dengan value Kucing
	public: // access modifier public
		void bersuara() { //  fungsi bersuara dalam clas Kucing yang mengeluarkan "Miawww" sebagai output ke konsol.
			cout << "Miawww\n";
		}
};


class Kambing: public Hewan { // Child Class turunan dari class Hewan yang dideklarasikan dengan value Kambing
	public:
		void bersuara() {   // fungsi bersuara dalam clas Kucing yang mengeluarkan "embekkk" sebagai output ke konsol.
			cout << "embekkk\n";
		}
};

class Serigala: public Hewan { // Child Class turunan dari class Hewan yang dideklarasikan dengan value Serigala
	public:
		void bersuara() {// fungsi bersuara dalam clas Kucing yang mengeluarkan "auuuu" sebagai output ke konsol.
			cout << "auuuu\n";
		}
};

int main() { // fungsi utama yang akan dieksekusi saat program dimulai.
	// kalau mau nunjuk, harus punya arah
	// pointer == petunjuk
	Hewan *h1 = new Kucing(); // pointer h1 bertipe Hewan yang menunjuk ke Class Hewan dengan objek kucing
	Hewan *h2 = new Kambing(); // pointer h2 bertipe Hewan yang menunjuk ke Class Hewan dengan objek Kambing
	Hewan *h3 = new Serigala(); // pointer h3 bertipe Hewan yang menunjuk ke Class Hewan dengan objek kucing
	
	h1->bersuara(); // Memanggil fungsi bersuara pada objek yang ditunjuk oleh pointer h1, maka implementasi fungsi bersuara pada kelas Kucing yang akan dieksekusi.
	h2->bersuara(); // Memanggil fungsi bersuara pada objek yang ditunjuk oleh pointer h2, maka implementasi fungsi bersuara pada kelas Kambing yang akan dieksekusi.
	h3->bersuara(); // Memanggil fungsi bersuara pada objek yang ditunjuk oleh pointer h3, maka implementasi fungsi bersuara pada kelas Serigala yang akan dieksekusi.
	
	return 0; //  Mengakhiri program dan mengembalikan nilai 0 kepada sistem operasi yang memanggil program. Ini menunjukkan bahwa program selesai berjalan tanpa adanya kesalahan.
}











