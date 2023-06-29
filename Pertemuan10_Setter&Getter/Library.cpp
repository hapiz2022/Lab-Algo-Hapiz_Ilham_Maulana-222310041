#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book {
private:
  string title;
  string author;
  string studentName;
  bool returned;

public:
  void setTitle(const string &bookTitle) { title = bookTitle; }
  string getTitle() const { return title; }
  void setAuthor(const string &bookAuthor) { author = bookAuthor; }
  string getAuthor() const { return author; }
  void setStudentName(const string &name) { studentName = name; }
  string getStudentName() const { return studentName; }
  void setReturned(bool isReturned) { returned = isReturned; }
  bool isReturned() const { return returned; }
};

class Library {
private:
  vector<Book *> collection;

public:
  void addBook(Book *book) { collection.push_back(book); }
  void borrowBook(Book *book, const string &studentName) {
    book->setStudentName(studentName);
    book->setReturned(false);
  }
  void returnBook(Book *book) { book->setReturned(true); }
  string getBookStatus(Book *book) const {
    string status;
    if (book->isReturned()) {
      status = "Returned by " + book->getStudentName();
    } else {
      status = "Borrowed by " + book->getStudentName();
    }
    return status;
  }
  vector<Book *> getBookList() const { return collection; }
};

int main() {
  Library library;
  Book book1;
  book1.setTitle("The Prince");
  book1.setAuthor("Niccolo Machiavelli");

  library.addBook(&book1);

  int choice;
  string studentName;

  do {
    cout << "Pilih menu yang Anda inginkan:" << endl;
    cout << "1. Input buku" << endl;
    cout << "2. Daftar buku" << endl;
    cout << "3. Peminjaman" << endl;
    cout << "4. Pengembalian" << endl;
    cout << "5. Exit" << endl;
    cout << "Pilihan Anda: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      system ("CLS");
      string title, author;
      cout << "Masukkan judul buku: ";
      cin.ignore();
      getline(cin, title);
      cout << "Masukkan penulis buku: ";
      getline(cin, author);

      Book *newBook = new Book();
      newBook->setTitle(title);
      newBook->setAuthor(author);

      library.addBook(newBook);
      cout << "Buku berhasil ditambahkan!" << endl;
      break;
    }
    case 2: {
      system ("CLS");
      vector<Book *> bookList = library.getBookList();
      cout << "Daftar buku:" << endl;
      for (const auto &book : bookList) {
        cout << "- Judul: " << book->getTitle()
                  << ", Penulis: " << book->getAuthor() << endl;
      }
      break;
    }
    case 3: {
      system ("CLS");
      cout << "Masukkan nama peminjam: ";
      cin.ignore();
      getline(cin, studentName);

      vector<Book *> bookList = library.getBookList();
      cout << "Pilih nomor buku yang ingin dipinjam: " << endl;
      for (size_t i = 0; i < bookList.size(); ++i) {
        cout << i + 1 << ". Judul: " << bookList[i]->getTitle()
                  << ", Penulis: " << bookList[i]->getAuthor() << endl;
      }

      int bookChoice;
      cin >> bookChoice;

      if (bookChoice >= 1 && bookChoice <= bookList.size()) {
        library.borrowBook(bookList[bookChoice - 1], studentName);
        cout << "Peminjaman berhasil!" << endl;
      } else {
        cout << "Pilihan buku tidak valid." << endl;
      }
      break;
    }
    case 4: {
      system ("CLS");
      vector<Book *> bookList = library.getBookList();
      cout << "Pilih nomor buku yang ingin dikembalikan: " << endl;
      for (size_t i = 0; i < bookList.size(); ++i) {
        cout << i + 1 << ". Judul: " << bookList[i]->getTitle()
                  << ", Penulis: " << bookList[i]->getAuthor() << endl;
      }

      int bookChoice;
      cin >> bookChoice;

      if (bookChoice >= 1 && bookChoice <= bookList.size()) {
        library.returnBook(bookList[bookChoice - 1]);
        cout << "Pengembalian berhasil!" << endl;
      } else {
        cout << "Pilihan buku tidak valid." << endl;
      }
      break;
    }
    case 5: {
      cout << "Terima kasih telah menggunakan layanan perpustakaan. "
                   "Program selesai."
                << endl;
      break;
    }
    default: {
      cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia."
                << endl;
      break;
    }
    }
  } while (choice != 5);

  return 0;
}