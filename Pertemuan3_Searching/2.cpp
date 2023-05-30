#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string books[] = {"Harry Potter and the Philosopher's Stone",
                  "To Kill a Mockingbird",
                  "The Great Gatsby",
                  "1984",
                  "Animal Farm",
                  "Pride and Prejudice"};

int binarySearch(string x, int l, int r) {
  if (r >= l) {
    int mid = l + (r - l) / 2;
    if (books[mid] == x)
      return mid;
    if (books[mid] > x)
      return binarySearch(x, l, mid - 1);
    return binarySearch(x, mid + 1, r);
  }
  return -1;
}

int main() {
  string bookTitle;
  sort(books, books + 6);

  cout << "List buku : " << endl;
  for (int i = 0; i < 6; i++) {
    cout << books[i] << endl;
  }
  cout << endl;
  cout << "Masukan judul buku yang dicari: ";
  getline(cin, bookTitle);

  int bookIndex = binarySearch(bookTitle, 0, 5);

  if (bookIndex == -1) {
    cout << "Buku yang anda cari tidak tersedia." << endl;
  } else {
    cout << "Buku yang anda cari terletak pada rak " << bookIndex + 1 << "." << endl;
  }
  cin.ignore();
  cout << "\n\nPress any key to exit..." << endl;
  getchar();
  return 0;
}
