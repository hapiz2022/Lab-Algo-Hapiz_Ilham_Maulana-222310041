#include <iostream>
using namespace std;

int main() {
  int x[] = {0, 6, 12, 18, 24};
  int jumlah = sizeof(x) / sizeof(x[0]);
  int dataDicari;
  bool ditemukan = false;

  cout << "Masukan data yang dicari: ";
  cin >> dataDicari;

  for (int i = 0; i < jumlah; i++) {
    if (x[i] == dataDicari) {
      ditemukan = true;
    }
  }

  if (ditemukan) {
    cout << "Bilangan ditemukan" << endl;
  } else {
    cout << "Bilangan tidak ditemukan" << endl;
  }
  cin.ignore();
  cout << "\n\nPress any key to exit..." << endl;
  getchar();
  return 0;
}
