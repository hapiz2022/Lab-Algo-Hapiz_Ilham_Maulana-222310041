#include <iostream>
using namespace std;

int main() {
    string nama[] = {"Ayu", "Dani", "Hera"};
    int size = sizeof(nama) / sizeof(nama[0]);

    for (int i = 0; i < size; i++) {
        cout << "Nama mahasiswa: " << nama[i] << endl;
    }
	
	  cout << "\n\nPress any key to exit..." << endl;
	getchar(); 
    return 0;
}
